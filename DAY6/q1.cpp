#include <iostream>
using namespace std;
int main()
{
    string password;
    cout << "Enter the password:";
    cin >> password;
    bool Upper = false;
    bool Lower = false;
    bool Digit = false;
    for (int i = 0; i < password.length(); i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            Upper = true;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            Lower = true;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            Digit = true;
        }
    }
    if (Upper && Lower && Digit)
    {
        cout << "STRONG";
    }
    else
    {
        cout << "WEAK";
    }
    return 0;
}