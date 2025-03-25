#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    vector<string> arr(T);

    for (int i = 0; i < T; i++) {
        cin >> arr[i];
    }


    sort(arr.begin(), arr.end());

    int cnt = 0;  
  
    for (int i = 0; i < T - 1; i++) {
        if (arr[i + 1].substr(0, arr[i].size()) == arr[i]) {
            cnt++; 
        }
    }

    cout << arr.size() - cnt << "\n";
    return 0;
}
