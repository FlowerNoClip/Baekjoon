#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void sol(int x, int y, vector<vector <char>>& S, int N) {
    if (N == 1) { 
        S[x][y] = '*'; 
        return; }
    else {
        int trio = N / 3;
        sol(x, y, S, trio);
        sol(x + trio, y, S, trio);
        sol(x + trio * 2, y, S, trio);        
        sol(x, y + trio, S, trio);
        sol(x + trio * 2, y + trio, S, trio);
        sol(x, y + trio * 2, S, trio);
        sol(x + trio, y + trio * 2, S, trio);
        sol(x + trio * 2, y + trio * 2, S, trio);      
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;


    vector <vector <char>> S(N, vector <char>(N));


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            S[i][j] = ' ';
        }
    }

    sol(0, 0, S, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << S[i][j];
        }
        cout << endl;
    }

    return 0;
}