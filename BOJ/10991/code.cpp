#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 0; j < N - i; j++)
            cout << ' ';
        for (size_t j = 0; j < i; j++) {
            cout << '*';
            cout << ' ';
        }
        cout << endl;
    }
    return 0;
}