#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    int temp = 0;
    for(int i = left; i <= right; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(i % j == 0)
            {
                temp++;
            }

        }
            if(temp % 2 == 0)
            {
               answer += i; 
            }
            else if(temp % 2 == 1)
            {
                answer -= i;
            }
            temp = 0;
    }
    
    return answer;
}