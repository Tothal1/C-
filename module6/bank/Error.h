#ifndef ERROR_H
#define ERROR_H
#include <string>
#include <iostream>
using namespace std;
class Error
{
    private:
        string message;
        int line;
    public:
        int getline();
        string getmessage();
        Error(string);
        Error(int,string);
};

#endif
