#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
#include <queue> 
#include <deque> 
#include <iterator> 
#include <list> 
#include <stack> 
#include <map> 
#include <unordered_map>
#include <set> 
#include <unordered_set>
#include <math.h> 
#define ll long long 
#define INF 1e9+10 
using namespace std;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
unordered_map<int, int> deleteMap;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while (T--)
    {
        int N; cin >> N;
        vector<pair<char, int>> commands(N);

        maxHeap = priority_queue<int>(); 
        minHeap = priority_queue<int, vector<int>, greater<int>>();
        deleteMap.clear();

        for (int i = 0; i < N; i++)
        {
            cin >> commands[i].first >> commands[i].second;
        }
        for (int i = 0; i < N; i++)
        {
            if (commands[i].first == 'I')
            {
                maxHeap.push(commands[i].second);
                minHeap.push(commands[i].second);
                if (deleteMap.count(commands[i].second) == 0)
                {
                    deleteMap[commands[i].second] = 1;
                }
                else
                {
                    deleteMap[commands[i].second]++;
                }
            }
            else if (commands[i].first == 'D')
            {
                if (commands[i].second == 1)
                {
                    while (!maxHeap.empty() && deleteMap[maxHeap.top()] == 0)
                    {
                        maxHeap.pop();
                    }
                    if (maxHeap.empty())
                    {
                        continue;
                    }

                    deleteMap[maxHeap.top()]--;
                    maxHeap.pop();
                }
                else if (commands[i].second == -1)
                {
                    while (!minHeap.empty() && deleteMap[minHeap.top()] == 0)
                    {
                        minHeap.pop();
                    }
                    if (minHeap.empty())
                    {
                        continue;
                    }

                    deleteMap[minHeap.top()]--;
                    minHeap.pop();
                }
            }
        }
        while (!maxHeap.empty() && deleteMap[maxHeap.top()] == 0)
        {
            maxHeap.pop();
        }
        while (!minHeap.empty() && deleteMap[minHeap.top()] == 0)
        {
            minHeap.pop();
        }
        if (minHeap.empty() || maxHeap.empty())
        {
            cout << "EMPTY" << endl;
        }
        else
        {
            cout << maxHeap.top() << " " << minHeap.top() << "\n";
            
        }
        
    }
    // I n : 정수 n을 q안에 삽입한다.
    // D 1 : 최대값 삭제
    // D -1 : 최소값 삭제
    // 연산 처리후 Q안에 남아있는 최대값과 최소값을 출력한다
    // Q가 비어있다면 "EMPTY" 를 출력


    
 
    
}