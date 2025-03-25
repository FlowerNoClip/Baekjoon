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
    queue<int> q;
    
    int T;
    cin >> T;
    cin.ignore();

    while (T--)
    {
        string temp;
        getline(cin, temp);
        stringstream ss(temp);
        string op;
        ss >> op;

        if (op == "push") {
            int num;
            ss >> num;
            q.push(num);
        }
        else if (op == "pop") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (op == "size") {
            cout << q.size() << '\n';
        }
        else if (op == "empty") {
            cout << (q.empty() ? 1 : 0) << '\n';
        }
        else if (op == "front") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if (op == "back") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }
    return 0;
}