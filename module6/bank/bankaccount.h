#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
using namespace std;
class bankaccount
{
    private:
        string user;
        double money;
        char type;
    public:
        bankaccount(string,char);
        bankaccount();
        void transfer(double);
        char gettype();
        string getname();
        double getmoney();
};
#endif // BANKACCOUNT_H

