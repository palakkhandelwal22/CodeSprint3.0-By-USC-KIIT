#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the value of N:";
    cin >> n;
    cout << "Enter the matrix:" << endl;
    int arr[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << "Final seating arrangement:" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] == 1)
            {
                cout << "O ";
            }
            else if((i > 0 && arr[i-1][j] == 1) ||(i < n-1 && arr[i+1][j] == 1) ||(j > 0 && arr[i][j-1] == 1) ||(j < n-1 && arr[i][j+1] == 1))
            {
                cout << "X ";
            }
            else
            {
                cout << "S ";
            }
        }
        cout << endl;
    }
    return 0;
}