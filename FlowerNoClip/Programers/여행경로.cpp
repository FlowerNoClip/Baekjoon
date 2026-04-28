#include <bits/stdc++.h>

using namespace std;
int isFull = false;
void dfs(vector<vector<string>> &tickets,vector<bool> &visited, vector<string> &answer, string start, int depth)
{
    answer.push_back(start);
    if(tickets.size() == depth)
    {
        isFull = true;
    }
    
    for(int i = 0; i < tickets.size(); i++)
    {
        if(!visited[i] && tickets[i][0] == start)
        {
            visited[i] = true;            
            dfs(tickets, visited, answer, tickets[i][1], depth+1);
            
            if(!isFull)
            {
                answer.pop_back();
                visited[i] = false;
            }
        }
    }

}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    vector<bool> visited(tickets.size(), false);
    dfs(tickets, visited, answer, "ICN", 0);
    return answer;
}