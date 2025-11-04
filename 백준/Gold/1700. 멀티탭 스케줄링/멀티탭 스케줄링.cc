#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    FAST_IO
    int n, k, temp, cnt = 0;
    cin >> n >> k;
    vector<int> arr(k);
    for(int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    vector<int> plug;

    for(int i = 0; i < k; i++)
    {
        bool pluged = false;
        for(int ace : plug)
        {
            if(ace == arr[i])
            {
                pluged = true;
                break;
            }
        }
        if(pluged) continue;
        if(plug.size() < n)
        {
            plug.push_back(arr[i]);
            continue;
        } 
        
        int idx = -1; int far = -1;
        for(int j = 0; j < plug.size(); j++)
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
        plug[idx] = arr[i];
        cnt++;
    }
cout << cnt;
}