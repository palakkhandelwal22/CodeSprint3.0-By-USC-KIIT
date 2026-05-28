#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of students:";
    cin >> n;
    int count0 = 0, count1 = 0, count2 = 0;
    cout << "Enter integers ( only 0 , 1 & 2) : ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 0)
            count0++;
        else if (x == 1)
            count1++;
        else
            count2++;
    }
    while (count0--)
        cout << 0 << " ";
    while (count1--)
        cout << 1 << " ";
    while (count2--)
        cout << 2 << " ";
    return 0;
}