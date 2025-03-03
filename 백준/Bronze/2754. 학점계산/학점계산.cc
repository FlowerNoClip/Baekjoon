#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string sol;
    cin >> sol;
    if (sol[0] == 'A')
    {
        if (sol[1] == '+')
        {
            cout << "4.3";
        }
        else if (sol[1] == '0')
        {
            cout << "4.0";
        }
        else if (sol[1] == '-')
        {
            cout << "3.7";
        }
    }
    else if (sol[0] == 'B')
    {
        if (sol[1] == '+')
        {
            cout << "3.3";
        }
        else if (sol[1] == '0')
        {
            cout << "3.0";
        }
        else if (sol[1] == '-')
        {
            cout << "2.7";
        }
    }
    else if (sol[0] == 'C')
    {
        if (sol[1] == '+')
        {
            cout << "2.3";
        }
        else if (sol[1] == '0')
        {
            cout << "2.0";
        }
        else if (sol[1] == '-')
        {
            cout << "1.7";
        }
    }
    else if (sol[0] == 'D')
    {
        if (sol[1] == '+')
        {
            cout << "1.3";
        }
        else if (sol[1] == '0')
        {
            cout << "1.0";
        }
        else if (sol[1] == '-')
        {
            cout << "0.7";
        }
    }
    else
    {
        cout << "0.0";
    }


}
