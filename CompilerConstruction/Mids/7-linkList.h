#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct node
{
    int value;
    node *next;
};

class Linklist
{

private:
    node *header;
    node *current;

public:
    Linklist()
    {
        header = NULL;
    }

    void insert_begin(int value)
    {
        node *n = new node();
        n->value = value;
        n->next = header;

        header = n;
    }

    void insert_end(int value)
    {
        node *n = new node();

        current = header;

        while (current->next != NULL)
            current = current->next;

        current->next = n;
        n->value = value;
        n->next = NULL;
    }

    void insert_any(int value, int key)
    {
        node *n = new node();

        current = header;

        while (current->value != key || current == NULL)
            current = current->next;

        n->next = current->next;
        current->next = n;

        n->value = value;
    }

    int search(int value)
    {

        current = header;

        while (current != NULL)
        {
            if (current->value == value)
            {
                cout << " \n Roll NO found : \t";
                return value;
            }
            else
            {
                current = current->next;
            }
        }
    }

    void display()
    {

        current = header;
        while (current)
        {

            cout << "\n Name is " << current->value;

            current = current->next;
        }
    }

    void delete_begin()
    {
        header = header->next;
    }

    void delete_key(int r)
    {

        current = header;

        node *temp;

        temp = header;

        while (current->value != r)
        {
            if (current->next == NULL)
            {
                cout << "\n Could not find the rollno";
            }
            else
            {
                temp = current;
                current = current->next;
            }
        }

        if (current == header)
            header = header->next;

        else
            temp->next = current->next;
    }

    void delete_end()
    {
        current = header;

        node *temp;
        temp = header;

        while (current->next != NULL)
        {
            temp = current;
            current = current->next;
        }

        temp->next = NULL;
    }
};