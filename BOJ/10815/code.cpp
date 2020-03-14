#include <algorithm>
#include <iostream>
using namespace std;

int v[500010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;

    for (size_t i = 0; i < N; i++)
        cin >> v[i];

    sort(v, v + N);

    cin >> M;

    int num;
    bool find;
    int L, R;
    for (size_t i = 0; i < M; i++) {
        cin >> num;
        find = false;
        L = 0;
        R = N;
        while (L < R) {
            if (v[(L + R) / 2] > num)
                R = (L + R) / 2;
            else if (v[(L + R) / 2] < num)
                L = (L + R) / 2 + 1;
            else {
                find = true;
                break;
            }
        }
        cout << find << " ";
    }
    cout << '\n';
    return 0;
}