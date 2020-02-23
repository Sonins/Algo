#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    const char char_table[38] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int N, B;
    cin >> N >> B;
    string s;
    while (N >= B) {
        s.push_back(char_table[N % B]);
        N = N / B;
    }
    s.push_back(char_table[N]);
    reverse(s.begin(), s.end());
    cout << s << '\n';
    return 0;
}