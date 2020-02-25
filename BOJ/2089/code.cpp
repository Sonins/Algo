#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int N;
    cin >> N;
    vector<bool> v;
    int digit;
    while (N != 0) {
        digit = N % (-2);
        N = N / -2;
        if (digit == -1) {
            digit = 1;
            N++;
        }
        v.push_back(digit);
    }
    for (vector<bool>::reverse_iterator i = v.rbegin(); i != v.rend(); i++)
        cout << *i;
    if (v.empty())
        cout << 0;
    cout << '\n';
    return 0;
}