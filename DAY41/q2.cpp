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
bool isLeaf(Node* node) 
{
    return node && node->left == NULL && node->right == NULL;
}
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
void leftBoundary(Node* root, vector<int>& ans) 
{
    Node* curr = root->left;
    while (curr) 
    {
        if (!isLeaf(curr))
            ans.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}
void leaves(Node* root, vector<int>& ans) 
{
    if (!root)
        return;
    if (isLeaf(root)) 
    {
        ans.push_back(root->data);
        return;
    }
    leaves(root->left, ans);
    leaves(root->right, ans);
}
void rightBoundary(Node* root, vector<int>& ans) 
{
    vector<int> temp;
    Node* curr = root->right;
    while (curr) 
    {
        if (!isLeaf(curr))
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
        ans.push_back(temp[i]);
}
int main() 
{
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    Node* root = buildTree(arr);
    if (!root)
        return 0;
    vector<int> ans;
    ans.push_back(root->data);
    leftBoundary(root, ans);
    if (!isLeaf(root))
        leaves(root, ans);
    rightBoundary(root, ans);
    for (int i = 0; i < ans.size(); i++) 
    {
        if (i)
            cout << " ";
        cout << ans[i];
    }
    return 0;
}