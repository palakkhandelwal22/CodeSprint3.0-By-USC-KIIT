#include <iostream>
using namespace std;
struct Node 
{
    long long data;
    Node *left, *right;
    Node(long long val) 
    {
        data = val;
        left = right = NULL;
    }
};
Node* insert(Node* root, long long val) 
{
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
int count = 0;
long long ans = 0;
void reverseInorder(Node* root, int K) 
{
    if (root == NULL || count >= K)
        return;
    reverseInorder(root->right, K);
    count++;
    if (count == K) 
    {
        ans = root->data;
        return;
    }
    reverseInorder(root->left, K);
}
int main() 
{
    int N;
    cin >> N;
    Node* root = NULL;
    for (int i = 0; i < N; i++) 
    {
        long long x;
        cin >> x;
        root = insert(root, x);
    }
    int K;
    cin >> K;
    reverseInorder(root, K);
    cout << ans;
    return 0;
}