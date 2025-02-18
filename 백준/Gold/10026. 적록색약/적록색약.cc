#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0 , 1, -1 };
int cnt = 0;
int N;
int rcnt = 0;
int gcnt = 0;
int bcnt = 0;
void dfs(int x, int y, char a, vector<vector<char>>& map, vector<vector<bool>>& visited) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if (map[nx][ny] == a && !visited[nx][ny]) {
                dfs(nx, ny, a,map, visited);
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    vector<vector<char>> map(N, vector<char>(N));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            map[i][j] = str[j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(!visited[i][j]){
                if (map[i][j] == 'R') {
                    rcnt++;
                    dfs(i, j, 'R', map, visited);
                    
                }
                else if (map[i][j] == 'G') {
                    gcnt++;
                    dfs(i, j, 'G', map, visited); 
                    
                }
                else if (map[i][j] == 'B') {
                    bcnt++;
                    dfs(i, j, 'B', map, visited);
                    
                }
            }
            
        }
    }
    cout << rcnt + gcnt + bcnt << " ";
    rcnt = 0;
    gcnt = 0;
    bcnt = 0;
    for (int i = 0; i < visited.size(); i++) {
        for (int j = 0; j < visited.size(); j++) {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'G') {
                map[i][j] = 'R';
        }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                if (map[i][j] == 'R') {
                    rcnt++;
                    dfs(i, j, 'R', map, visited);

                }
                else if (map[i][j] == 'G') {
                    gcnt++;
                    dfs(i, j, 'G', map, visited);

                }
                else if (map[i][j] == 'B') {
                    bcnt++;
                    dfs(i, j, 'B', map, visited);

                }
            }

        }
    }
    cout << rcnt + gcnt + bcnt << " ";
    //sort(v.begin(), v.end());
    //cout << v.size() << endl;

    //for (int i = 0; i < v.size(); i++) {
    //    cout << v[i] << endl;
    //}
    


}
