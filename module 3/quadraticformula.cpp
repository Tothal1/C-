#include <iostream>
#include <cmath>

using namespace std;

double a, b, c, sol1, sol2, delta;

int main()
{
    cout << "enter the values for a, b and c: ";
    cin >> a >> b >> c;
    try
    {
        if(a == 0)
            throw a;
    }
        catch (...)
    {
        cerr << "error: division by 0" << endl;
        return 1;
    }
    delta = b*b - 4 * a * c;
    if (delta > 0 )
    {
        sol1 = (-b + sqrt(delta))/2;
        sol2 = (-b - sqrt(delta))/2;

        cout << "the first solution is: " << sol1 << endl;
        cout << "the second solution is: " << sol2 << endl;
    }
    else
    {
        if (delta == 0)
        {
            sol1 = -b/2;
            cout << "the only solution is: " << sol1 << endl;
        }
        else
        {
            cout << "there is no solution. " << endl;
        }
    }


    return 0;
}

