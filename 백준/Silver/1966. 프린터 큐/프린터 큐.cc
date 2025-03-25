#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin >> T;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        int num;
        for (int i = 0; i < N; i++)
        {
            cin >> num;
            pq.push(num);
            q.push({ i, num });
        }
        int cnt = 0;
        while (!q.empty())
        {
            int currentIndex = q.front().first;
            int currentPriority = q.front().second;
            q.pop();

            if (currentPriority == pq.top())
            {
                cnt++;
                pq.pop();
                if (currentIndex == M)
                {
                    cout<< cnt << endl;
                }
            }
            else
            {
                q.push({ currentIndex, currentPriority });
            }
        }

    }


    return 0;
}
