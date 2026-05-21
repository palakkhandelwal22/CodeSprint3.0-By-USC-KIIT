#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the value of N:";
    cin >> n;
    int nsp = 2 * n - 2;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for(int j = 1; j <= nsp; j++)
        {
            cout << "@";
        }
        for(int j = i; j >= 1; j--)
        {
            cout << j;
        }
        nsp -= 2;
        cout << endl;
    }
    return 0;
}