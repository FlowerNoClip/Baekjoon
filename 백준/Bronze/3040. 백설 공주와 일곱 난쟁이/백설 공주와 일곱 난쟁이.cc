#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector <int> s(9,0);
    int sum = 0;
    int tempi, tempj;
   
    for (int i = 0; i < s.size(); i++) {
        cin >> s[i];
        sum += s[i];
    }
    
   
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            int temp = s[i] + s[j];
            if (sum - temp == 100) {
                tempi = i;
                tempj = j;
            }
        }
    }
    s.erase(s.begin() + tempi);
    s.erase(s.begin() + tempj);

    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << endl;
    }
    

    

    }



