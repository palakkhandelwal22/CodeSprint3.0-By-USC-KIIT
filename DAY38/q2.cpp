#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
int main() 
{
    int N;
    cin >> N;
    vector<long long> arr(N);
    unordered_set<long long> st;
    for (int i = 0; i < N; i++) 
    {
        cin >> arr[i];
        st.insert(arr[i]);
    }
    int longest = 0;
    for (long long num : st) 
    {
        if (st.find(num - 1) == st.end()) 
        {
            long long current = num;
            int length = 1;
            while (st.find(current + 1) != st.end()) 
            {
                current++;
                length++;
            }
            longest = max(longest, length);
        }
    }
    cout << longest;
    return 0;
}