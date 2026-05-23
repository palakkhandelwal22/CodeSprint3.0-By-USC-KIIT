#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the value of N:";
    cin >> n;
    int arr[n][n];
    cout << "Enter the elements of the matrix:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int mainDiagonal = 0;
    int secDiagonal = 0;
    for(int i = 0; i < n; i++)
    {
        mainDiagonal = mainDiagonal + arr[i][i];
        secDiagonal = secDiagonal + arr[i][n - i - 1];
    }
    if(mainDiagonal == secDiagonal)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}