#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int num = 0;
    int max_cnt = 0;
    vector<int> count(1001, 0);
    
    for(int i = 0; i < array.size(); i++)
    {
        num = array[i];
        count[num]++;
    }
    
    for(int i = 0; i < count.size(); i++)
    {
        if(count[i] > max_cnt)
        {
            max_cnt = count[i];
            answer = i;
        }
        else if((!max_cnt == 0) && (count[i] == max_cnt))
        {
            answer = -1;
        }
        
    }
    return answer;
}