#include <iostream>
#include <unordered_map>
#include <queue>
#include <cctype>
#include <string>
using namespace std;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M; cin >> N >> M;
    string temp;
    unordered_map<string, int> nameToNum; 
    unordered_map<int, string> numToName;

    for (int i = 1; i <= N; i++) {
        cin >> temp;
        nameToNum[temp] = i;  
        numToName[i] = temp;
    }

    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (isdigit(temp[0])) { 
            int num = stoi(temp);
            cout << numToName[num] << "\n"; 
        }
        else { 
            cout << nameToNum[temp] << "\n"; 
        }
    }


}