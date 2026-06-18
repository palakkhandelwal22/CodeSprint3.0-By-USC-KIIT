#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() 
{
    int K, Q;
    cin >> K >> Q;
    vector<long long> q(K);
    int front = 0;
    int rear = -1;
    int count = 0;
    while (Q--) 
    {
        string op;
        cin >> op;
        if (op == "ENQUEUE") 
        {
            long long x;
            cin >> x;
            if (count == K) 
            {
                cout << "FULL" << "\n";
            } 
            else 
            {
                rear = (rear + 1) % K;
                q[rear] = x;
                count++;
            }
        }
        else if (op == "DEQUEUE") 
        {
            if (count == 0) 
            {
                cout << "EMPTY" << "\n";
            } 
            else 
            {
                front = (front + 1) % K;
                count--;
            }
        }
        else if (op == "FRONT") 
        {
            if (count == 0) 
            {
                cout << -1 << "\n";
            } 
            else 
            {
                cout << q[front] << "\n";
            }
        }
    }
    return 0;
}