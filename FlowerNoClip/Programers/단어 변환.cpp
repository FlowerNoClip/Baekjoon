#include <bits/stdc++.h>
using namespace std;

bool isValid(const string &a, const string &b)
{
    int cnt = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            cnt++;
            if (cnt > 1) return false;
        }
    }

    return cnt == 1;
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    if(find(words.begin(), words.end(), target) == words.end())
    {
        return 0;
    }
    vector<bool> visited(words.size(), false);
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    while(!q.empty())
    {
        string cur = q.front().first;
        int next = q.front().second;
        q.pop();
        
        if(cur == target)
        {
            return next;
        }
        
        for(int i = 0; i < words.size(); i++)
        {
            if(!visited[i] && isValid(cur, words[i]))
            {
                visited[i] = true;
                q.push({words[i], next + 1});
            }
        }
        
    }
    return 0;
}