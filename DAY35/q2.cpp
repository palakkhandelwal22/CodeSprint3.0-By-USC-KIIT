#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() 
{
    int N;
    long long X;
    cin >> N >> X;
    unordered_map<long long, int> freq;
    for (int i = 0; i < N; i++) 
    {
        long long w;
        cin >> w;
        freq[w]++;
    }
    long long count = 0;
    for (auto &p : freq) 
    {
        long long a = p.first;
        long long b = X - a;
        if (freq.find(b) == freq.end())
            continue;
        if (a < b) 
        {
            count++;
        }
        else if (a == b && freq[a] >= 2) 
        {
            count++;
        }
    }
    cout << count;
    return 0;
}