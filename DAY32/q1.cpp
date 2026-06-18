#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    int Q;
    cin >> Q;
    stack<long long> s1, s2;
    while(Q--)
    {
        string op;
        cin >> op;
        if(op == "REGISTER")
        {
            long long x;
            cin >> x;
            s1.push(x);
        }
        else if(op == "NEXT")
        {
            if(s2.empty())
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            if(s2.empty())
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << s2.top() << "\n";
                s2.pop();
            }
        }
    }
    return 0;
}