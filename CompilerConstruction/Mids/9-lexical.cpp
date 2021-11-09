#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <iostream>
using namespace std;

enum COL_NAME
{
    L = 0,
    _,
    D,
    OTHER,
    FSLASH,
    ANY,
    NLINE,
    A,
    R,
    T
};

enum TOKENS
{
    ID = 0,
    COMMENT,
    IDENTIFIER
};

COL_NAME getCharType(char ch)
{
    if (isalpha(ch))
        return L;

    else if (isdigit(ch))
        return D;

    else if (ch == '_')
        return _;
    else if (ch == '/')
        return FSLASH;

    else if (ch == '\n')
        return NLINE;
    else if (ch != isalpha(ch) && ch != isdigit(ch) && ch != '_')
        return OTHER;
    else
        return ANY;
}

int main()
{

    char b1[4096];
    char b2[4096];
    char word[4096];

    int TT[6][10] = {
        {1, 1, -1, -1, 3, -1, 0, 0, 0, 0},
        {1, 1, 1, 2, 2, 2, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, IDENTIFIER},
        {-1, -1, -1, -1, 4, -1, -1, 0, 0, 0},
        {-1, -1, -1, -1, -1, 4, 5, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, COMMENT}};

    ifstream obj;
    obj.open("9-testing.txt");

    char *curr_buff = b1;
    obj.get(curr_buff, 4096, EOF);

    int count = 0, c = 0;

    int state = 0;
    char lex[100];
    int i = 0, j = 0;

    while (curr_buff[count] != EOF)
    {

        if (!TT[state][A])
        {

            state = TT[state][getCharType(curr_buff[count])];
            if (state == -1)
            {
                j = 0;
                state = 0;
                count++;
            }
            else
            {
                lex[j] = curr_buff[count];
                count++;
                j++;
            }
        }
        else
        {
            lex[j] = '\0';
            cout << lex;
            cout << "\n";

            if (TT[state][R])
            {
                j = 0;
                state = 0;
            }
        }

        if (count > 4095)
        {
            if (curr_buff == b1)
            {
                curr_buff = b2;
            }
            else
                curr_buff = b1;

            obj.get(curr_buff, 4096, EOF);
            count = 0;
        }
    }

    getch();
    return 0;
}
