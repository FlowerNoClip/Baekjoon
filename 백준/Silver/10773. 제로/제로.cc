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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    stack<int> st;
    while (N--)
    {
        int temp; 
        cin >> temp;

        if (temp != 0)
        {
            st.push(temp);
        }
        else if (temp == 0)
        {
            st.pop();
        }
    }
    
    int sum = 0;

    while (!st.empty())
    {
        sum += st.top();
        st.pop();
    }

    cout << sum << endl;
}
