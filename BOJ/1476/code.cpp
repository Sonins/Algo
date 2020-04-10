#include <iostream>
#define E_limit 16
#define S_limit 29
#define M_limit 20
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int E, S, M;
    cin >> E >> S >> M;

    int e = 1, s = 1, m = 1;
    int year = 1;
    while (e != E || s != S || m != M) {
        e = (e + 1) % E_limit;
        s = (s + 1) % S_limit;
        m = (m + 1) % M_limit;

        if (!e)
            e = 1;
        if (!s)
            s = 1;
        if (!m)
            m = 1;
        year++;
    }
    cout << year << '\n';
    return 0;
}