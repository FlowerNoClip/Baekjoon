#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int max = -1;
    int maxX, maxY;
    vector<vector <int>> A;
    vector<vector<int>> A2(9, vector<int>(9, 0));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> A2[i][j];
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (A2[i][j] > max) {
                max = A2[i][j];
                maxX = i + 1;
                maxY = j + 1;
            }
        }       
    }

    cout << max << endl << maxX << " " << maxY;

}
