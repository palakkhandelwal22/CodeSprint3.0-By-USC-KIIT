#include <iostream>
using namespace std;
struct Participant
{
    string name;
    int score;
};
int main()
{
    int n;
    cout << "Enter the number of participants : ";
    cin >> n;
    Participant arr[n];
    cout << "Enter a name and score : " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].name >> arr[i].score;
    }
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j].score > arr[j + 1].score)
            {
                Participant temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "LeaderBoard : " << endl ;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i].name << " " << arr[i].score << endl;
    }
    return 0;
}