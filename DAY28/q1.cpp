#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<char> st;
    for(char ch : s)
    {
        if(ch == '(' || ch == '[' || ch == '{' || ch == '<')
        {
            st.push(ch);
        }
        else
        {
            if(st.empty())
            {
                cout << "INVALID";
                return 0;
            }
            char top = st.top();
            st.pop();
            if((ch == ')' && top != '(') ||
               (ch == ']' && top != '[') ||
               (ch == '}' && top != '{') ||
               (ch == '>' && top != '<'))
            {
                cout << "INVALID";
                return 0;
            }
        }
    }
    if(st.empty())
        cout << "VALID";
    else
        cout << "INVALID";
    return 0;
}