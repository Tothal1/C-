#include <iostream>
#include <string>

using namespace std;

class Error
{
    public:
        string message;
        Error(string err)
        {
            message = err;
        }
};
void check_input(int entry)
{
    if(!cin)
    {
        throw Error("invalid input! \n");
    }
    if(entry < 0)
    {
        throw Error("numbers should be positive! \n")
    }
}
int factorial(int number)
{
    if(number == 0)
    {
        return 1;
    }
    else
    {
        return number * factorial(number-1);
    }

}
int permutation(int entry1, int entry2)
{
    return factorial(entry1) / factorial(entry1 - entry2);
}
int combination(int entry1, int entry2)
{
    return permutation(entry1, entry2)/factorial(entry2);
}

int main()
{
    int entry1, entry2;
    char operation;
    try
    {

        cout << "enter two integers: ";
        cin >> entry1;
        check_input(entry1);
        cin >> entry2;
        check_input(entry1);

        cout << "please enter \'p\' for permutation or \'c\' for combination: ";
        cin >> operation;
        switch(operation)
        {
            case 'c':
                cout <<" the combination of "<< entry1 << " and "
                     << entry2 << " is " << combination(entry1, entry2) << endl;
                break;
            case 'p':
                cout << " the permutation of " << entry1 << " and "
                     << entry2 << " is " << permutation(entry1, entry2) << endl;
                break;
            default:
                throw Error("operation not recognised! \n");
        }
    }
    catch(Error& msg)
    {
        cerr << "Error: " << msg.message;
    }
}
