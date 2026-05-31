#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int left = 0;
    int right = n - 1;
    int maxScore = 0;
    while(left < right)
    {
        int height = min(arr[left], arr[right]);
        int width = right - left;
        int score = height * width;
        if(score > maxScore)
        {
            maxScore = score;
        }
        if(arr[left] < arr[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    cout << maxScore;
    return 0;
}