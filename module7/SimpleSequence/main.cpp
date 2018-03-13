#include <iostream>
#include "IntRow.h"
using namespace std;
int element(int index)
{
    return index * 2 - 3;
}
int main()
{
    int number_of_iterations, term;
    IntRow sequence;
    cout << "Please enter the number of iterations: ";
    cin >> number_of_iterations;

    cout << "which term would you like to know: ";
    cin >> term;

    for(int i = 1; i <= number_of_iterations; i++)
    {
        sequence.push_back(element(i));
    }

    cout << " the value of term "<< term << " is "<< sequence.at(term - 1) << endl;

    cout << "The entire sequence up to " << number_of_iterations << " terms is: ";
    for(int i = 0; i < sequence.length(); i++)
    {
        cout << sequence.at(i) << " ";
    }
    cout << endl;

    return 0;
}
