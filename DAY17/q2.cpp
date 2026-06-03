#include <iostream>
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
Node* removeKthFromEnd(Node* head, int k)
{
    Node dummy(0);
    dummy.next = head;
    Node* fast = &dummy;
    Node* slow = &dummy;
    for(int i = 0; i <= k; i++)
    {
        fast = fast->next;
    }
    while(fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete;
    return dummy.next;
}
int main()
{
    int n;
    cin >> n;
    Node* head = NULL;
    Node* tail = NULL;
    for(int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        Node* newNode = new Node(x);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    int k;
    cin >> k;
    head = removeKthFromEnd(head, k);
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data;
        if(temp->next != NULL)
        {
            cout << " ";
        }
        temp = temp->next;
    }
    return 0;
}