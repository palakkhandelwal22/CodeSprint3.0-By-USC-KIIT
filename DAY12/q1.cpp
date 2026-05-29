#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the integers : ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int left = 0;
    int right = n - 1;
    int minSum = 1000000000;
    int first, second;
    while(left < right)
    {
        int sum = arr[left] + arr[right];
        if(abs(sum) < abs(minSum))
        {
            minSum = sum;
            first = arr[left];
            second = arr[right];
        }
        if(sum < 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    cout << first << " " << second;
    return 0;
}