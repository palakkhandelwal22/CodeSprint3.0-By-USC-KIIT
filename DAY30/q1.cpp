#include <iostream>
#include <stack>
#include <string>
using namespace std;
int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return 0;
}
int main()
{
    string s;
    cin >> s;
    stack<char> st;
    string postfix = "";
    for(char ch : s)
    {
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            postfix += ch;
        }
        else if(ch == '(')
        {
            st.push(ch);
        }
        else if(ch == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() &&
                  precedence(st.top()) >= precedence(ch))
            {
                if(st.top() == '(')
                    break;
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty())
    {
        postfix += st.top();
        st.pop();
    }
    cout << postfix;
    return 0;
}