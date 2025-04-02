#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#define ll long long
#define INF 1e9+10
using namespace std;
int board[502][502];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    vector<int> arr(N);
    map<int, int> compressed;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    vector<int> sortedArr = arr; 
    sort(sortedArr.begin(), sortedArr.end());
    int index = 0;
    for (int num : sortedArr) {
        if (compressed.find(num) == compressed.end()) {
            compressed[num] = index++;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << compressed[arr[i]] << " ";
    }
}