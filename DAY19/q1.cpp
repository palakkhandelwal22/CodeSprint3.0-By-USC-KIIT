#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> ids(n);
    for(int i = 0; i < n; i++)
    {
        cin >> ids[i];
    }
    int k;
    cin >> k;
    int index = 0;
    while(ids.size() > 1)
    {
        index = (index + k - 1) % ids.size();
        ids.erase(ids.begin() + index);
    }
    cout << ids[0];
    return 0;
}