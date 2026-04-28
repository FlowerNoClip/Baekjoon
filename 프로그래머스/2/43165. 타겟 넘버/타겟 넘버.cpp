#include <bits/stdc++.h>
using namespace std;
int answer = 0;

int dfs(vector<int> numbers, int target, int depth, int sum){   
    if(depth == numbers.size())
    {
        if(sum == target) return 1;
        
        return 0;
    }
    
    int plus = dfs(numbers, target, depth+1, sum + numbers[depth]);
    int minus = dfs(numbers, target, depth+1, sum - numbers[depth]);
    
    
    return plus + minus;
}
int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 0);
}