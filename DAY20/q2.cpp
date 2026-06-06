#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        cout << arr[i];
        if(i != n - 1)
        {
            cout << " ";
        }
    }
    return 0;
}