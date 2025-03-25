#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin >> T;
    stack<int> st;
    int temp;
    while (T--)
    {
        cin >> temp;

        if (temp != 0 )
        {
            st.push(temp);
        }
        else if (!st.empty() && temp == 0)
        {
            st.pop();
        }
    }
    int answer = 0;
    while (!st.empty())
    {
        answer += st.top();
        st.pop();
    }

    cout << answer << endl;
    
    
}
