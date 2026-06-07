#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    cin.ignore();
    vector<int> nums;
    for(int i = 0; i < N; i++)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int x;
        while(ss >> x)
        {
            nums.push_back(x);
        }
    }
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if(i != nums.size() - 1)
        {
            cout << " ";
        }
    }
    return 0;
}