#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of subjects : ";
    cin >> n;
    int arr[n];
    cout << "Enter the marks : ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    bool found=false;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                found = true;
                break;
            }
        }
        if(found == true)
        {
            break;
        }
    }
    if(found == true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}