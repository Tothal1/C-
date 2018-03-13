#include <iostream>

using namespace std;
void insert_character(int counter, char character)
{
    for(int i = 0; i < counter; i++)
    {
        cout << character;
    }
}
void representation()
{
    constexpr int rows = 10;
    int spaces = 24;
    int stars = 1;
    for(int i = 0; i < rows; i++)
    {
        insert_character(spaces, ' ');
        insert_character(stars, '*');
        cout << endl;
        spaces--;
        stars+= 2;
    }
}
int main()
{
    representation();
    return 0;
}
