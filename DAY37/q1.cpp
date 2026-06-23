#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() 
{
    int N, K;
    cin >> N >> K;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < N; i++) 
    {
        long long x;
        cin >> x;
        pq.push(x);
        if ((int)pq.size() > K) 
        {
            pq.pop();
        }
    }
    vector<long long> ans;
    while (!pq.empty()) 
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) 
    {
        if (i) cout << " ";
        cout << ans[i];
    }
    return 0;
}