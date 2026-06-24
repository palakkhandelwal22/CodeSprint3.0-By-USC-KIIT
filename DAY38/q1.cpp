#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> result;
void backtrack(int index, string &digits, string &current,
               vector<string> &mapping) 
               {
    if (index == digits.size()) 
    {
        result.push_back(current);
        return;
    }
    string letters = mapping[digits[index] - '0'];
    for (char ch : letters) 
    {
        current.push_back(ch);
        backtrack(index + 1, digits, current, mapping);
        current.pop_back();
    }
}
int main() 
{
    string digits;
    cin >> digits;
    vector<string> mapping = 
    {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    string current = "";
    backtrack(0, digits, current, mapping);
    for (int i = 0; i < result.size(); i++) 
    {
        if (i) cout << " ";
        cout << result[i];
    }
    return 0;
}