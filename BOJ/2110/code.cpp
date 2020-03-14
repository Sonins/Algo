#include <algorithm>
#include <iostream>
#define MAX 200010
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int N, C;
    cin >> N >> C;

    int arr[MAX];
    for (size_t i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    int mid;
    int L = 0, R = __INT32_MAX__;

    int before;
    int count;
    while (L < R) {
        mid = (L + R) / 2;
        count = 0;
        before = arr[0];
        count++;
        for (size_t i = 0; i < N; i++) {
            if (arr[i] - before >= mid) {
                before = arr[i];
                count++;
            }
        }

        if (count < C)
            R = mid;
        else
            L = mid + 1;
    }
    cout << L - 1 << '\n';
    return 0;
}