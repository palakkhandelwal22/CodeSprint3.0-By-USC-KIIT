#include <iostream>
using namespace std;
int main()
{
    int n, x;
    cout << "Enter the value of n and x:";
    cin >> n >> x;
    int arr[n];
    cout << "Enter the number of students :"<< endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    int index = -1;
    for(int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if(sum > x)
        {
            index = i;
            break;
        }
    }
    cout << index;
    return 0;
}