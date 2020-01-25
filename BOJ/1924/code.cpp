#include <iostream>
using namespace std;
int main() {
    int day_per_month[12] = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30     
    };
    int x, y, days;
    for (int i = 0; i < 11; i++)
        day_per_month[i + 1] += day_per_month[i];
    cin >> x >> y; 
    days = day_per_month[x - 1] + y - 1;
    switch(days % 7) {
        case 0:
        cout << "MON" << '\n';
        break;
        case 1:
        cout << "TUE" << '\n';
        break;
        case 2:
        cout << "WED" << '\n';
        break;
        case 3:
        cout << "THU" << '\n';
        break;
        case 4:
        cout << "FRI" << '\n';
        break;
        case 5:
        cout << "SAT" << '\n';
        break;
        case 6:
        cout << "SUN" << '\n';
    }
    return 0;
}