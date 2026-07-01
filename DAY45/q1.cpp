#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;
const ll INF = 4e18;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> dist(N + 1, vector<ll>(N + 1, INF));
    for (int i = 1; i <= N; i++)
        dist[i][i] = 0;
    for (int i = 0; i < M; i++) 
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }
    for (int k = 1; k <= N; k++) 
    {
        for (int i = 1; i <= N; i++) 
        {
            if (dist[i][k] == INF)
                continue;
            for (int j = 1; j <= N; j++) 
            {
                if (dist[k][j] == INF)
                    continue;
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    int Q;
    cin >> Q;
    while (Q--) 
    {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF)
            cout << -1 << "\n";
        else
            cout << dist[a][b] << "\n";
    }
    return 0;
}