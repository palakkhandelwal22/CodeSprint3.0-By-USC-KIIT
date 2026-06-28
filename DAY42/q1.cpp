#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node 
{
    int data;
    Node *left, *right;
    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};
Node* buildTree(vector<int>& arr) 
{
    if (arr.empty() || arr[0] == -1)
        return NULL;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size()) 
    {
        Node* curr = q.front();
        q.pop();
        if (i < arr.size() && arr[i] != -1) 
        {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        if (i < arr.size() && arr[i] != -1) 
        {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
void recoverBST(Node* root) 
{
    Node *first = NULL, *second = NULL, *prev = NULL;
    Node* curr = root;
    while (curr) 
    {
        if (curr->left == NULL) 
        {
            if (prev && prev->data > curr->data) 
            {
                if (!first)
                    first = prev;
                second = curr;
            }
            prev = curr;
            curr = curr->right;
        }
        else 
        {
            Node* pred = curr->left;
            while (pred->right && pred->right != curr)
                pred = pred->right;
            if (pred->right == NULL) 
            {
                pred->right = curr;
                curr = curr->left;
            }
            else 
            {
                pred->right = NULL;
                if (prev && prev->data > curr->data) 
                {
                    if (!first)
                        first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            }
        }
    }
    if (first && second)
        swap(first->data, second->data);
}
void printLevelOrder(Node* root) 
{
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) 
    {
        Node* node = q.front();
        q.pop();
        if (node == NULL) 
        {
            cout << -1 << " ";
            continue;
        }
        cout << node->data << " ";
        if (node->left || node->right) 
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
}
int main() 
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    Node* root = buildTree(arr);
    recoverBST(root);
    printLevelOrder(root);
    return 0;
}