
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/mman.h>
#include <errno.h>

#include "chapter_03.h"

void ch_03(int argc, char **argv)
{
    //ch_3_4_1();
    //ch_3_4_2();
    //ch_3_4_3();
    //ch_3_6_2();
    //ch_3_6_3();
    ch_3_8(argc, argv);
    //ch_3_11();
}

void ch_3_4_1()
{
    if (write(1, "Here is some data\n", 18) != 18) 
        write(2, "a write error has occurred on file descriptor 1 \n", 50);
}

void ch_3_4_2()
{
    char buf[128];
    int nread;

    nread = read(0, buf, 128);
    if (nread == -1)
        write(2, "a read error has occurred\n", 27);

    write(1, "output: ", strlen("output: "));
    if (write(1, buf, nread) != nread)
        write(2, "a write error has occurred\n", 28);
}

/* 文件复制程序 */
void ch_3_4_3()
{
    char    c;
    int     in_fd, out_fd;
    char    buf[1024];

    in_fd = open("Makefile", O_RDONLY);
    if (in_fd == -1)
        perror("open input file");

    out_fd = open("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (out_fd == -1)
        perror("open output file");

    // while (read(in_fd, &c, 1) == 1)
    //     write(out_fd, &c, 1);

    int nread;
    while ((nread = read(in_fd, buf, 1024)) > 0)
        write(out_fd, buf, nread);
   
    printf("write finished.");
    exit(0);
}

void ch_3_6_2()
{
    char    s[256];
    int     n;
    float   f;
    char    c;

    // scanf("hello, %d,%g, %c, %[^\n]", &n, &f, &c, s);
    // printf("%d\n%g\n%c\n%s\n", n, f, c, s);

    char sss[256];
    //sprintf(sss, "%s-%d-%g-%c\n", s, n, f, c);
    sprintf(sss, "%s-%d-%g-%c\n", "ss123", 9, 3.14, 'a');
    printf("%s\n", sss);
}

void ch_3_6_3()
{
    int c;
    FILE *in, *out;

    in = fopen("Makefile", "r");
    while ((c = fgetc(in)) != EOF)
        fputc(c, stdout);
    
    printf("%d\n", feof(in));
    clearerr(in);

    printf("file id = %d\n", fileno(in));
    fclose(in);
    exit(0);
}

void PrintDir(char *dir, int depth)
{
    DIR             *dp;
    struct dirent   *entry;
    struct stat     stat_buf;

    // 打开目录
    if ((dp = opendir(dir)) == NULL)
    {
        fprintf(stderr, "cannot open direntry: %s\n", dir);
        return ;
    }

    chdir(dir);
    while ((entry = readdir(dp)) != NULL)
    {
        lstat(entry->d_name, &stat_buf);
        if (S_ISDIR(stat_buf.st_mode))
        {
            if (strcmp(".", entry->d_name) == 0 ||
                strcmp("..", entry->d_name) == 0)
                    continue;
            
            printf("%*s%s/\n", depth, "", entry->d_name);
            PrintDir(entry->d_name, depth + 4);
        }
        else
            printf("%*s%s\n", depth, "", entry->d_name);
    }
}

void ch_3_8(int argc, char **argv)
{
    char *top_dir = ".";
    if (argc >= 2)
        top_dir = argv[1];

    printf("Dir scan of %s\n", top_dir);
    PrintDir(top_dir, 0);
    printf(".done\n");

    exit(0);
}

typedef struct 
{
    int     integer;
    char    str[24];
} RECORD;

#define NRECORDS    (10)

void PrintFile(const char *s)
{
    RECORD record;

    FILE *fp = fopen(s, "r+");
    if (fp == NULL) 
    {
        fprintf(stderr, "open file failed.\n");
        return ;
    }

    for (int i = 0; i < NRECORDS; ++i) 
    {
        fread(&record, sizeof (RECORD), 1, fp);
        printf("%d ---> %s\n", record.integer, record.str);
    }
    printf("\n\n");
    fclose(fp);
}

void ch_3_11()
{
    RECORD  record, *mapped;
    FILE    *fp;
    int     f;

    fp = fopen("record.dat", "w+");
    if (fp == NULL) 
    {
        fprintf(stderr, "can not open record file!");
        return ;
    }

    //写文件
    for (int i = 0; i < NRECORDS; ++i) 
    {
        record.integer = i;
        sprintf(record.str, "RECORE-%d", i);
        fwrite(&record, sizeof (RECORD), 1, fp);
    }
    fclose(fp);
    PrintFile("record.dat");

    //修改文件
    fp = fopen("record.dat", "r+");
    if (fp == NULL) {
        fprintf(stderr, "can not open record file!");
        return ;
    }

    fseek(fp, 3 * sizeof (RECORD), SEEK_SET);
    //fread(&record, sizeof (RECORD), 1, fp);
    record.integer = 10000;
    sprintf(record.str, "RECORE-%d", record.integer);
    fwrite(&record, sizeof (RECORD), 1, fp);
    fclose(fp);
    PrintFile("record.dat");

    //映射
    f = open("record.dat", O_RDWR);
    if (f == -1) {
        printf("open file failed, errno: %d\n", errno);
        return ;
    }

    mapped = (RECORD *)mmap(0, NRECORDS * sizeof (RECORD), 
            PROT_READ | PROT_WRITE, MAP_SHARED, f, 0);
    mapped[3].integer = 111;
    sprintf(mapped[3].str, "RECORD-%d", mapped[3].integer);
    msync((void *)mapped, NRECORDS * sizeof(RECORD), MS_ASYNC);
    munmap((void *)mapped, NRECORDS * sizeof(RECORD));
    close(f);
    PrintFile("record.dat");

    exit(0);

}
