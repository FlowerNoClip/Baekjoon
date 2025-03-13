#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr;
    vector<string> arrc;
    int temp;
    for (int i = 0; i < 3; i++)
    {
        cin >> temp;
        arr.push_back(temp);
        arrc.push_back(to_string(temp));
    }

    cout << arr[0] + arr[1] - arr[2] << endl;
    cout << stoi(arrc[0] + arrc[1]) - stoi(arrc[2]) << endl;
}
