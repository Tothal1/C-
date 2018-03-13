#include "addressbook.h"
addressbook::addressbook(std::string nameinput, std::string roominput):
name(nameinput), room(roominput), next(nullptr)
{

}
addressbook::addressbook():next(nullptr)
{

}
addressbook::~addressbook()
{
    delete next;
}
std::string addressbook::getname()
{
    return name;
}
std::string addressbook::getroom()
{
    return room;
}
addressbook* addressbook::getnext()
{
    return next;
}
void addressbook::setroom(std::string newroom)
{
       room = newroom;
}
void addressbook::setnext(addressbook* newnext)
{
    next = newnext;
}
