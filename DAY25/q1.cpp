#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> height(N);
    for(int i = 0; i < N; i++)
    {
        cin >> height[i];
    }
    int left = 0;
    int right = N - 1;
    long long maxArea = 0;
    while(left < right)
    {
        long long area = 1LL * min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, area);
        if(height[left] < height[right])
            left++;
        else
            right--;
    }
    cout << maxArea;
    return 0;
}