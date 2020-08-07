#include <iostream>
#define MAX 1010

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int C, N, L;
    cin >> C;
    int arr[MAX];
    double min = __INT32_MAX__;
    cout.precision(10);
    for (size_t c = 0; c < C; c++) {
        cin >> N >> L;
        arr[0] = 0;
        min = __INT32_MAX__;
        for (size_t i = 1; i <= N; i++) {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }

        for (size_t i = L; i <= N; i++) {
            for (size_t j = i; j <= N; j++) {
                if (min > (double)(arr[j] - arr[j - i]) / i)
                    min = (double)(arr[j] - arr[j - i]) / i;
            }
        }
        cout << min << '\n';
    }
    return 0;
}