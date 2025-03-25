#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    stack<int> st;
    int num = 1;
    vector<string> result;

    for (int i = 0; i < N; i++) {
        while (num <= arr[i]) {
            st.push(num++);
            result.push_back("+");
        }

        if (!st.empty() && st.top() == arr[i]) {
            st.pop();
            result.push_back("-");
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }
    for (const string& op : result) {
        cout << op << "\n";
    }

    return 0;
}
