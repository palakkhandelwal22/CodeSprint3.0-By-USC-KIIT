#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the value of N:";
    cin >> n;
    int arr[n];
    cout << "Enter the bracelet IDs:"<< endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int xorValue = 0;
    for(int i = 0; i < n; i++)
    {
        xorValue = xorValue ^ arr[i];
    }
    if(xorValue == 0)
    {
        cout << "BALANCED";
    }
    else
    {
        cout << "UNBALANCED";
    }
    return 0;
}