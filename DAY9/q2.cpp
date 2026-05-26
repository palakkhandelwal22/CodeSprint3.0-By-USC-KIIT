#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the value of N:";
    cin >> n;
    string arr[n];
    cout << "Enter the series names:"<< endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    string prefix = arr[0];
    for(int i = 1; i < n; i++)
    {
        string temp = "";
        int j = 0;
        while(j < prefix.length() &&j < arr[i].length() &&prefix[j] == arr[i][j])
        {
            temp += prefix[j];
            j++;
        }
        prefix = temp;
    }
    cout << prefix;
    return 0;
}