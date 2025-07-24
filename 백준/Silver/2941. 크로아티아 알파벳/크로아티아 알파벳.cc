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
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define INF 1e9+10 
using namespace std;

int main() {
    FAST_IO;
    string str;
    cin >> str;
    int count = 0;
    vector<string> croatianletters = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    for (string pat : croatianletters) {
        size_t pos;
        while ((pos = str.find(pat)) != string::npos) {
            str.replace(pos, pat.size(), "#");  // 아무 1글자로 대체
        }
    }

    cout << str.size();  // 최종 글자 수 출력

}