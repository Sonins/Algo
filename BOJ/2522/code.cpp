#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (size_t i = 1; i <= 2 * N - 1; i++) {
        if (i <= N) {
            for (size_t j = 0; j < N - i; j++)
                cout << ' ';
            for (size_t j = 0; j < i; j++)
                cout << '*';
            cout << endl;
        } else {
            for (size_t j = 0; j < i - N; j++)
                cout << ' ';
            for (size_t j = 0; j < 2 * N - i; j++)
                cout << '*';
            cout << endl;
        }
    }
    return 0;
}