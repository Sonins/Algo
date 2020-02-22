#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    int aa, bb, r;
    int T;
    cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        cin >> a >> b;
        aa = a;
        bb = b;
        while (bb != 0) {
            r = aa % bb;
            aa = bb;
            bb = r;
        }
        cout << a * b / aa << '\n';
    }
    return 0;
}