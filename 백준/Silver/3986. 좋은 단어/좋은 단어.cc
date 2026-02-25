#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    FAST_IO
    
    string s;
    int N; cin >> N;
    
    int cnt = 0;
    while(N--)
    {
        cin >> s;
        stack<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(st.top() == s[i])
            {
                st.pop();
            }
            else if(st.top() != s[i])
            {
                st.push(s[i]);
            }
            
        }
        if(st.empty())
        {
            cnt++;
        }

    }
    
    
    cout << cnt << '\n';



}