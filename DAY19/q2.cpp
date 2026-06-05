#include <iostream>
using namespace std;
struct Node
{
    long long data;
    Node* prev;
    Node* next;
    Node(long long val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};
Node* rotateRight(Node* head, int k)
{
    if(head == NULL || head->next == NULL || k == 0)
        return head;
    int n = 1;
    Node* tail = head;
    while(tail->next)
    {
        tail = tail->next;
        n++;
    }
    k %= n;
    if(k == 0)
        return head;
    int steps = n - k - 1;
    Node* newTail = head;
    for(int i = 0; i < steps; i++)
    {
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;
    tail->next = head;
    head->prev = tail;
    newTail->next = NULL;
    newHead->prev = NULL;
    return newHead;
}
int main()
{
    int n, k;
    cin >> n >> k;
    Node* head = NULL;
    Node* tail = NULL;
    for(int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        Node* newNode = new Node(x);
        if(head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    head = rotateRight(head, k);
    Node* temp = head;
    while(temp)
    {
        cout << temp->data;
        if(temp->next)
            cout << " ";
        temp = temp->next;
    }
    return 0;
}