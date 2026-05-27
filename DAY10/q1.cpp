#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of restaurants:";
    cin >> n;
    string arr[n];
    cout << "Enter the restaurants names:"<< endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    string prefix;
    cout << "Search Prefix:";
    cin >> prefix;
    sort(arr, arr + n);
    for(int i = 0; i < n; i++)
    {
        if(arr[i].find(prefix) == 0)
        {
            cout << arr[i] << endl;
        }
    }
    return 0;
}