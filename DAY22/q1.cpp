#include <iostream>
#include <vector>
using namespace std;
vector<string> paths;
void solve(int i, int j, vector<vector<int>>& maze,
           vector<vector<int>>& vis, string path, int n)
{
    if(i == n - 1 && j == n - 1)
    {
        paths.push_back(path);
        return;
    }
    vis[i][j] = 1;
    if(i + 1 < n && maze[i + 1][j] == 1 && !vis[i + 1][j])
        solve(i + 1, j, maze, vis, path + "D", n);
    if(j - 1 >= 0 && maze[i][j - 1] == 1 && !vis[i][j - 1])
        solve(i, j - 1, maze, vis, path + "L", n);
    if(j + 1 < n && maze[i][j + 1] == 1 && !vis[i][j + 1])
        solve(i, j + 1, maze, vis, path + "R", n);
    if(i - 1 >= 0 && maze[i - 1][j] == 1 && !vis[i - 1][j])
        solve(i - 1, j, maze, vis, path + "U", n);
    vis[i][j] = 0; 
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    if(maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
    {
        cout << -1;
        return 0;
    }
    vector<vector<int>> vis(n, vector<int>(n, 0));
    solve(0, 0, maze, vis, "", n);
    if(paths.empty())
    {
        cout << -1;
    }
    else
    {
        for(string p : paths)
        {
            cout << p << endl;
        }
    }
    return 0;
}