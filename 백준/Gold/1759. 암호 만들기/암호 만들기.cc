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
int L, C;
vector<char> alpha;
vector<char> password;
bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
void func(int depth, int idx)
{
    if(depth == L)
    {   
        int vowel = 0, consonant = 0;
        for(char c : password)
        {
            if(isVowel(c)) vowel++;
            else consonant++;
        }
        if(vowel >= 1 && consonant >=2)
        {
            for(char c : password)
            {
                cout << c;
            }
        cout << "\n";
        }
        
        return;
    }

    for(int i = idx; i < C; i++)
    {
        password.push_back(alpha[i]);
        func(depth+1, i+1);
        password.pop_back();
    }
}
int main() {
    FAST_IO;
    cin >> L >> C;
    alpha.resize(C);
    for(char& a : alpha) cin >> a;
    sort(alpha.begin(), alpha.end());
    func(0, 0);
}