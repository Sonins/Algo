#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (size_t i = 0; i < N - 1; i++)
        cout << ' ';
    cout << '*' << endl;
    for (size_t i = 2; i <= N - 1; i++) {
        for (size_t j = 0; j < N - i; j++)
            cout << ' ';
        cout << '*';
        for (size_t j = 0; j < 2 * (i - 1) - 1; j++)
            cout << ' ';
        cout << '*' << endl;
    }
    for (size_t i = 0; i < 2 * N - 1; i++) {
        if (N == 1)
            break;
        cout << '*';
    }
    if (N != 1)
        cout << endl;
    return 0;
}