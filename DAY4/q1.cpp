#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cout << "Enter the string : ";
    getline(cin, str);
    int vowels = 0;
    int consonants = 0;
    int words = 0;
    bool inWord = false;
    for(int i = 0; i < str.length(); i++)
    {
        char ch = tolower(str[i]);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            vowels++;
        }
        else if(ch >= 'a' && ch <= 'z')
        {
            consonants++;
        }
        if(str[i] != ' ' && inWord == false)
        {
            words++;
            inWord = true;
        }
        else if(str[i] == ' ')
        {
            inWord = false;
        }
    }
    cout << "Total Vowels: " << vowels << endl;
    cout << "Total Consonants: " << consonants << endl;
    cout << "Total Words: " << words << endl;
    return 0;
}