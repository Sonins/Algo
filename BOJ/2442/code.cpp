#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 0; j < N - i; j++)
            cout << ' ';
        for (size_t j = 0; j < (2 * i) - 1; j++)
            cout << '*';
        cout << endl;
    }
    return 0;
}