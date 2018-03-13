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

bool check_small_letter(char letter)
{
    return !(letter >= 'a' && letter <='z');
}

int main()
{
    string uncompressed_data, compressed_data;
    int i = 0,j = 0, sameletters = 1;
    cout << "enter the data to be compressed: ";
    getline(cin, uncompressed_data);
    try
    {
        while(i < uncompressed_data.length())
        {
            if(check_small_letter(uncompressed_data[i]))
            {
                throw Error("invalid input");
            }
            j = i + 1;
            while(uncompressed_data[i] == uncompressed_data[j])
            {
                sameletters++;
                j++;
            }
            compressed_data += to_string(sameletters);
            compressed_data.push_back(uncompressed_data[i]);
            i = j;
            sameletters = 1;
        }
        cout <<"the compressed data is: " << compressed_data << endl;
    }
    catch (Error& message)
    {
        cerr << "error: " << message.message << endl;
    }
}
