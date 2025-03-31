#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 입출력 비동기화 해제
    cin.tie(NULL);               // 입력과 출력을 묶지 않음

    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙
    int N;
    cin >> N;

    int temp = 0;
    while (N--)
    {
        cin >> temp;
        if (temp > 0)
        {
            pq.push(temp); // 양수라면 힙에 삽입
        }
        else if (temp == 0)
        {
            if (pq.empty())
            {
                cout << 0 << '\n'; // 힙이 비어있다면 0 출력
            }
            else
            {
                cout << pq.top() << '\n'; // 최소값 출력
                pq.pop();                 // 최소값 제거
            }
        }
    }

    return 0;
}