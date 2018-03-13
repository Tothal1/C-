#include "stack.h"
#include "Error.h"
#include <iostream>

using namespace std;

int main()
{
    Stack myStack;//schimba numele
    string input;

    do
    {
        try
        {
            cout << ">";
            cin >> input;
            if(input == "push")
            {
                int aux;
                cin >> aux;
                if(!cin)
                {
                    throw Error("invalid input! ");
                }
                myStack.push(aux);
            }
            else
            {
                if(input == "pop")
                {
                    myStack.pop();
                    cout << endl;
                }
                else
                {
                    if(input == "peek")
                    {
                        myStack.peek();
                        cout << endl;
                    }
                    else
                    {
                        throw Error("unknown operation!");
                    }
                }
            }
        }
        catch(Error& err)
        {
            cout << "Error: " << err.message << endl;
        }
    } while(input != "end");

        while(!myStack.isEmpty())
        {
            myStack.pop();
        }

    cout << endl;
    return 0;
}
