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
    unordered_map<string, string> map;
    vector<string> arr;
    string temp;
    string password;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        cin >> password;
        map.insert({ temp,password });
        
    }
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    for (auto& v : arr)
    {
        cout << map[v]<<endl;
    }

  


}