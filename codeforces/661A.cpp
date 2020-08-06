#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int N;
    int arr[51];
    bool ans = 1;
    for (size_t T = 0; T < t; T++) {
        cin >> N;
        for (size_t i = 0; i < N; i++)
            cin >> arr[i];

        sort(arr, arr + N);

        for (size_t i = 1; i < N; i++) {
            if (arr[i] - arr[i - 1] > 1) {
                ans = 0;
                break;
            }
        }

        if (!ans)
            cout << "NO\n";
        else
            cout << "YES\n";
        ans = 1;
    }
    return 0;
}