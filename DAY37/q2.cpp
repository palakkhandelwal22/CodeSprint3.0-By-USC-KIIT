#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() 
{
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> arr(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> arr[i];
    }
    unordered_map<long long, long long> freq;
    long long prefixSum = 0;
    long long count = 0;
    freq[0] = 1;
    for (int i = 0; i < N; i++) 
    {
        prefixSum += arr[i];
        if (freq.find(prefixSum - K) != freq.end()) 
        {
            count += freq[prefixSum - K];
        }
        freq[prefixSum]++;
    }
    cout << count;
    return 0;
}