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
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long 
#define INF 1e9+10 
using namespace std;

int main() {
    FAST_IO;
    const int MAX = 4'000'000;
    vector<bool> isPrime(MAX + 1, true);
    vector<int> primes;
    int N; cin >> N;
    isPrime[0] = isPrime[1] = false;  

    for (int i = 2; i * i <= MAX; ++i) 
    {
        if (!isPrime[i]) continue;

        for (int j = i * i; j <= MAX; j += i) 
        {
            isPrime[j] = false;  
        }
    }

    for (int i = 2; i <= MAX; ++i) 
    {
        if (isPrime[i]) primes.push_back(i);
    }
    int left = 0; int right = 0; int cnt = 0;
    int sum = 0;

    while (true) {
        if (sum >= N) sum -= primes[left++];
        else {
            if (right == primes.size()) break;
            sum += primes[right++];
        }
        if (sum == N) cnt++;
    }

    cout << cnt;
}