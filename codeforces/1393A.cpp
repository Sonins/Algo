#include <iostream>

using namespace std;

int main() {
    int T, N;
    cin >> T;
    for (size_t t = 0; t < T; t++)
    {
        cin >> N;
        cout << (N - (N % 2)) / 2 + 1 << '\n';
    }
    return 0;
}