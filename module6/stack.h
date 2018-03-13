#ifndef STACK_H
#define STACK_H
#include <vector>

class Stack {
    private:
        std::vector<int> elements;
    public:
        bool isEmpty();
        int peek();
        int pop();
        void push(int);
        int size();
};

#endif
