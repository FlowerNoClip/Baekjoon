#include<bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
int a[9];
int n = 9, r = 7;
void solved()
{
    int sum = 0;
    for(int i = 0; i < r; i++)
    {
        sum += a[i];
    }

    if(sum == 100)
    {
        sort(a,a+7);
        for(int i = 0; i < r; i++) cout << a[i] << "\n";
        exit(0);
    }
}
void makePermutation(int n, int r, int depth)
{
    if(depth == r)
    {
        solved();
        return;
    }
    

    for(int i = depth; i < n; i++)
    {
        swap(a[i], a[depth]);
        makePermutation(n,r,depth+1);
        swap(a[i], a[depth]);        
    }
}
int main()
{
    FAST_IO;
    
    for(int i = 0; i < 9; i++)
    {
        int temp;
        cin >> a[i];
    }

    makePermutation(n, r, 0);
}