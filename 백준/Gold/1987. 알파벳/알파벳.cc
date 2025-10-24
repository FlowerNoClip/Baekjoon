#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, m, bestlen;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
bool used[26];
void dfs(int sy, int sx, vector<string>& a, int depth)
{
    bestlen = max(bestlen, depth);

    for(int d = 0; d < 4; d++)
    {
        int ny = sy + dy[d];
        int nx = sx + dx[d]; 
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        int ch = a[ny][nx] - 'A';
        if(used[ch]) continue;

        used[ch]= true;
        dfs(ny, nx, a, depth+1);
        used[ch]= false;
    }
}
int main()
{
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    memset(used, 0, sizeof(used));
    used[a[0][0] - 'A'] = true;
    dfs(0, 0, a, 1);


    cout << bestlen << endl;
}