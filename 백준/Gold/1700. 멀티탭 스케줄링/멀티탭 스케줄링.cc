#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n, k;
int main()
{
    FAST_IO
    cin >> n >> k;
    vector<int> arr(k);
    vector<int> plug;
    int cnt = 0;
    for(int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < k; i++)
    {
        int x = arr[i];
        bool pluged = false;
        
        for(int j : plug)
        {
            if(j == x)
            {
                pluged = true;
                break;
            } 
        } 
        if(pluged) continue;

        if ((int)plug.size() < n)
        {
            plug.push_back(x);
            continue;
        }
        int idx = -1, far = -1;
        for(int j = 0; j < n; j++)
        {
            int next = -1;
            for(int t = i+1; t < k; t++)
            {
                if(arr[t] == plug[j])
                {
                    next = t;
                    break;
                }
            }
            if(next == -1) {idx = j; break;}
            if(next > far)
            {
                far = next;
                idx = j;
            }
        }
        plug[idx] = x;
        cnt++;
    }
    cout << cnt; 
}
