#include <iostream>
using namespace std;
int main() {
    int N, A, B;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        cout << "Case #" << i << ": ";
        cout << A << " + " << B;
        cout << " = " << A + B << endl;
    }
    return 0;
}