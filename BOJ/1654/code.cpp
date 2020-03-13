#include <iostream>
#include <vector>
using namespace std;

typedef long long lld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    lld N, K;
    cin >> K >> N;

    vector<int> length;
    int len;
    lld L = 0, R = (lld)INT32_MAX + 10;
    for (size_t i = 0; i < K; i++) {
        cin >> len;
        length.push_back(len);
    }

    lld count;
    lld max_length;
    while (L < R) {
        max_length = (L + R) / 2;
        count = 0;

        for (size_t i = 0; i < K; i++)
            count += length[i] / max_length;

        if (count < N)
            R = max_length;
        else {
            L = max_length + 1;
        }
    }
    cout << L - 1 << '\n';
    return 0;
}