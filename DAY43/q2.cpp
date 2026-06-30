#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef long long ll;
struct Edge 
{
    int u, v;
    ll w;
};
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<Edge> edges;
    vector<vector<int>> rev(N + 1);
    for (int i = 0; i < M; i++) 
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        rev[v].push_back(u);
    }
    vector<bool> canReachEnd(N + 1, false);
    queue<int> q;
    q.push(N);
    canReachEnd[N] = true;
    while (!q.empty()) 
    {
        int node = q.front();
        q.pop();
        for (int prev : rev[node]) 
        {
            if (!canReachEnd[prev]) 
            {
                canReachEnd[prev] = true;
                q.push(prev);
            }
        }
    }
    vector<ll> dist(N + 1, LLONG_MIN);
    dist[1] = 0;
    for (int i = 1; i <= N - 1; i++) 
    {
        bool updated = false;
        for (auto &e : edges) 
        {
            if (dist[e.u] == LLONG_MIN)
                continue;
            if (dist[e.u] + e.w > dist[e.v]) 
            {
                dist[e.v] = dist[e.u] + e.w;
                updated = true;
            }
        }
        if (!updated)
            break;
    }
    for (auto &e : edges) 
    {
        if (dist[e.u] == LLONG_MIN)
            continue;
        if (dist[e.u] + e.w > dist[e.v] && canReachEnd[e.v]) 
        {
            cout << "INFINITE PROFIT";
            return 0;
        }
    }
    if (dist[N] == LLONG_MIN)
        cout << "UNREACHABLE";
    else
        cout << dist[N];    
    return 0;
}