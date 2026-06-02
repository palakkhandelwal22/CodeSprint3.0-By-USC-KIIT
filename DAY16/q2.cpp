#include <iostream>
using namespace std;
int main()
{
    int N, K;
    long long X;
    cin >> N >> K >> X;
    int arr[N];
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    long long sum = 0;
    int zeroCount = 0;
    for(int i = 0; i < K; i++)
    {
        sum += arr[i];
        if(arr[i] == 0)
        {
            zeroCount++;
        }
    }
    if(sum >= X && zeroCount == 0)
    {
        cout << "YES";
        return 0;
    }
    for(int i = K; i < N; i++)
    {
        sum -= arr[i - K];
        if(arr[i - K] == 0)
        {
            zeroCount--;
        }
        sum += arr[i];
        if(arr[i] == 0)
        {
            zeroCount++;
        }
        if(sum >= X && zeroCount == 0)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}