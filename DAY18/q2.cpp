#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    long long path1[N];
    for(int i = 0; i < N; i++)
    {
        cin >> path1[i];
    }
    int M;
    cin >> M;
    long long path2[M];
    for(int i = 0; i < M; i++)
    {
        cin >> path2[i];
    }
    long long X;
    cin >> X;
    cout << X;
    return 0;
}