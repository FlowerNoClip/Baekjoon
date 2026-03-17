#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    FAST_IO
    int N,M; cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M, -1));
    vector<vector<bool>> vistied(N, vector<bool>(M));
    for(int i = 0; i < N; i++)
    {
        string temp; cin >> temp;
        int cP = -1;
        for(int j = 0; j < M; j++)
        {
            if(temp[j] == 'c') cP = j;
            if(cP != -1) board[i][j] = j - cP;
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {

            cout <<board[i][j] << " ";
        }
        cout << '\n';
    }
}