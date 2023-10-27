
#include <stdio.h>

#include "more.h"
#include "who.h"
#include "cp.h"
#include "ls.h"
#include "pwd.h"
#include "echo.h"
#include "mapping.h"
#include "play_again.h"



int main(int argc, char **argv)
{
    printf("==================Hello World!==================\n");

    // chapter 01
    more(argc, argv);

    // chapter 02
    who1();
    //cp(argc, argv);
    who2();

    // chapter 03
    ls(argc, argv);

    // chapter 04
    pwd();

    // chapter 05
    set_echo(argc, argv);
    echo_state(0);

    // chapter 06
    mapping();
    //get_response();


    printf("===Quietly try and amaze everyone's sentences===\n");
}
