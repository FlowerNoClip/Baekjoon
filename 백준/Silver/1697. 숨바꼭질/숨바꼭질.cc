#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int bfs(int start, int end) {
    vector<bool> visited(100001, false);
    queue<pair<int, int>> q;
    q.push({ start, 0 });

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();
        int current = node.first;
        int depth = node.second;

        if (current == end)
        {
            return depth;
        }

        int move[] = { current + 1, current - 1, current * 2 };

        for (int a : move)
        {
            if (a >= 0 && a <= 100001 && !visited[a])
            {
                visited[a] = true;
                q.push({ a, depth + 1 });
            }
        }
    }


    return -1; // 도달할 수 없는 경우
}

int main() {
    int N, M;
    cin >> N >> M;

    cout << bfs(N, M) << endl;

    return 0;
}