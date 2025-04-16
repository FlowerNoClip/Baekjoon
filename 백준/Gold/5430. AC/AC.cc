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
#include <unordered_map>
#include <set> 
#include <unordered_set>
#include <math.h> 
#define ll long long 
#define INF 1e9+10 
using namespace std;

deque<int> extractNumbers(const string& input) {
    deque<int> result;
    string temp;

    for (char c : input) {
        if (isdigit(c)) temp += c;
        else {
            if (!temp.empty()) {
                result.push_back(stoi(temp));
                temp.clear();
            }
        }
    }
    if (!temp.empty()) result.push_back(stoi(temp));

    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // R 뒤집기 : 배열에 있는 수의 순서를 뒤집는 함수
    // D 버리기 첫 번째 수를 버리는 함수
    int T; cin >> T;
    int N;
    deque<int> arr;
    string p;
    string str;
    string temp;
    while (T--)
    {
        cin >> p >> N >> str;
        arr.resize(N);
        arr = extractNumbers(str);

        bool isReversed = false;
        bool isError = false;

        for (int i = 0; i < p.length(); i++)
        {
            if (p[i] == 'R')
            {
                isReversed = !isReversed;
            }
            else if (p[i] == 'D') 
            {
                if (arr.empty()) 
                {
                    isError = true;
                    break;
                }
                if (!isReversed) 
                {
                    arr.pop_front();
                }
                else 
                {
                    arr.pop_back();
                }
            }
        }
        
        if (isError) {
            cout << "error\n";
        }
        else {
            cout << '[';
            if (!arr.empty()) {
                if (!isReversed) {
                    for (size_t i = 0; i < arr.size(); ++i) {
                        cout << arr[i];
                        if (i != arr.size() - 1) cout << ',';
                    }
                }
                else {
                    for (size_t i = arr.size(); i-- > 0;) {
                        cout << arr[i];
                        if (i != 0) cout << ',';
                    }
                }
            }
            cout << "]\n";
        }
    }
    
}