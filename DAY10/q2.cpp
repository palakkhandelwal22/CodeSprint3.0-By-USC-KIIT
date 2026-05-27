#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of values:";
    cin >> n;
    int arr[n];
    cout << "Enter the number of integers:";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout << "Enter the target value :";
    cin >> k;
    sort(arr, arr + n);
    bool found = false;
    for(int i = 0; i < n - 2; i++)
    {
        int left = i + 1;
        int right = n - 1;
        while(left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];
            if(sum == k)
            {
                found = true;
                break;
            }
            else if(sum < k)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        if(found)
        {
            break;
        }
    }
    if(found)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}