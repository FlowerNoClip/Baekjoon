#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (true)
    {
        int N;
        cin >> N;
        if (N == 0) break;
        vector <int> A(N);

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        for (int a = 0; a < N; a++)
        {
            for (int b = a + 1; b < N; b++)
            {
                for (int c = b + 1; c < N; c++)
                {
                    for (int d = c + 1; d < N; d++)
                    {
                        for (int e = d + 1; e < N; e++)
                        {
                            for (int f = e + 1; f < N; f++)
                            {
                                cout << A[a] << " " << A[b] << " " << A[c] << " " << A[d] << " " << A[e] << " " << A[f] << endl;
                            }
                        }
                    }
                }
            }
        }

            cout << endl;
    }
}
    



