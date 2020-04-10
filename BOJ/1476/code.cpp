#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int E, S, M;
    cin >> E >> S >> M;
    E--; S--; M--;
    int year = 0;
    while (year % 15 != E ||
           year % 28 != S ||
           year % 19 != M) {
        year++;
    }
    cout << year + 1 << '\n';
    return 0;
}