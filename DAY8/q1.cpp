#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the value of N:";
    cin >> n;
    int arr[n];
    cout << "Enter roll numbers :" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        int num = arr[i];
        int count = 0;
        while(num > 0)
        {
            if(num % 2 == 1)
            {
                count++;
            }
            num = num / 2;
        }
        if(count % 2 == 1)
        {
            cout << "ANSWER" << endl;
        }
        else
        {
            cout << "SAFE" << endl;
        }
    }
    return 0;
}