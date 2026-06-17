#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    stack<int> st;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        char ch = s[i];
        if(isdigit(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int result;
            if(ch == '+')
                result = a + b;
            else if(ch == '-')
                result = a - b;
            else if(ch == '*')
                result = a * b;
            else
                result = a / b;   
            st.push(result);
        }
    }
    cout << st.top();
    return 0;
}