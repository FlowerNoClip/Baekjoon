#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
using namespace std;

int main()
{
    int T; cin >> T;
    while(T--)
    {
        stack<char> st;
        string str; cin >> str;

        for(int i = 0; i < str.length(); i++)
        {
            if(st.empty())
            {
                st.push(str[i]);
            }
            else
            {
                if(str[i] != st.top())
                {
                    if(st.top() == ')')
                    {
                        st.push(str[i]);
                    }
                    else
                    {
                        st.pop();
                    }
                }
                else
                {
                    st.push(str[i]);
                    
                }
            }
        }
        if(st.empty())
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}