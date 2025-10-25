#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    FAST_IO;
    vector<vector<char>> a(5, vector<char>(15, '*'));
    for(int i = 0; i < 5; i++)
    {
        string temp; cin >> temp;
        for(int j = 0; j < temp.length(); j++)
        {
            if(temp[j] != NULL)
            {
                a[i][j] = temp[j];
            }
        }
    }
    for(int j = 0; j < 15; j++)
    {
        for(int i = 0; i < 5; i++)
        {
            if(a[i][j] != '*')
            {
                cout << a[i][j];
            }
        }
    }


}