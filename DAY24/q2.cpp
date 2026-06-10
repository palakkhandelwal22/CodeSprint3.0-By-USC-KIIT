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
    int slow = 0;
    int fast = 0;
    while(fast < N && fast + 1 < N)
    {
        slow++;
        fast += 2;
    }
    cout << arr[slow];
    return 0;
}