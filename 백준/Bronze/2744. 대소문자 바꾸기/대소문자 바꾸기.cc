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
    for (int i = 0; i < sol.size(); i++)
    {
        if (sol[i] >= 65 && sol[i] <= 90)
        {
            sol[i] += 32;
        }
        else if(sol[i] >= 97 && sol[i] <= 122)
        {
            sol[i] -= 32;
        }
        
    }
    cout << sol;

}
