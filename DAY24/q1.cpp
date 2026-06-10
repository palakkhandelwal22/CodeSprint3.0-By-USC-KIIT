#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    long long W;
    cin >> N >> W;
    vector<long long> arr(N);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int left = 0;
    long long sum = 0;
    int maxLen = 0;
    for(int right = 0; right < N; right++)
    {
        sum += arr[right];
        while(sum > W)
        {
            sum -= arr[left];
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    cout << maxLen;
    return 0;
}