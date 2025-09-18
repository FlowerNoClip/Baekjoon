#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
string vowels = "aeiou";
const string nnn =  " is not acceptable.";
const string yes =  " is acceptable.";
string a;
bool isVowel(char c) {
    return vowels.find(c) != string::npos;
}
bool first(string str)
{
    if (str.find_first_of(vowels) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool second(string str)
{
    char temp = ' ';
    int cnt = 0;
    for(char& a : str)
    {
        if(temp != a)
        {
            temp = a;
            cnt = 0;
        }
        if(temp == a)
        {
            cnt++;
        }
        if(cnt >= 2 && temp != 'e' && temp != 'o')
        {
            return false;
        }
    }
    
    return true;
    
}
bool check(string s) {
    int cnt = 1;
    for (int i = 1; i < s.size(); i++) {
        if ((isVowel(s[i]) && isVowel(s[i-1])) ||
            (!isVowel(s[i]) && !isVowel(s[i-1]))) {
            cnt++;
        } else {
            cnt = 1;
        }
        if (cnt >= 3) return false;
    }
    return true;
}
void text(bool _isYN)
{
    if(_isYN)
    {
        cout << '<' << a << '>' << yes<<'\n';
    }
    else
    {
        cout << '<' << a << '>' << nnn <<'\n';
    }
}
int main()
{
    FAST_IO
    while(true)
    {
        cin >> a;
        
        if (a == "end")
        {
            break;
        }
        if(!first(a))
        {
            text(false);
            continue;
        }
        if(!second(a))
        {
            text(false);
            continue;
        }
        if(!check(a))
        {
            text(false);
            continue;
        }

        text(true);

        
    }
}