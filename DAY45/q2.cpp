#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) 
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> color(N + 1, 0);
    for (int i = 1; i <= N; i++) 
    {
        if (color[i] != 0)
            continue;
        queue<int> q;
        q.push(i);
        color[i] = 1;
        while (!q.empty()) 
        {
            int node = q.front();
            q.pop();
            for (int nxt : graph[node]) 
            {
                if (color[nxt] == 0) 
                {
                    color[nxt] = 3 - color[node];
                    q.push(nxt);
                }
                else if (color[nxt] == color[node]) 
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= N; i++) 
    {
        cout << color[i];
        if (i != N)
            cout << " ";
    }
    return 0;
}