#include <iostream>
#include <vector>
using namespace std;
int main() 
{
    int N, X;
    cin >> N >> X;
    vector<int> cost(N), energy(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> cost[i] >> energy[i];
    }
    vector<long long> dp(X + 1, 0);
    for (int i = 0; i < N; i++) 
    {
        for (int j = cost[i]; j <= X; j++) 
        {
            dp[j] = max(dp[j], dp[j - cost[i]] + energy[i]);
        }
    }
    cout << dp[X];
    return 0;
}