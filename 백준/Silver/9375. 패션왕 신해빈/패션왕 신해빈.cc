#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int fac(int n)
{
    if(n == 1 || n == 0)
    {
        return 1;
    }
    return n * fac(n-1); 
}
int main()
{
    FAST_IO
    int N, M; cin >> N;
    
    
    while(N--)
    {
        unordered_map<string, int> cloths;
        cin >> M;
        int sum = 1;
        string str;
        for(int i = 0; i < M; i++)
        {
            string item, cate;
            cin >> item >> cate;
            cloths[cate]++;
        }

        for(auto& pair : cloths)
        {
            string key = pair.first;
            int value = pair.second;
            sum *= (value + 1);
        }
        cout << sum-1 << '\n';
    }
    

}