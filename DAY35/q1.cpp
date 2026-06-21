#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> scores(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> scores[i];
    }
    sort(scores.begin(), scores.end());
    vector<long long> prefix(N + 1, 0);
    for (int i = 0; i < N; i++) 
    {
        prefix[i + 1] = prefix[i] + scores[i];
    }
    long long answer = 0;
    int i = 0;
    while (i < N) 
    {
        int j = i;
        while (j < N && scores[j] == scores[i]) 
        {
            j++;
        }
        long long smallerSum = prefix[i];
        if (smallerSum >= K) 
        {
            answer += (j - i);
        }
        i = j;
    }
    cout << answer;
    return 0;
}