#include <iostream>
#include <fstream>
#include "Error.h"
#include "bankaccount.h"
#include "bank.h"
#include <vector>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int main()
{
    char type;
    bank mybank;
    string name;
    double money;
    char type_of_account;
    int line = 1;
    while(fin >> type)
    {
        try
        {
            switch (type)
                {
                    case 'c':
                        fin >> name >> type_of_account;
                        mybank.create(line,name,type_of_account);
                        break;
                    case 't':
                        fin >> name >> money;
                        mybank.transfer(line,name,money);
                        break;
                    case 'r':
                        fin >> name;
                        mybank.removal(line,name);
                        break;
                    default:
                        throw Error(line,"invalid type of operation");
                }
            line++;
        }
        catch(Error& msg)
        {
            cerr << "error on line " << msg.getline() << ": "
                 << msg.getmessage() << endl;
            line++;
            continue;
        }
    }
    cout << endl<<endl;
    mybank.getinfo();
}
