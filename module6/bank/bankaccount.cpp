#include "bankaccount.h"
#include <iostream>

bankaccount::bankaccount( string userinfo, char typeinfo)
{
    user = userinfo;
    type = typeinfo;
    money = 0;
}
bankaccount::bankaccount()
{

}
void bankaccount::transfer(double moneyinfo)
{
    money += moneyinfo;
}
double bankaccount::getmoney()
{
    return money;
}
char bankaccount::gettype()
{
    return type;
}
string bankaccount::getname()
{
    return user;
}
