#include <iostream>
#include <string>

using namespace std;


int main()
{
    int x;
    cout << "Please enter integers only" << endl;

   try
   {
       while (cin >> x)
        {
            cout << x << " ok" << endl;
        }
    throw runtime_error("input mismatch");
   }
    catch (runtime_error& e)
    {
        cout << "terminating with uncaught exception of type std::runtime error:" << e;
    }

}
