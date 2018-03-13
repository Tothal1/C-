#ifndef ADRESSBOOK_H
#define ADRESSBOOK_H
#include "Entry.h"
using namespace std;

class AdressBook
{
    private:
        Entry* elements;
        int size;
        void sort();
        void del(int);
    public:
        AdressBook();
        ~AdressBook();
        void add(string, string);
        void list();
        void move(string,string);
        void remove(string);
        void find(string);
        void clear();


};
#endif
