#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the size of the array:";
    cin >> n;
    int arr[n];
    cout << "Enter the elements : " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans[n];
    int left = 0;
    int right = n - 1;
    int k = n - 1;
    while(left <= right)
    {
        int leftSquare = arr[left] * arr[left];
        int rightSquare = arr[right] * arr[right];
        if(leftSquare > rightSquare)
        {
            ans[k] = leftSquare;
            left++;
        }
        else
        {
            ans[k] = rightSquare;
            right--;
        }
        k--;
    }
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}