#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T; cin >> T;
    string temp;
    
    while (T--)
    {
        cin >> temp;
        stack<char> st;
        bool isValid = true;

        for (char ch : temp)
        {
            if (ch == '(')
            {
                st.push('(');
            }
            else if (ch == ')')
            {
                if (st.empty())
                {
                    isValid = false;
                    break;
                }
                st.pop();
            }
        }

        if (isValid && st.empty())
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }

    }
}
