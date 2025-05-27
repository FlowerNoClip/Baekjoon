#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    stringstream ss(s);
    vector<int> numbers;
    int num;

    while (ss >> num) {
        numbers.push_back(num);
    }

    int minValue = *min_element(numbers.begin(), numbers.end());
    int maxValue = *max_element(numbers.begin(), numbers.end());

    return to_string(minValue) + " " + to_string(maxValue);
}