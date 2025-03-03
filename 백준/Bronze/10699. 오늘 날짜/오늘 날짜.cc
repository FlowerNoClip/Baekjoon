#include <iostream>
#include <ctime>

using namespace std;

int main() {
    time_t timer = time(NULL);
    tm* t = localtime(&timer);

    char date[11];  
    strftime(date, sizeof(date), "%Y-%m-%d", t);  // YYYY-MM-DD 형식 변환

    cout << date << endl;

    return 0;
}
