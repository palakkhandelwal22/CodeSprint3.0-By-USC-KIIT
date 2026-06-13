#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<long long> arr(N);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int low = 0;
    int high = N - 1;
    while(low < high)
    {
        int mid = low + (high - low) / 2;
        if(arr[mid] < arr[mid + 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    cout << arr[low];
    return 0;
}