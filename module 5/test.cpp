// to_string example
#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string

using namespace std;
int x = 42;
void f(int x)
{
    cout << ::x << endl;
    cout << x << endl;
}
int main ()
{
f(10);

}
