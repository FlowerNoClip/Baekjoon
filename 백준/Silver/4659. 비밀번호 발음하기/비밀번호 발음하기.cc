#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
bool isHaveMo(string temp)
{
    for(char c : temp)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c=='u')
        {
            return true;
        }
    }
    return false;
}
bool isTriple(string temp)
{
   for(int i = 1; i < temp.length(); i++)
   {
        if(temp[i] == temp[i-1])
        {
            if(temp[i] != 'e' && temp[i] != 'o')
            {
                return false;
            } 
        }    
    }
   return true;   
}

bool isSequence(string temp)
{
    int s = 0;
    int mos = 0;
    for(char c : temp)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c=='u')
        {
            s = 0;
            mos++;
        }
        else
        {
            mos = 0;
            s++;
        }

        if(mos >= 3 || s >= 3)
        return false;
    }
    return true;
}
int main()
{
    
    FAST_IO
    /*
        1. 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
        2. 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
        3. 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
    */
   //모음이 한개라도 존재 하는지 ? 
   while(true)
   {
        string temp; cin >> temp;
        if(temp == "end") return 0;
        if(isHaveMo(temp) && isSequence(temp) && isTriple(temp))
        {
            
            cout << "<" << temp << "> " << "is " << "acceptable." <<'\n';
        }          
        else
        {
            cout << "<" << temp << "> " << "is " << "not " << "acceptable." <<'\n';
        }
   }
}