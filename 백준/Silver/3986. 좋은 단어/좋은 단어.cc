#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

int main()
{
    FAST_IO;
    int N; cin >> N;
    vector<string> v(N);
    
    for(string& s: v)
    {
        cin >> s;
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        stack<char> st;
        for (char c : v[i]) 
        {
            if (!st.empty() && st.top() == c) st.pop();
            else st.push(c);
        }
        if (st.empty()) cnt++; 
    }

    cout << cnt << endl;
}