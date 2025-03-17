#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int N)
{
    if (N < 2) return false;

    for (int i = 2; i <= sqrt(N); i++) // `<=`를 사용해 √N까지 검사
    {
        if (N % i == 0) return false;
    }

    return true;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N; 
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (isPrime(arr[i]))
        {
            count++;
        }
    }

    cout << count;
    return 0;
}
