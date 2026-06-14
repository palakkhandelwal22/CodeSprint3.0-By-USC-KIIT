#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main()
{
    int Q;
    cin >> Q;
    queue<long long> q;
    while(Q--)
    {
        string op;
        cin >> op;
        if(op == "REGISTER")
        {
            long long x;
            cin >> x;
            q.push(x);
        }
        else if(op == "WITHDRAW")
        {
            if(!q.empty())
            {
                q.pop();
            }
        }
        else if(op == "NEXT")
        {
            if(q.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << q.front() << endl;
                q.pop();
            }
        }
    }
    return 0;
}