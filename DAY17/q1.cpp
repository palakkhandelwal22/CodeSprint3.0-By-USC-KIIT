#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
Node* reverseList(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL)
    {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
int main()
{
    int n;
    cin >> n;
    Node* head = NULL;
    Node* tail = NULL;
    for(int i = 0; i < n; i++)
    {
        int x;
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
    head = reverseList(head);
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