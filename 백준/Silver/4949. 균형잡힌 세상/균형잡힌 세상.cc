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
    string temp;
    
    while (true)
    {
        getline(cin, temp);
        stack<char> st;
        bool isValid = true;
        if (temp == ".") break;
        for (char v : temp)
        {
            if (v == '(')
            {
                st.push('(');
            }
            else if (v == '[')
            {
                st.push('[');
            }
            if (v == ')')
            {
                if (st.empty() || st.top() != '(')
                {
                    isValid = false;
                    break;
                }
                    st.pop();
            }
            if (v == ']')
            {
                if (st.empty() || st.top() != '[')
                {
                    isValid = false;
                    break;
                }
                    st.pop();
            }
            
        }

        if (isValid && st.empty())
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }

    }
    // 스택 제일 위에 있는 괄호가 현재 괄호과 매치가 된다면 pop.
    // 스택이 비어있으면 YES 안비어있으면 NO
    
}
