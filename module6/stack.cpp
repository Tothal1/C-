#include <iostream>
#include "stack.h"
#include "Error.h"

using namespace std;

bool Stack :: isEmpty()
{
    return !elements.size();
}
int Stack::peek()
{
    if(isEmpty())
    {
        throw Error("Stack is empty");
    }
    else
    {
        cout << elements.back();
    }
}
int Stack::pop()
{
    if(isEmpty())
    {
        throw Error("Stack is empty");
    }
    else
    {
        cout << elements.back();
        elements.pop_back();
    }
}
void Stack::push(int number)
{
    elements.push_back(number);
}

int Stack::size()
{
    return elements.size();
}
