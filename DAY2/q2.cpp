#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of transactions : ";
    cin >> n;
    int arr[n];
    cout << "Enter each transaction amount :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max = arr[0];
    int smax = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != max)
        {
            if (arr[i] > smax)
            {
                smax = arr[i];
            }
        }
    }
    cout << smax;
    return 0;
}