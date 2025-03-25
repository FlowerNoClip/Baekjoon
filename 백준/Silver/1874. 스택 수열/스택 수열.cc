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
    vector<string> result; // ✅ 결과 저장용 벡터

    for (int i = 0; i < N; i++) {
        while (num <= arr[i]) { 
            st.push(num++);
            result.push_back("+"); // ✅ 연산 저장
        }

        if (!st.empty() && st.top() == arr[i]) {
            st.pop();
            result.push_back("-"); // ✅ 연산 저장
        } 
        else {
            cout << "NO\n"; // ❌ 불가능한 경우 즉시 종료
            return 0;
        }
    }

    // ✅ 최종적으로 한 번에 출력
    for (const string& op : result) {
        cout << op << "\n";
    }

    return 0;
}
