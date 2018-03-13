#include "interface.h"
#include <iostream>
interface::interface():
firstelement(nullptr)
{

}
interface::~interface()
{
    delete firstelement;
}
addressbook* interface::getaddress()
{
    return firstelement;
}
void interface::setaddress(addressbook *newfirstelem)
{
    firstelement = newfirstelem;
}
void interface::operator+=(addressbook* newelem)
{
    if(firstelement == nullptr)
    {
        firstelement = newelem;
        return;
    }
    addressbook* aux = firstelement;
    while(aux->getnext()!=nullptr)
    {
        if(aux -> getname() == newelem->getname())
        {
            std::cout << "error: name already exists \n";
            return;
        }
        aux = aux -> getnext();
    }
    aux -> setnext(newelem);
}
void interface::add(addressbook& newelem)
{
    if(firstelement == nullptr)
    {
        firstelement = &newelem;
        return;
    }
    addressbook* aux = firstelement;
    while(aux->getnext()!=nullptr)
    {
        if(aux -> getname() == newelem.getname())
        {
            std::cout << "error: name already exists \n";
            return;
        }
        aux = aux -> getnext();
    }
    aux -> setnext(&newelem);
}
void interface::operator-=( std::string name)
{
    if(firstelement == nullptr)
    {
        std::cout << "no names in the list\n";
        return;
    }
    addressbook* aux = firstelement;
    addressbook* temp = aux->getnext();
    if(aux->getname() == name)
    {
        firstelement = aux->getnext();
        //delete aux;
        return;
    }

       while(aux->getnext()!=nullptr)
       {
           if(temp->getname() == name)
           {
               //addressbook* afterdelete = aux->getnext();
               aux->setnext(temp->getnext());
               delete temp;
               return;
           }
           aux = aux->getnext();
           temp = aux -> getnext();
       }
}
void interface::move(std::string name,std::string room)
{
    addressbook* aux = firstelement;
    while(aux != nullptr)
    {
        if(aux->getname() == name)
        {
            aux->setroom(room);
            return;
        }
        aux = aux -> getnext();
    }
    std::cout << "error: name not found\n";
}
void interface::find(std::string name)
{
    addressbook* aux = firstelement;
    while(aux != nullptr)
    {
        if(aux->getname() == name)
        {
            std::cout << name << " can be found in room " << aux -> getroom() << "\n";
            return;
        }
        aux = aux -> getnext();
    }
    std::cout << name << "not found \n";
}
void interface::list()
{
    addressbook* aux = firstelement;
    while( aux != nullptr)
    {
        std::cout << aux -> getname() << " is in room " << aux -> getroom() << std::endl;
        aux = aux -> getnext();
    }
}
void interface::clear()
{
    //delete firstelement;
    firstelement = nullptr;
}
