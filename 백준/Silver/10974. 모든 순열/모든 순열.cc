#include <bits/stdc++.h>
#define FAST_IO cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
using namespace std;
int main()
{
    FAST_IO
    /*
        1. 입력받기 # 완
        2. 받은 값을 오름차순으로 배열에 넣기 # 
        3. 배열에 넣은값을 순열 출력하기 
    */
    int N;
    cin >> N;
    vector<int> v;
    
    for(int i = 1; i <= N; i++)
    {
        v.push_back(i);  
    }
    do{
        for(int i = 0; i < N; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }while(next_permutation(v.begin(), v.end()));
}