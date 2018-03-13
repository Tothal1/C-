#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include <string>
class addressbook
{
  private:
    std::string name, room;
    addressbook *next;
  public:
    addressbook(std::string nameinput, std::string roominput);
    addressbook();
    ~addressbook();
    std::string getname();
    std::string getroom();
    //void setname(std::string name);
    void setroom(std::string newroom);
    addressbook* getnext();
    void setnext(addressbook* newnext);
};


#endif //ADDRESSBOOK_H
