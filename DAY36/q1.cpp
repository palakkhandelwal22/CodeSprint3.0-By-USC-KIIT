#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main() 
{
    int N;
    cin >> N;
    vector<int> marks(N);
    for(int i = 0; i < N; i++) 
    {
        cin >> marks[i];
    }
    sort(marks.begin(), marks.end(), greater<int>());
    unordered_map<int, int> rankMap;
    for(int i = 0; i < N; i++) 
    {
        rankMap[marks[i]] = i + 1;
    }
    int Q;
    cin >> Q;
    while(Q--) 
    {
        int score;
        cin >> score;
        if(rankMap.find(score) != rankMap.end()) 
        {
            cout << "Rank " << rankMap[score] << endl;
        } 
        else 
        {
            cout << "No Rank" << endl;
        }
    }
    return 0;
}