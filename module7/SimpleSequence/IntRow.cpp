#include <iostream>
#include <IntRow.h>
IntRow::IntRow()
{
    size = 0;
    elements = NULL;
}
IntRow::~IntRow()
{
    if(elements != 0)
    {
        delete[]elements;
    }
}
/*void IntRow::increase_capacity(int sz) {
    if (sz <= size) return;

    int* new_vec = new double[sz];   // allocate a new array on the free store

    for(int i = 0; i < size; i++) { // copy old vector into new one
      new_vec[i] = elements[i];
    }
    size = sz;                      // set the new capacity

    delete[] elements;                       // delete the old vector
    elements = new_vec;
  }
*/
void IntRow::push_back(int value)
{
    int* new_vec = new int[size + 1];   // allocate a new array on the free store
    if(size != 0)
    {
        for(int i = 0; i < size; i++)
        {                   // copy old vector into new one
            new_vec[i] = elements[i];
        }
    }
    if(elements != NULL)
    {
        delete[] elements;                       // delete the old vector
    }
    elements = new_vec;
    elements[size] = value;
    size++;                     // set the new capacity
}
int IntRow::length()
{
    return size;
}
int IntRow::at(int index)
{
    return elements[index];
}
