#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool dfs(vector<vector<char>>& board, string& word,
         int i, int j, int idx) 
         {
    if (idx == word.size())
        return true;
    int n = board.size();
    int m = board[0].size();
    if (i < 0 || i >= n || j < 0 || j >= m ||
        board[i][j] != word[idx])
        return false;
    char temp = board[i][j];
    board[i][j] = '#'; 
    bool found =
        dfs(board, word, i + 1, j, idx + 1) ||
        dfs(board, word, i - 1, j, idx + 1) ||
        dfs(board, word, i, j + 1, idx + 1) ||
        dfs(board, word, i, j - 1, idx + 1);
    board[i][j] = temp; 
    return found;
}
int main() 
{
    int N, M;
    cin >> N >> M;
    vector<vector<char>> board(N, vector<char>(M));
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            cin >> board[i][j];
        }
    }
    string word;
    cin >> word;
    bool exists = false;
    for (int i = 0; i < N && !exists; i++) 
    {
        for (int j = 0; j < M && !exists; j++) 
        {
            if (dfs(board, word, i, j, 0)) 
            {
                exists = true;
            }
        }
    }
    cout << (exists ? "YES" : "NO");
    return 0;
}