#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
int main()
{
    string S, T;
    cin >> S >> T;
    vector<int> need(128, 0);
    for(char c : T)
        need[c]++;
    int required = T.length();
    int left = 0;
    int start = 0;
    int minLen = INT_MAX;
    for(int right = 0; right < S.length(); right++)
    {
        if(need[S[right]] > 0)
            required--;
        need[S[right]]--;
        while(required == 0)
        {
            if(right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                start = left;
            }
            need[S[left]]++;
            if(need[S[left]] > 0)
                required++;
            left++;
        }
    }
    if(minLen == INT_MAX)
        cout << -1;
    else
        cout << S.substr(start, minLen);
    return 0;
}