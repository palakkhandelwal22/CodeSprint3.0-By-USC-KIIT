#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() 
{
    int N;
    cin >> N;
    vector<int> arr(N);
    int uniqueNum = 0;
    for(int i = 0; i < N; i++) 
    {
        cin >> arr[i];
        uniqueNum ^= arr[i];
    }
    sort(arr.begin(), arr.end());
    int position = 0;
    for(int i = 0; i < N; i++) 
    {
        if(arr[i] == uniqueNum) 
        {
            position = i + 1; 
            break;
        }
    }
    cout << uniqueNum << " " << position;   
    return 0;
}