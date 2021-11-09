#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    char b1[4096];
    char b2[4096];
    char word[4096];

    ifstream obj;        // used to read from the file        Similarly
                         // ofstream() --> used to write to the file
    obj.open("qwe.txt"); // used to open the file

    char *curr_buff = b1;
    obj.get(curr_buff, 4096, EOF); // get() --> reads a single character form the associated stream

    int count = 0;
    int c = 0;
    int i = 0;
    int j = 0;

    while (curr_buff[count] != EOF)
    {

        word[c] = curr_buff[count];
        c++;

        if (isspace(curr_buff[count]))
        {
            cout << "\n";
            word[c] = '\0';

            c = 0;
            while (word[c] != '\0')
            {
                cout << word[c];
                c++;
            }
            c = 0;
        }
        count++;
        if (count > 4095)
        {
            if (curr_buff == b1)
            {
                curr_buff = b2;
            }
            else
            {
                curr_buff = b1;
            }
            obj.get(curr_buff, 4096, EOF);
            count = 0;
        }
    }

    getch();
    return 0;
}