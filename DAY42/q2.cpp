#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<vector<int>> adj;
vector<int> tin, tout;
vector<ll> value;
vector<ll> bit;
int timer = 0;
void dfs(int node, int parent) 
{
    tin[node] = ++timer;
    for (int child : adj[node]) 
    {
        if (child != parent)
            dfs(child, node);
    }
    tout[node] = timer;
}
void update(int idx, ll delta, int n) 
{
    while (idx <= n) 
    {
        bit[idx] += delta;
        idx += idx & (-idx);
    }
}
ll query(int idx) 
{
    ll sum = 0;
    while (idx > 0) 
    {
        sum += bit[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
ll rangeQuery(int l, int r) 
{
    return query(r) - query(l - 1);
}
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    value.resize(N + 1);
    adj.resize(N + 1);
    tin.resize(N + 1);
    tout.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> value[i];
    for (int i = 0; i < N - 1; i++) 
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    bit.assign(N + 2, 0);
    for (int i = 1; i <= N; i++)
        update(tin[i], value[i], N);
    while (Q--) 
    {
        int type;
        cin >> type;
        if (type == 1) 
        {
            int X;
            ll V;
            cin >> X >> V;
            ll diff = V - value[X];
            value[X] = V;
            update(tin[X], diff, N);
        }
        else 
        {
            int X;
            cin >> X;
            cout << rangeQuery(tin[X], tout[X]) << "\n";
        }
    }
    return 0;
}