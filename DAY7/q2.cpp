#include <iostream>
using namespace std;
int main()
{
    string s;
    cout << "Enter the string:";
    cin >> s;
    int count = 1;
    for(int i = 0; i < s.length(); i++)
    {
        while(i < s.length() - 1 && s[i] == s[i + 1])
        {
            count++;
            i++;
        }
        cout << s[i] << count;
        count = 1;
    }
    return 0;
}