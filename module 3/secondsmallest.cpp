#include <iostream>
#include <string>
#include <sstream>
// easier way for the input

using namespace std;


int main()
{
    constexpr int infinity = 999999;
    string input_string;
    cout << "enter the numbers in random order: ";
    getline(cin, input_string);// read the whole line so i can end without a incorrect input.
    istringstream input_stream(input_string);// putin the numbers back in stream to read them easily.
    int iterations_number, smallest = infinity, second = infinity;
    while(input_stream >> iterations_number)
    {
        if(iterations_number <= smallest)
        {
            if (iterations_number < smallest)
                {
                    second = smallest;
                }
            smallest = iterations_number;
        }
        else
        {
            if(iterations_number < second)
            {
                second = iterations_number;
            }
        }
    }
    try
    {
        if(smallest == second)
            {
                throw 1;
            }
        if(second == infinity)
            {
                throw 1;
            }
    }
    catch(...)
    {
        cerr << "error: no second smallest" << endl;
        return 1;
    }

    cout << "the second smallest number is " << second << endl;
    return 0;
}
