#include <iostream>
#include <algorithm>
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
    sort(arr, arr + n);
    long long maxLoad = 0;
    int left = 0;
    int right = n - 1;
    while(left < right)
    {
        long long load = arr[left] + arr[right];
        if(load > maxLoad)
        {
            maxLoad = load;
        }
        left++;
        right--;
    }
    cout << maxLoad;
    return 0;
}