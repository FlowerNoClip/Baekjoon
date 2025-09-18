#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    FAST_IO
    int H, W;cin >> H >> W;
    vector<vector<int>> arr(H, vector<int>(W));
    for(int i = 0; i < H; i++)
    {
        string s; cin >> s;
        bool flag = false;
        int flagNum = 0;
        for(int j = 0; j < s.length(); j++)
        {
            if(s[j] == '.' && !flag) 
            {
                arr[i][j] = -1;
            }
            else if(s[j] == 'c' && !flag)
            {
                arr[i][j] = 0;
                flag = true;
                flagNum = 1;
            } 
            else if(s[j] == 'c' && flag)
            {
                arr[i][j] = 0;
                flagNum = 1;
            }
            else if(s[j] == '.' && flag)
            {
                arr[i][j] = flagNum;
                flagNum++;
            }
        }
    }
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] <<' ';
        }
        cout << '\n';
    }
}