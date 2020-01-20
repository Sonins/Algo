#include <iostream>
using namespace std;
int main() {
    int T;
    int A, B;
    cin >> T;
    for (int i = 0; i < T; i++) {
        scanf("%d,%d", &A, &B);
        cout << A+B << '\n';
    }
    return 0;
}