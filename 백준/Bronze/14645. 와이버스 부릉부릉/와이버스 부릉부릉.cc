#include <iostream>
#include <vector>

using namespace std;


int main() {
    int N, K;
    cin >> N >> K;
    
    
    vector<vector<int>> arr(N, vector<int>(K));
    for(int i = 0; i < N; i ++)
    {
        for(int j = 0 ; j < K; j++)
            {
                cin >> arr[i][j];
            }
    }

    cout << "비와이" << endl;
    return 0;
}