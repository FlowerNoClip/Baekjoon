#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr(31, -1);

    for (int i = 1; i <=30; i++)
    {
        arr[i] = i;
    }

    int sol;
    for (int i = 0; i < 28; i++)
    {
        cin >> sol;
        arr[sol] = -1;
    }

    sort(arr.begin(), arr.end());
    

    for (int j = 1; j <= 30; j++)
    {
        if (arr[j] != -1)
        {
            cout << arr[j] << endl;
        }
    }

}
