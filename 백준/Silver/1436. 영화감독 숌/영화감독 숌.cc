#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    FAST_IO
    int N;
    cin >> N;
    long long num = 666;
    int i = 1;
    string temp;
    while(true)
    {
        if(i == N) 
        {
            cout << num << '\n';
            return 0;
        }
        num += 1;
        temp = to_string(num);
        if (temp.find("666") != string::npos) {
            i++;
        }
        
    }
}