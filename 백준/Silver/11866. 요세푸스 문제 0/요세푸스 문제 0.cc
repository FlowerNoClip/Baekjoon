#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <sstream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M; cin >> N >> M;
    queue<int> q;
    
    for (int i = 1; i <= N; i++)
    {
            q.push(i);
    }
    int i = 1;
    cout << "<";
    while (!q.empty())
    {
        if (i % M == 0)
        {
            if (q.size() - 1 == 0)
            {
                cout << q.front();
                break;
            }
            cout << q.front()<<","<<" ";
            q.pop();
        }
        else
        {
            int num = q.front();
            q.pop();
            q.push(num);
        }
        i++;
    }
    cout << ">";
    return 0;
}