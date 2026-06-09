#include <iostream>
#include <vector>
#include <climits>
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
    int Q;
    cin >> Q;
    while(Q--)
    {
        int L, R;
        cin >> L >> R;
        long long mn = LLONG_MAX;
        long long mx = LLONG_MIN;
        for(int i = L; i <= R; i++)
        {
            mn = min(mn, arr[i]);
            mx = max(mx, arr[i]);
        }
        cout << mx - mn << endl;
    }
    return 0;
}