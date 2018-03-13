#include "AdressBook.h"
#include <iostream>
AdressBook::AdressBook()
{
    elements = NULL;
    size = 0;
}
AdressBook::~AdressBook()
{
    delete[]elements;
}
void AdressBook::add(string name, string room)
{
    for(int i = 0; i < size; i++)
    {
        if(elements[i].getname() == name)
        {
            cout << "Name already in the Adress Book" << endl;
            return;
        }
    }
    Entry* new_vec = new Entry[size + 1];   // allocate a new array on the free store
    if(size != 0)
    {
        for(int i = 0; i < size; i++)
        {                   // copy old vector into new one
            new_vec[i] = elements[i];
        }
    }
    delete[] elements;                       // delete the old vector
    elements = new_vec;
    Entry aux(name,room);
    elements[size] = aux;
    size++;
}
void AdressBook::move(string name, string room)
{
    if(size)
    {
        for(int i = 0; i < size; i++)
        {
            if(elements[i].getname()==name)
            {
                elements[i].setroom(room);
                return;
            }
        }
        cout << "error: Name not found" << endl;
    }
    else
    {
        cout << " error: No names in the Adress Book" << endl;
    }
}
void AdressBook::del(int index)
{
    if(size == 1 || size == 0)
    {
        delete[] elements;
        elements = nullptr;
        size = 0;
    }
    else
    {
        int j = 0;
        Entry* new_vec = new Entry[size - 1];   // allocate a new array on the free store
        for(int i = 0; i < size; i++)
        {                   // copy old vector into new one
            if(i != index)
                {
                    new_vec[j] = elements[i];
                    j++;
                }
        }
        delete[] elements;                       // delete the old vector
        elements = new_vec;
        size--;
    }
}
void AdressBook::remove(string name)
{
    for(int i = 0; i < size; i++)
    {
        if(elements[i].getname() == name)
        {
            del(i);
            return;
        }
    }
    cout << "error: Name not found" << endl;
}
void AdressBook::find(string name)
{
    for(int i = 0; i < size; i++)
    {
        if(elements[i].getname() == name)
        {
            cout << name << " is in room " << elements[i].getroom() << endl;
            return;
        }
    }
    cout << "error: " << name << " not found" << endl;
}
void AdressBook::clear()
{
    delete[] elements;
    size = 0;
    elements = NULL;
}
void AdressBook::sort()
{
    if( size > 1)
    {
        for(int i = 1; i < size; i++)
        {
            for(int j = 0; j < size-i; j++)
            {
                if(elements[j].getroom() > elements[j+1].getroom())
                {
                    swap(elements[j],elements[j+1]);
                }
                else if(elements[j].getroom() == elements[j+1].getroom()
                        && elements[j].getname() > elements[j+1].getname())
                {
                    swap(elements[j],elements[j+1]);
                }
            }
        }
    }
}
void AdressBook::list()
{
    // print the list sorted by room
    if(size != 0)
    {
        sort();
        for(int i = 0; i < size;i++)
        {
            cout << elements[i].getname() << " is in " << elements[i].getroom() << endl;
        }
    }
    else
    {
        cout << "The Adress book is empty" << endl;
    }
}
