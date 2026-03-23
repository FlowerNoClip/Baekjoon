#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
vector<vector<int>> board;
vector<vector<int>> chicken;
vector<pair<int, int>> sV, hV;          
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};
int shopCount = 0;
int maxNum = -1;
int N, M;
int res = 1e9; 

void DeleteShop(int a, vector<int>& v)
{
    if(v.size() == M)
    {
        chicken.push_back(v);
        return;
    };

    for(int i = a+1; i < sV.size(); i++)
    {
        v.push_back(i);
        DeleteShop(i, v);
        v.pop_back();
    }
    return;
}
int main()
{
    FAST_IO
    // M개를 폐업 시키기
    // maxNum = 0; 각 치킨의 거리를 계산 ret += (r-c) + (cr + cc) = ?
    // maxNum = max(ret, maxNum)
    // 결론은 M개의 치킨집을 폐업 시켰을때, 남은 치킨집으로 가장 최단거리를 찾는거

    cin >> N >> M;
    board.assign(N, vector<int>(N));
    
    for(int i = 0; i < N; i++)
    {
        for(int j  = 0; j < N; j++)
        {
            cin >> board[i][j];
            if(board[i][j] == 1)
            {
                hV.push_back({i,j});
            }
            if(board[i][j] == 2)
            {
                sV.push_back({i,j});
            }
        }
    }
    vector<int> v;
    DeleteShop(-1, v);
    for(vector<int> cL : chicken)
    {
        int ret = 0;
        for(pair<int, int> home : hV)
        {
            int minNum = 1e9;
            for(int c : cL)
            {
                int dist = abs(home.first - sV[c].first) + abs(home.second - sV[c].second);
                minNum = min(minNum, dist);
            }
            ret += minNum;
        }
        res = min(res, ret);
    }

    cout << res << endl;
    
}