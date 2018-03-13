// what about small case letters? transform into uppercase
// should i check for invalid input with numbers? why not
// what happens if different characters is bigger than 27?
// how does the player know that the character are uppercase
// what happens with lowercase characters introduced by the player?
#include <time.h>
#include <stdlib.h>

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

char get_letter(int different_characters)
{
    return (rand() % different_characters) + 'A';
}
string random_string_creator(int different_characters,int pattern_length)
{
    string pattern;
    for(int i = 0; i < pattern_length; i++)
    {
        pattern.push_back(get_letter(different_characters));
    }
    return pattern;

}
int check(string guess, string pattern)
{
    int similarities = 0;
    for(int i = 0; i < pattern.length(); i++)
    {
        if(pattern[i] == guess[i])
        {
            similarities++;
        }
    }
    return similarities;
}
int main()
{
    int different_characters, pattern_length, similarities;
    int number_of_guesses = 0;
    srand(time(NULL));
    string guess;
    try
    {
        cout << "enter the amount of different characters: ";
        cin >> different_characters;
        if(!cin)
        {
            throw Error("Invalid input");
        }
        cout << "Enter the pattern length: ";
        cin >> pattern_length;
        if(!cin)
        {
            throw Error("Invalid input");
        }
        cout << endl;


        string pattern = random_string_creator(different_characters, pattern_length);
        do
        {
            cout << "Enter your guess: ";
            cin >> guess;
            similarities = check(guess, pattern);
            number_of_guesses++;
            cout << "You guessed "<< similarities
                 << " characters correctly" << endl;
        }while(similarities < pattern_length);
        cout << endl << "you guessed the pattern in "
             << number_of_guesses << " guesses" << endl;
        return 0;
    }
    catch(Error& msg)
    {
        cerr << "error: "<< msg.message << endl;
    }
}
