#include <iostream>
using namespace std;
int main()
{
    string jewels, stones;
    cin >> jewels;
    cin >> stones;
    int count = 0;
    for(int i = 0; i < stones.length(); i++)
    {
        for(int j = 0; j < jewels.length(); j++)
        {
            if(stones[i] == jewels[j])
            {
                count++;
                break;
            }
        }
    }
    cout << count;
    return 0;
}