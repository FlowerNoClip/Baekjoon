#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    FAST_IO
    int N, M, J; cin>> N >> M >> J;
    int cl = 1, cr = M, ret = 0;
    for(int i = 0; i < J; i++)
    {
        int apple; 
        cin >> apple;
        if(apple < cl)
        {
            int diff = cl - apple;
            ret += diff;
            cl-= diff;
            cr -= diff;
        }
        else if(apple > cr)
        {
            int diff = apple - cr;
            ret += diff;
            cl+=diff;
            cr+=diff;
        }
    }
    cout << ret;


}