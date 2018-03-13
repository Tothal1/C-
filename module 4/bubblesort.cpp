#include <iostream>
#include <vector>
#include <string>
#include <exception>

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

void sorting(vector<int>& elements)
{
        for(int i = 0; i < elements.size(); i++)
        {
            for(int j = 0; j < elements.size() - 1; j++)
            {
                if(elements[j] > elements[j + 1])
                {
                    swap(elements[j], elements[j+1]);
                }
            }
        }
}

int main()
{
    int number_of_elements, aux;
    vector<int> elements;
    try {
        cout << "please enter the number of elements: ";
        cin >> number_of_elements;

        if (!cin)
        {
            throw Error("invalid input");
        }

        cout << "Enter the list to be sorted: ";
        for(int i = 0; i < number_of_elements; i++)
        {
            cin >> aux;
            if (!cin)
            {
                throw Error("invalid input");
            }
            elements.push_back(aux);
        }

        sorting(elements);

        cout << "the sorted list is: ";
        for(int i = 0; i < elements.size(); i++)
        {
            cout << elements[i]<< " ";
        }
        cout << endl;
        return 0;
    }
    catch(Error& message)
    {
        cerr << "error: " << message.message;
        return 1;
    }
}
