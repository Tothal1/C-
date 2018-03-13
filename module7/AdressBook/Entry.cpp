#include "Entry.h"
#include <iostream>
// PrepaidCard(std::string name, double balance):name(name), balance(balance){ }
Entry::Entry(string nameinput, string roominput)
{
    name = nameinput;
    room = roominput;
}
Entry::Entry()
{

}
string Entry::getname()
{
    return name;
}
string Entry::getroom()
{
    return room;
}
void Entry::setname(string nameinput)
{
    name = nameinput;
}
void Entry::setroom(string roominput)
{
    room = roominput;
}
