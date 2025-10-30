#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m, words[51];
string s;
int count(int mask)
{
    int cnt = 0;
    for(int word : words)
    {
        if(word && (mask & word) == word) cnt++;
    }
    return cnt;
}
int go(int index, int k, int mask)
{
    if(k < 0) return 0;
    if(index == 26) return count(mask);
    int ret = go(index + 1, k -1, mask | (1 << index));
    if (index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a')
    {
        ret = max(ret, go(index + 1, k, mask));
    }

    return ret;
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        for(char str : s)
        {
            words[i] |= (1 << (str - 'a'));
        }
    }

    cout << go(0, m, 0) << endl;
}