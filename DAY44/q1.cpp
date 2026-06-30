#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int P;
    cin >> P;
    unordered_map<string, int> id;
    vector<vector<int>> undirected;
    vector<int> indegree, outdegree;
    int idx = 0;
    auto getId = [&](const string &s) 
    {
        if (!id.count(s)) 
        {
            id[s] = idx++;
            undirected.push_back(vector<int>());
            indegree.push_back(0);
            outdegree.push_back(0);
        }
        return id[s];
    };
    for (int i = 0; i < P; i++) 
    {
        string u, v;
        cin >> u >> v;
        int a = getId(u);
        int b = getId(v);
        outdegree[a]++;
        indegree[b]++;

        undirected[a].push_back(b);
        undirected[b].push_back(a);
    }
    vector<bool> vis(idx, false);
    int start = -1;
    for (int i = 0; i < idx; i++) 
    {
        if (indegree[i] + outdegree[i] > 0) 
        {
            start = i;
            break;
        }
    }
    if (start != -1) 
    {
        queue<int> q;
        q.push(start);
        vis[start] = true;
        while (!q.empty()) 
        {
            int node = q.front();
            q.pop();
            for (int nxt : undirected[node]) 
            {
                if (!vis[nxt]) 
                {
                    vis[nxt] = true;
                    q.push(nxt);
                }
            }
        }
        for (int i = 0; i < idx; i++) 
        {
            if ((indegree[i] + outdegree[i] > 0) && !vis[i]) 
            {
                cout << "ASSEMBLY IMPOSSIBLE";
                return 0;
            }
        }
    }
    int startNodes = 0, endNodes = 0;
    for (int i = 0; i < idx; i++)
    {
        if (outdegree[i] - indegree[i] == 1)
            startNodes++;
        else if (indegree[i] - outdegree[i] == 1)
            endNodes++;
        else if (indegree[i] != outdegree[i]) 
        {
            cout << "ASSEMBLY IMPOSSIBLE";
            return 0;
        }
    }
    if ((startNodes == 1 && endNodes == 1) ||
        (startNodes == 0 && endNodes == 0))
        cout << "ASSEMBLY POSSIBLE";
    else
        cout << "ASSEMBLY IMPOSSIBLE";
    return 0;
}