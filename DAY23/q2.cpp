#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> arr(N);
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
        unordered_map<int, int> freq;
        for(int i = L; i <= R; i++)
        {
            freq[arr[i]]++;
        }
        long long score = 0;
        for(auto &p : freq)
        {
            score += 1LL * p.second * p.second;
        }
        cout << score << endl;
    }
    return 0;
}