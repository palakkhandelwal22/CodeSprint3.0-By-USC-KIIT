#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string s;
    cout << "Enter the string : ";
    getline(cin, s);
    vector<string> words;
    string word = "";
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != ' ')
        {
            word += s[i];
        }
        else
        {
            if(word != "")
            {
                words.push_back(word);
                word = "";
            }
        }
    }
    if(word != "")
    {
        words.push_back(word);
    }
    for(int i = words.size() - 1; i >= 0; i--)
    {
        cout << words[i];
        if(i != 0)
        {
            cout << " ";
        }
    }
    return 0;
}