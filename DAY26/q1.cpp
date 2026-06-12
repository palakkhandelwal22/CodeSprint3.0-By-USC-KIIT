#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<long long> userID(N);
    vector<int> randomIndex(N);
    for(int i = 0; i < N; i++)
    {
        cin >> userID[i];
    }
    for(int i = 0; i < N; i++)
    {
        cin >> randomIndex[i];
    }
    for(int i = 0; i < N; i++)
    {
        cout << userID[i] << " " << randomIndex[i] << endl;
    }
    return 0;
}