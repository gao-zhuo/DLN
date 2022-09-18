
#include <iostream>
#include <vector>
#include <algorithm>

#include "chapter_04.h"
#include "../util/triangular.h"
#include "../util/triangular_iterator.h"
#include "../util/num_seq1.h"

using namespace std;

void ch_4()
{
    //ch_4_1();
    //ch_4_3();
    //ch_4_5();
    //ch_4_7();
    ch_4_9();
    //ch_4_10();
}

void FillStack(Stack &stack, std::istream &is)
{
    string str;
    if (is >> str && !stack.Empty())
        stack.Push(str);
    cout << "read in " << stack.Size() << " elements\n";
}

void ch_4_1()
{
    Stack sta;
    cout << sta.Empty() << endl;
    FillStack(sta, cin);
}

void ch_4_3()
{
    Triangular tri(4);
    cout << tri << " -- sum of elements: "
      << Sum(tri) << endl;

    Triangular tri2(4, 3);
    cout << tri2 << " -- sum of elements: "
      << Sum(tri2) << endl;

    Triangular tri3(8, 8);
    cout << tri3 << " -- sum of elements: "
      << Sum(tri3) << endl;
}

void ch_4_5()
{
    char ch;
    bool more = true;

    while (more)
    {
        cout << "Enter a value: ";
        int ival;
        cin >> ival;

        bool is_elem = Triangular::IsElem(ival);
        cout << ival << (is_elem ? " is " : " is not ")
             << "an element in the Triangular series.\n"
             << "Anther value(y/n)?";

        cin >> ch;
        if (ch == 'n' || ch == 'N')
            more = false;
    }
}

void ch_4_7()
{
    Triangular tri(20,3);
    //cout << tri << endl;
    cout << "Triangular Sequence of: " << tri.Length() << " elements\n";

    Triangular::Iterator beg = tri.Begin();
    Triangular::Iterator end = tri.End();

    while (beg != end)
    {
        cout << *beg << '\n';
        ++beg;
    }
    cout << endl;
}

int CountLessThan(const vector<int> &vec, int comp)
{
    LessThan lt(comp);
    int count = 0;

    for (int ix = 0; ix < vec.size(); ++ix)
        if (lt(vec[ix]))
            ++count;

    return count;
}

int SumLessThan(const std::vector<int> &vec, int comp)
{
    LessThan lt(comp);
    
    int sum = 0;
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (lt(vec[i]))
        {
            //cout << "val: " << vec[i] << endl;
            sum += vec[i];
        }
    }
    
    return sum;
}

void PrintLessThan(const vector<int> &vec, int comp, ostream &os)
{
    LessThan lt(comp);

    auto it = vec.begin(), it_end = vec.end();
    while ((it = find_if(it, it_end, lt)) != it_end)
    {
        os << *it << ' ';
        ++it;
    }
}

void ch_4_9()
{
    int ia[16] = { 17, 12, 44, 9, 18, 45, 6, 14,
                   23, 67, 9, 0, 27, 55, 8, 16 };

    vector<int> vec( ia, ia+16 );
    int comp_val = 20;

    cout << "vector size: " << vec.size() << endl;
    cout << "vector less than comp val size: " << CountLessThan(vec, comp_val) << endl;
    cout << "vector sum is: " << SumLessThan(vec, comp_val) << endl;

    PrintLessThan(vec, comp_val, cout);
    cout << endl;
}

void ch_4_10()
{
    Triangular tri(6, 3);
    cout << tri << endl;

    Triangular tri2;
    cin >> tri2;
    cout << tri2 << endl;
}

void Chapter_04()
{
    //Practice_4_3();
    //Practice_4_5();
    //Practice_4_7();
    //Practice_4_9();
    //Practice_4_10();
    //Practice_4_11();
}

void Example(const ValClass *pvc, ValClass &rvc)
{
    pvc->Val();
    rvc.Val();
}

void Practice_4_3()
{
    const ValClass  v1;
    ValClass        v2;
    Example(&v1, v2);
}

void Practice_4_5()
{
    char    ch;
    bool    more = true;

    while (more)
    {
        cout << "Please enter a num value: ";
        int val;
        cin >> val;

        bool is_elem = Triangular::IsElem(val);
        cout << val << (is_elem ? " is" : " is not")
             << " an element int the Triangular series.\n"
             << "Anther value?(Y/N)? ";

        //Triangular::Display(1, 10, cout);
        cin >> ch;
        if (ch == 'n' || ch == 'N')
            more = false;
    }
}

void Practice_4_7()
{
    Triangular  tri(20, 12);
    Triangular::Iterator beg = tri.Begin();
    Triangular::Iterator end = tri.End();

    cout << "Triangular Sequence of: " << tri.Length() << " elements\n";
    cout << endl;

    while (beg != end)
    {
        cout << *beg << ' ';
        ++beg;
    }
    cout << tri;
    cout << endl;
}



void Practice_4_9()
{
    int ia[16] = { 17, 12, 44, 9, 18, 45, 6, 14,
                   23, 67, 9, 0, 27, 55, 8, 16 };

    vector<int> vec( ia, ia+16 );
    int comp_val = 20;

    cout << CountLessThan(vec, comp_val);
    cout << endl;
    PrintLessThan(vec, comp_val, cout);
    cout << endl;
}

void Practice_4_10()
{
    Triangular tri(6, 3);
    cout << tri << endl;
}

void Display(ostream &os, const NumSeqVer1 &ns,
             int pos, int elem_val)
{
    os << "The element at position: " << pos
        << " for the: " << ns.WhatAmI()
        << " sequence is: " << elem_val 
        << endl;
}

void Practice_4_11()
{
    NumSeqVer1 ns;
    //cout << ns << endl;

    const int pos = 8;
    for (int ix = 1; ix < NumSeqVer1::NumOfSequence() ; ++ix)
    {
        ns.SetSequence(NumSeqVer1::SeqType(ix));
        int val = ns.Elem(pos);
        //Display(cout, ns, pos, val);

        if (ns.IsElem(val))
            cout << "ok!\n";
    }

    // NumSeqVer1 ns1(1, 8, NumSeqVer1::NS_TRI);
    // cout << ns1 << endl;
}
