#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> arr(N);
    vector<bool> visited(N, false);

    for (size_t i = 0; i < N; i++)
        cin >> arr[i];

    if (N == 1) {
        cout << arr[0] << '\n';
        return 0;
    }

    sort(arr.begin(), arr.end(), greater<int>());

    int idx = N;

    for (size_t i = 0; i < N; i++) {
        if (arr[i] <= 0) {
            idx = i;
            sort(arr.begin() + i, arr.end());
            break;
        }
    }
    
    int sum = 0;
    for (int i = 1; i < idx; i += 2) {
        if (arr[i - 1] >= 2 && arr[i] >= 2) {
            sum += arr[i - 1] * arr[i];
        } else {
            sum += arr[i];
            sum += arr[i - 1];
        }
    }

    if (idx % 2)
        sum += arr[idx - 1];

    for (int i = idx + 1; i < N; i += 2)
        sum += arr[i - 1] * arr[i];

    if ((N - idx) % 2 && idx != N)
        sum += arr[N - 1];

    cout << sum << '\n';
    return 0;
}