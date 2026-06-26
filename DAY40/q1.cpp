#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() 
{
    int N;
    cin >> N;
    vector<long long> treasure(N + 1);
    for (int i = 1; i <= N; i++) 
    {
        cin >> treasure[i];
    }
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < N - 1; i++) 
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> level(N + 1, -1);
    queue<int> q;
    q.push(1);
    level[1] = 0;
    long long ans = 0;
    while (!q.empty()) 
    {
        int node = q.front();
        q.pop();
        if (level[node] % 2 == 0)
            ans += treasure[node];
        for (int child : adj[node]) 
        {
            if (level[child] == -1) 
            {
                level[child] = level[node] + 1;
                q.push(child);
            }
        }
    }
    cout << ans;
    return 0;
}