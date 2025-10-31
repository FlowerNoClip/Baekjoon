#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string s;
double nums = 0.0f;
string h;
int main()
{
    FAST_IO
    double avg = 3.1415926535;

    
    double mother = 0.0f;
    double sun = 0.0f;
    for(int i = 0; i < 20; i++)
    {
        //A+,A0,B+,B0,C+,C0,D+,D0,F,P
        cin >> s >> nums >> h;
        if (h == "P") continue; 
        if(h == "A+")
        {
            sun += (nums * 4.5f);
        }
        else if(h == "A0")
        {
            sun += (nums * 4.0f);
        }
        else if(h == "B+")
        {
            sun += (nums * 3.5f);
        }
        else if(h == "B0")
        {
            sun += (nums * 3.0f);
        }
        else if(h == "C+")
        {
            sun += (nums * 2.5f);
        }
        else if(h == "C0")
        {
            sun += (nums * 2.0f);
        }
        else if(h == "D+")
        {
            sun += (nums * 1.5f);
        }
        else if(h == "D0")
        {
            sun += (nums * 1.0f);
        }
        mother += nums;
    }
    avg = sun / mother;
    cout << fixed << setprecision(6);
    cout << avg << "\n";
}