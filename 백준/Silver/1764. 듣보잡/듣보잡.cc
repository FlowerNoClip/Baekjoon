#include <iostream>
#include <unordered_map>
#include <queue>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M; cin >> N >> M;
    unordered_map<string, int> map;
    vector<string> arr;
    string temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        map[temp]++;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    for (auto& v : arr)
    {
        map[v]--;
    }

    vector<string> answer;
    for (auto& v : map) {
        if (v.second == 0) {
            answer.push_back(v.first);
        }
    }
    sort(answer.begin(), answer.end());

    cout << answer.size() << endl;

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << endl;
    }


}