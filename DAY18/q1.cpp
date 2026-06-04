#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    long long data;
    Node* next;
    Node(long long val)
    {
        data = val;
        next = NULL;
    }
};
bool hasCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<Node*> nodes;
    for(int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        nodes.push_back(new Node(x));
    }
    for(int i = 0; i < n - 1; i++)
    {
        nodes[i]->next = nodes[i + 1];
    }
    int pos;
    cin >> pos;
    if(pos != -1)
    {
        nodes[n - 1]->next = nodes[pos];
    }
    if(hasCycle(nodes[0]))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}