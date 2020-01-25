#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (size_t i = 1; i <= 2 * N - 1; i++) {
        if (i <= N) {
            for (size_t j = 1; j < i; j++)
                cout << ' ';
            for (size_t j = 2 * i; j <= 2 * N; j++)
                cout << '*';
            cout << endl;
        } else {
            for (size_t j = i; j < 2 * N - 1; j++)
                cout << ' ';
            for (size_t j = 2 * N; j <= 2 * i; j++)
                cout << '*';
            cout << endl;
        }       
    }
    return 0;
}