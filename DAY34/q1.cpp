#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() 
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            cin >> grid[i][j];
            if (grid[i][j] == 2) 
            {
                q.push({i, j});
            } 
            else if (grid[i][j] == 1) 
            {
                fresh++;
            }
        }
    }
    if (fresh == 0) 
    {
        cout << 0;
        return 0;
    }
    int minutes = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while (!q.empty() && fresh > 0) 
    {
        int sz = q.size();
        minutes++;
        while (sz--) 
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) 
            {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx >= 0 && nx < N &&
                    ny >= 0 && ny < M &&
                    grid[nx][ny] == 1) 
                    {
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx, ny});
                }
            }
        }
    }
    if (fresh > 0)
        cout << -1;
    else
        cout << minutes;
    return 0;
}