#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<long long>> matrix(N, vector<long long>(M));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> matrix[i][j];
        }
    }
    long long X;
    cin >> X;
    int low = 0;
    int high = N * M - 1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int row = mid / M;
        int col = mid % M;
        if(matrix[row][col] == X)
        {
            cout << "FOUND";
            return 0;
        }
        else if(matrix[row][col] < X)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "NOT FOUND";
    return 0;
}