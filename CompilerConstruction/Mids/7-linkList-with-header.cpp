#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "7-linkList.h"

using namespace std;

int main()
{

    Linklist valueLinkList;
    string name;
    char grade, c, ch;
    int rollno, semester, key, value;

    do
    {
        cout << "\n Press 1 to insert... 2 to delete... 3 to search ... 4 to display... 5 to exit\n";
        cin >> ch;

        if (ch == '1')
        {
            cout << "Enter value :  ";
            cin >> value;

            cout << "\nNow press 's' to insert in begin... 'm' for middle and 'e' for end\n";
            cin >> c;

            if (c == 's')
            {
                valueLinkList.insert_begin(value);
            }

            else if (c == 'e')
            {
                valueLinkList.insert_end(value);
            }

            else if (c == 'm')
            {
                cout << "Enter the key after which you want to insert";
                cin >> key;

                valueLinkList.insert_any(value, key);
            }

            else
            {
                cout << "Invalid entry try again";
            }
        }

        else if (ch == '2')
        {

            cout << "Now press 's' to delete in begin... 'm' for middle and 'e' for end";
            cin >> c;

            if (c == 's')
            {
                valueLinkList.delete_begin();
            }

            else if (c == 'e')
            {
                valueLinkList.delete_end();
            }

            else if (c == 'm')
            {
                cout << "Enter the roll no you wanted to delete";
                cin >> key;
                valueLinkList.delete_key(key);
            }

            else
            {
                cout << "Invalid entry try again";
            }
        }

        else if (ch == '3')
        {
            cout << "Enter the roll no you wanted to search";
            cin >> key;
            valueLinkList.search(key);
        }

        else if (ch == '4')
        {
            valueLinkList.display();
        }

        else if (ch == '5')
        {

            return 0;
        }

        else
        {
            cout << "Invalid entry... press again";
        }
    } while (ch != 5);

    getch();
    return 0;
}