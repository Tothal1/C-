#include "Error.h"

Error::Error(string err)
{
    message = err;
}
Error::Error(int lineinput, string err)
{
    message = err;
    line = lineinput;
}
int Error::getline()
{
    return line;
}
string Error::getmessage()
{
    return message;
}
