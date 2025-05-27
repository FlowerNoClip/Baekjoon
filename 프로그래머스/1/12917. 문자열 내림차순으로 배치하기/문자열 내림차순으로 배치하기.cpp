#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string ustring = "";
    for(int i = 0 ; i < s.length(); i++)
    {
        if ('a' <= s[i] && s[i] <= 'z') {
            answer += s[i];
        }
        else if ('A' <= s[i] && s[i] <= 'Z') 
        {
            ustring += s[i];
        }
        if(!answer.empty())
        {
            sort(answer.begin(), answer.end(),greater<char>());
        }
        if(!ustring.empty())
        {
            sort(ustring.begin(), ustring.end(),greater<char>());
        }
        
            
    }
    return answer+ustring;
}