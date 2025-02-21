#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
    int DP[12];
    DP[0] = 1;
    DP[1] = 2;
    DP[2] = 4;
    
    for(int i=3; i < 12; i++)
        {
            DP[i] = DP[i-3]+DP[i-2]+DP[i-1];
        }

    while(T--)
    {
        int N;
        cin >> N;
        cout << DP[N-1] << endl;
    }
	

	



	


}