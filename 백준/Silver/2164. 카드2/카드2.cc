#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N; cin >> N;
    queue<int> q;
    
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }

    while (q.size() > 1)
    {
        q.pop();
        int current = q.front();
        q.pop();
        q.push(current);
    }

    cout << q.front() << endl;
}
