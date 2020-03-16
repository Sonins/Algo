#include <iostream>
using namespace std;

void hanoi(int from, int thru, int to, int n) {
    if (n == 1) {
        cout << from << " " << to << '\n';
        return;
    }

    hanoi(from, to, thru, n - 1);
    cout << from << " " << to << '\n';
    hanoi(thru, from, to, n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int N;
    cin >> N;
    cout << (1 << N) - 1 << '\n';
    hanoi(1, 2, 3, N);

    return 0;
}