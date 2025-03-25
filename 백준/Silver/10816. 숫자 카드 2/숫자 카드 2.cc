#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_map<int, int> map;
    int N, M; cin >> N;

    while (N--)
    {
        int num;
        cin >> num;
        map[num]++;
    }

    cin >> M;

    while (M--)
    {
        int num;
        cin >> num;
        cout << map[num] << " ";
    }

    cout << "\n";
  
}
