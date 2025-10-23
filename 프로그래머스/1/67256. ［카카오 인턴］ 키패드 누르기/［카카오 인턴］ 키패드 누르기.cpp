#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftPos = 10;
    int rightPos = 12;
    for(int num : numbers)
    {
        if(num == 1 || num == 4 || num == 7)
        {
            answer += "L";
            leftPos = num;
        }
        else if(num == 3 || num == 6 || num == 9)
        {
            answer +="R";
            rightPos = num;
        }
        else 
        {
            if(num == 0) num = 11;
            int leftDistance = abs((leftPos - num) / 3) + abs((leftPos - num) % 3);
            int rightDistance = abs((rightPos - num) / 3) + abs((rightPos - num) % 3);
            if(leftDistance < rightDistance) 
            {
                leftPos = num;
                answer += 'L';
            }   
            else if(rightDistance == leftDistance)
            {
                if(hand=="right")
                {
                    rightPos = num;
                    answer += 'R';
                }
                else
                {
                    answer += 'L';
                    leftPos = num;
                }
            }
            else
            {
                rightPos = num;
                answer += 'R';
            }
        }
    }
    return answer;
}