#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int countVowels(string s)
{
    int count = 0;
    for (char c : s)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            count++;
    }
    return count;
}
bool compare(string a, string b)
{
    int va = countVowels(a);
    int vb = countVowels(b);
    if (va != vb)
        return va > vb;
    if (a.length() != b.length())
        return a.length() < b.length();
    return a < b;
}
int main()
{
    int N;
    cin >> N;
    vector<string> usernames(N);
    for (int i = 0; i < N; i++)
    {
        cin >> usernames[i];
    }
    sort(usernames.begin(), usernames.end(), compare);
    for (string s : usernames)
    {
        cout << s << endl;
    }
    return 0;
}