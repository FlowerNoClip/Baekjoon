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
    int dial[26] = {
            3, 3, 3,      // A B C
            4, 4, 4,      // D E F
            5, 5, 5,      // G H I
            6, 6, 6,      // J K L
            7, 7, 7,      // M N O
            8, 8, 8, 8,   // P Q R S
            9, 9, 9,      // T U V
            10, 10, 10, 10// W X Y Z
        };

        string str;
        cin >> str;

        int answer = 0;
        for (char c : str) 
        {
            answer += dial[c - 'A'];
        }

        cout << answer;
}