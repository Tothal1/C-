#ifndef ENTRY_H
#define ENTRY_H
#include <string>
using namespace std;
class Entry
{
    private:
        string name, room;
    public:
        Entry();
        Entry(string, string);
        string getname();
        string getroom();
        void setname(string);
        void setroom(string);
};
#endif // ENTRY_H
