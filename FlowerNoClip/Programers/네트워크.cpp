#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};
void bfs(int idx, vector<bool>& visited, vector<vector<int>> adj)
{
    queue<int> q;
    q.push(idx);
    visited[idx] = 1;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        
        for(int i = 0; i < adj.size(); i++)
        {
            if(!visited[i] && adj[now][i] == 1)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visited(computers.size());
    for(int i = 0; i < computers.size(); i++)
    {    
            if(!visited[i])
            {
                bfs(i,visited, computers);
                answer++;
            }
    }
    return answer;
}