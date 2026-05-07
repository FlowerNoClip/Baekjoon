#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FAST_IO
    int N, M;
    cin >> N >> M;

    vector<int> c(N);
    vector<int> nc(N);
    for(int i = 0; i < N; i++)
    {
        cin >> c[i];
    }
    for(int i = 0; i < M; i++)
    {
        cin >> nc[i];
    }

    //sort(nc.begin(), nc.end());
    sort(c.begin(), c.end());
    // 1 2 3 5 8
    int temp = M;
    bool flag = false;
    for(int i = 0; i < M; i++)
    {
       int idx = lower_bound(c.begin(), c.end(), nc[i]) - c.begin();
        //cout << idx << endl;
        //cout << nc[i] << " " << c[idx] << endl;
        if(c[idx] != nc[i])
        {
            cout << nc[i] << ' ';
            flag = true;
        }
        else
        {
            continue;
        }
    }

    if(!flag)
    {
        cout << "-1" << endl;
    }
    return 0;
}