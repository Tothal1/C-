#include <iostream>
#include "interface.h"
using namespace std;
const string ADD = "add", MOVE = "move", REMOVE = "remove",
             FIND ="find", LIST = "list", CLEAR = "clear", EXIT = "exit";
int main()
{
    string operation, name, room;
    interface VUAdressBook;
    cout << ">";
    try
    {
        while(cin >> operation)
        {
            if(operation == ADD)
            {
                cin >> name >> room;
                addressbook* temp = new addressbook(name,room);
                VUAdressBook += temp;
                //VUAdressBook.add(temp);
            }
            else if(operation == MOVE)
            {
                cin >> name >> room;
                VUAdressBook.move(name, room);
            }
            else if(operation == FIND)
            {

                cin >> name;
                VUAdressBook.find(name);
            }
            else if(operation == LIST)
            {
                VUAdressBook.list();
            }
            else if(operation == REMOVE)
            {
                cin >> name;
                VUAdressBook -= name;
            }
            else if(operation == CLEAR)
            {
                VUAdressBook.clear();
            }
            else if(operation == EXIT)
            {
                return 0;
            }
            else
            {
                cout << "invalid operation, please input a valid operation from: \nadd\n list\n move\n remove\n find\n clear\n";
            }
            cout << ">";
        }

    }
    catch(...)
    {
        cerr << "An unexpected error appeared\n";
    }

}
