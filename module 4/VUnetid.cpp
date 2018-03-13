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
bool check_letter(char letter)
{
    return !(letter >='a' && letter<= 'z' || letter >='A' && letter <='Z');
}
bool check_number(char number)
{
    return !(number >='0' && number<= '9');
}
int main()
{
    string vu_id;
    cout << "Please enter the Vunet ID: ";
    getline(cin, vu_id);

    try
    {
        if(vu_id.length() != 6)
        {
            throw Error("The VU_id is not the right length!");
        }
        for(int i = 0; i < 3; i++)
        {
            if(check_letter(vu_id[i]))
            {
                throw Error("letter expected");
            }

        }
        for(int i = 3; i < vu_id.length(); i++)
        {
            if(check_number(vu_id[i]))
            {
                throw Error("number expected");
            }

        }
        cout << "The VUnet id " << vu_id << " is correct." << endl;
        return 0;
    }
    catch(Error& err)
    {
        cerr << "error: " << err.message;
        return 1;
    }
}
