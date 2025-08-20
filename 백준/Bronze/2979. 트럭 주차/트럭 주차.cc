#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 

int main()
{
    FAST_IO;
    int A, B, C;
    cin >> A >> B >> C;
    vector<int> v(101, 0);
    int N = 3;
    int a, b; 
    int answer = 0;
    while(N--)
    {
        cin >> a >> b;

        for(int i = a; i < b; i++)
        {
            v[i]++;
        }
    }

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == 1)
        {
            answer += A;
        }
        else if(v[i] == 2)
        {
            answer += (B*2);
        }
        else if (v[i] == 3)
        {
            answer += (C*3);
        }
    }


    cout << answer;
}