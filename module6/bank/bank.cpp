#include "bank.h"
#include "Error.h"
void bank::getinfo()
{
    vector<bankaccount>::iterator it;
    for (it=accounts.begin(); it!=accounts.end(); it++)
    {
        if(it -> getmoney() < 0)
        {
            cout << it -> getname() << " owes " << abs(it -> getmoney()) << " euros" << endl;
        }
        else
        {
            cout << it -> getname() << " owns " << abs(it -> getmoney()) << " euros" << endl;
        }
    }
}
int bank::findname(string name)
{
    for(unsigned int i = 0; i < accounts.size();i++)
    {
        if(accounts[i].getname() == name)
        {
            return i;
        }
    }
    return -1;
}
void bank::create(const int line,string name, char type)
{
    if(!(type == 'y' || type =='n'))
    {
        throw Error(line,"invalid Card type(only y/n allowed)");
    }
    bankaccount aux(name,type);
    int placeOfAccount = findname(name);
    if(placeOfAccount == -1)
    {
        accounts.push_back(aux);
    }
    else
    {
        throw Error(line,"account already exists");
    }

}
void bank::transfer(const int line,string name, double money)
{
    int placeOfAccount = findname(name);
    if(placeOfAccount != -1)
    {
        if(accounts[placeOfAccount].getmoney() < abs(money) && money < 0 && accounts[placeOfAccount].gettype() == 'n')
        {
           throw Error(line, "account cannot hold negative balance");
        }
        else
        {
            accounts[placeOfAccount].transfer(money);
        }
    }
    else
    {
        throw Error(line, "account doesn't exist");
    }
}
void bank::removal(const int line,string name)
{
    int placeOfAccount = findname(name);
    if(placeOfAccount != -1)
    {
        if(accounts[placeOfAccount].getmoney()<0)
        {
            throw Error(line, "account holds negative balance and cannot be removed.");
        }
        else
        {
            accounts.erase(accounts.begin()+placeOfAccount);
        }
    }
    else
    {
        throw Error(line, "account doesn't exist");
    }

}
