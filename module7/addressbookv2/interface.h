#include "addressbook.h"
class interface
{
private:
    addressbook* firstelement;
public:
    void operator+=(addressbook*);
    void operator-=(std::string name);
    ~interface();
    interface();
    addressbook* getaddress();
    void setaddress(addressbook*);
    void move(std::string name, std::string room);
    void find(std::string name);
    void clear();
    void list();
    void add(addressbook&);
};
