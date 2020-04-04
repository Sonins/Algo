#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int arr[1010];

    for (size_t i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    for (size_t i = 1; i < N; i++)
        arr[i] += arr[i - 1];

    int ans = 0;

    for (size_t i = 0; i < N; i++)
        ans += arr[i];

    cout << ans << '\n';
    return 0;
}