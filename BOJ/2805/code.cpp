#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> height;
    int hei;
    for (size_t i = 0; i < N; i++) {
        cin >> hei;
        height.push_back(hei);
    }

    int L = 0, R = __INT32_MAX__;
    int mid;
    long long count;
    while (L < R) {
        mid = (L + R) / 2;
        count = 0;
        for (size_t i = 0; i < N; i++)
            count += height[i] - mid > 0 ? height[i] - mid : 0;

        if (count < M)
            R = mid;
        else
            L = mid + 1;
    }
    cout << L - 1 << '\n';
    return 0;
}