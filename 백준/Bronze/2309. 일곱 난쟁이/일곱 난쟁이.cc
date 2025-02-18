#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector <int> spy;
    vector <int> heights(9);
    vector <int> real;

    int heightSum = 0;
    
    for (int i = 0; i < heights.size(); i++) {
        cin >> heights[i];
        heightSum += heights[i];
    }

    bool found = false;
    for (int i = 0; i < 9 && !found; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (heightSum - heights[i] - heights[j] == 100) {
                heights[i] = heights[j] = -1;  // 제외할 난쟁이를 -1로 표시
                found = true;  // 두 명의 스파이를 찾으면 반복 종료
                break;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (heights[i] != -1) {
            real.push_back(heights[i]);
        }
    }


    
    sort(real.begin(),real.end());
    for (int i = 0; i < real.size(); i++) {
        cout << real[i] << endl;
    }
    
}