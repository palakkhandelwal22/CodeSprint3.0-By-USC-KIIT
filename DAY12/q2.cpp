#include <iostream>
using namespace std;
int main()
{
    string s;
    cout << "Enter the string : ";
    cin >> s;
    int start = 0;
    int maxLength = 1;
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        int left = i;
        int right = i;
        while(left >= 0 && right < n && s[left] == s[right])
        {
            int len = right - left + 1;
            if(len > maxLength)
            {
                maxLength = len;
                start = left;
            }
            left--;
            right++;
        }
        left = i;
        right = i + 1;
        while(left >= 0 && right < n && s[left] == s[right])
        {
            int len = right - left + 1;
            if(len > maxLength)
            {
                maxLength = len;
                start = left;
            }
            left--;
            right++;
        }
    }
    for(int i = start; i < start + maxLength; i++)
    {
        cout << s[i];
    }
    return 0;
}