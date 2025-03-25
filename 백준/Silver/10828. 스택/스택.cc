#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    stack<int> st;
    
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
            st.push(num);
        }
        else if (op == "pop") {
            if (st.empty()) cout << -1 << '\n';
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (op == "size") {
            cout << st.size() << '\n';
        }
        else if (op == "empty") {
            cout << (st.empty() ? 1 : 0) << '\n';
        }
        else if (op == "top") {
            if (st.empty()) cout << -1 << '\n';
            else cout << st.top() << '\n';
        }
    }
    return 0;
}