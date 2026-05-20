#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of alarm codes:";
    cin >> n;
    int arr[n];
    cout << "Enter the alarm codes :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool found = false;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            cout << "INVALID " << i;
            found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "VALID";
    }
    return 0;
}