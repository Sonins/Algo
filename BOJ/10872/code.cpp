#include <iostream>
using namespace std;
int fac(int n) {
    if (n == 1)
        return 1;
    return n * fac(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    if (N)
        cout << fac(N) << '\n';
    else
        cout << 1 << '\n';
    return 0;
}