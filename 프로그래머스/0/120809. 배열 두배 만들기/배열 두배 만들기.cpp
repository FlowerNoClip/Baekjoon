#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer = numbers;
    for(int i = 0; i < answer.size(); i++)
    {
        answer[i] *= 2;
    }
    return answer;
}