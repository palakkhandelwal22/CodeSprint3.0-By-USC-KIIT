#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{
    int M, N;
    cin >> M >> N;
    vector<vector<int>> mat(M, vector<int>(N));
    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cin >> mat[i][j];
        }
    }
    bool first = true;
    for (int d = 0; d < M + N - 1; d++) 
    {
        vector<int> diagonal;
        int row = min(d, M - 1);
        int col = d - row;
        while (row >= 0 && col < N) 
        {
            diagonal.push_back(mat[row][col]);
            row--;
            col++;
        }
        if (d % 2 == 0)
            reverse(diagonal.begin(), diagonal.end());
        for (int x : diagonal) 
        {
            if (!first) cout << " ";
            cout << x;
            first = false;
        }
    }
    return 0;
}