#include <iostream>
using namespace std;
int main() {
    cin.tie(NULL);
    int N, A, B;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        cout << "Case #" << i << ": " << A+B << '\n';
    }
    return 0;
}