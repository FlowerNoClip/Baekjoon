#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M; cin >> M;
    vector<int> arr(21, 0);
    while (M--)
    {
        string temp;
        cin >> temp;
        if (temp == "add")
        {
            int num;
            cin >> num;
            if (arr[num] == 0)
            {
                arr[num] = 1;
            }
        }
        else if (temp == "remove")
        {
            int num;
            cin >> num;
            if (arr[num] == 1)
            {
                arr[num] = 0;
            }
        }
        else if (temp == "check")
        {
            int num;
            cin >> num;
            if (arr[num] == 1)
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if (temp == "toggle")
        {
            int num;
            cin >> num;
            if (arr[num] == 1)
            {
                arr[num] = 0;
            }
            else
            {
                arr[num] = 1;
            }
        }
        else if (temp == "all")
        {
            for (int i = 0; i < arr.size(); i++)
            {
                arr[i] = 1;
            }
        }
        else if (temp == "empty")
        {
            for (int i = 0; i < arr.size(); i++)
            {
                arr[i] = 0;
            }
        }
    }
}