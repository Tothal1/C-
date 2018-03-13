#ifndef INTROW_H
#define INTROW_H
using namespace std;

class IntRow {
    private:
        int *elements;
        int size;
       // void increase_capacity(int);
    public:
        IntRow(); // constructor
        ~IntRow(); // destructor
        int at(int index); // returns the element at position index
        void push_back(int value); // adds value to this IntRow
        int length(); // returns the amount of elements in this IntRow
};
#endif
