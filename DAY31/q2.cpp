#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    int Q;
    cin >> Q;
    stack<long long> st;
    stack<long long> minSt;
    while(Q--)  
    {
        string op;
        cin >> op;
        if(op == "PUSH")
        {
            long long x;
            cin >> x;
            st.push(x);
            if(minSt.empty() || x <= minSt.top())
            {
                minSt.push(x);
            }
        }
        else if(op == "POP")
        {
            if(!st.empty())
            {
                if(st.top() == minSt.top())
                {
                    minSt.pop();
                }
                st.pop();
            }
        }
        else if(op == "MIN")
        {
            if(st.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << minSt.top() << "\n";
            }
        }
    }
    return 0;
}