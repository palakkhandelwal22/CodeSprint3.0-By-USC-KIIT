#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef long long ll;
struct Edge 
{
    int to;
    ll travel;
    ll expiry;
};
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < M; i++) 
    {
        int u, v;
        ll t, e;
        cin >> u >> v >> t >> e;
        graph[u].push_back({v, t, e});
    }
    vector<ll> dist(N + 1, LLONG_MAX);
    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) 
    {
        auto curr = pq.top();
        pq.pop();
        ll time = curr.first;
        int node = curr.second;
        if (time > dist[node])
            continue;
        for (auto edge : graph[node]) 
        {
            if (time >= edge.expiry)
                continue;
            ll newTime = time + edge.travel;
            if (newTime < dist[edge.to]) 
            {
                dist[edge.to] = newTime;
                pq.push({newTime, edge.to});
            }
        }
    }
    for (int i = 1; i <= N; i++) 
    {
        if (dist[i] == LLONG_MAX)
            cout << -1;
        else
            cout << dist[i];
        if (i != N)
            cout << " ";
    }
    return 0;
}