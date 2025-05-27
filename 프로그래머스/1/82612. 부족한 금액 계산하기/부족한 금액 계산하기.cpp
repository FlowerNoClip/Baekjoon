#include <cmath>

using namespace std;

long long solution(int price, int money, int count)
{
    long long temp = 0;
    for(int i = 1; i <= count; i++)
    {
        temp += price * i;
        
    }
    if(temp < money)
    {
        return 0;
    }
    else
    {
        return abs(money-temp);
    }
    //count = 승수
    //price = 수
    //result = 반환 값
    // money = 소지금
    
}