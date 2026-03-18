#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

bool isTrue(char c)
{
    return c == 40 || c == 41 || c == 91 || c == 93;
}

int main()
{
    FAST_IO
    while (true)
    {
        string str;
        getline(cin, str);
        if (str == ".") return 0;
        stack<char> st;
        for (int i = 0; i < str.length(); i++)
        {
            if (st.empty() && isTrue(str[i]))
            {
                st.push(str[i]);
            }
            else if (!st.empty() && isTrue(str[i]))
            {
                if (str[i] != st.top())
                {
                    if (st.top() == '(' && str[i] == 41)
                    {
                        st.pop();
                    }
                    else if (st.top() == '[' && str[i] == 93)
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(str[i]);
                    }
                }
                else // str[i] == st.top() 인 경우
                {
                    st.push(str[i]);
                }
            }
        } // for문 끝

        if (st.empty())
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }
    }
} 