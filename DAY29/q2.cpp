#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<char> st;
    for(char ch : s)
    {
        if(!st.empty() && st.top() == ch)
        {
            st.pop();
        }
        else
        {
            st.push(ch);
        }
    }
    if(st.empty())
    {
        cout << "EMPTY";
        return 0;
    }
    string result = "";
    while(!st.empty())
    {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    cout << result;
    return 0;
}