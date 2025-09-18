#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

string vowels = "aeiou";

bool isVowel(char c) {
    return vowels.find(c) != string::npos;
}

bool hasVowel(const string& str) {
    for (char c : str) if (isVowel(c)) return true;
    return false;
}

bool noDoubleExceptEO(const string& str) {
    for (int i = 1; i < (int)str.size(); i++) {
        if (str[i] == str[i-1] && str[i] != 'e' && str[i] != 'o') {
            return false;
        }
    }
    return true;
}

bool noThreeConsecutive(const string& str) {
    int cnt = 1;
    for (int i = 1; i < (int)str.size(); i++) {
        if ((isVowel(str[i]) && isVowel(str[i-1])) ||
            (!isVowel(str[i]) && !isVowel(str[i-1]))) {
            cnt++;
        } else {
            cnt = 1;
        }
        if (cnt >= 3) return false;
    }
    return true;
}

void printResult(const string& word, bool ok) {
    cout << '<' << word << '>' 
         << (ok ? " is acceptable." : " is not acceptable.") 
         << '\n';
}

int main() {
    FAST_IO
    string word;
    while (cin >> word) {
        if (word == "end") break;

        bool ok = hasVowel(word) && noDoubleExceptEO(word) && noThreeConsecutive(word);
        printResult(word, ok);
    }
}
