#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
int a[9];
int n = 9, r = 7;

int main()
{
    FAST_IO;
    
    for(int i = 0; i < 9; i++)
    {
        int temp;
        cin >> a[i];
    }
    sort(a, a+9);
    do
    {
        int sum = 0;
        for(int i = 0; i < r; i++)
        {
            sum += a[i];
        }

        if(sum == 100)
        {
            break;
        }
    } while (next_permutation(a, a+9));
    
    for(int i=0; i < r; i++)
    {
        cout << a[i] << '\n';
    }
}