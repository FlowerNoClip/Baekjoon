#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int n1 = num1;
    float n2 = num2;
    float sol = n1 / n2;
    return sol * 1000;
}