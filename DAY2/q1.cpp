#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of players : ";
    cin >> n;
    int arr[n];
    int sum = 0;
    cout << " Enter the score for each players : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int avg = sum / n;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > avg)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}