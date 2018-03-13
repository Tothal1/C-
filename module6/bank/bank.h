#ifndef BANK_H
#define BANK_H
#include <string>
#include <vector>
#include "bankaccount.h"
using namespace std;
class bank
{
    private:
        vector<bankaccount> accounts;
    public:
        int findname(string);
        void create(const int,string,char);
        void transfer(const int,string,double);
        void removal(const int,string);
        void getinfo();
};
#endif // BANK_G
