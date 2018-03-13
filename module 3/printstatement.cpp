#include <iostream>

using namespace std;

int main()
{
    int x;
    cout << "Please enter integers only" << endl;

    while (cin >> x)
    {
        cout << " ok" << endl;
    }
    cout << "error: Invalid input, ending program " << endl;
}
