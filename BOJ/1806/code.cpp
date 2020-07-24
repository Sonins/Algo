#include <iostream>
#define MAX 100001
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, S;
    cin >> N >> S;
    int arr[MAX];

    for (size_t i = 0; i < MAX; i++)
        arr[i] = 0;
    
    for (size_t i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    int min_len = MAX;
    int low = 0, high = 1;
    while (low < N) {
        if (arr[high] - arr[low] >= S) {
            min_len = min_len > high - low ? high - low : min_len;
            low++;
        }
        else if (high != N)
            high++;
        else
            low++;
    }

    cout << (min_len == MAX ? 0 : min_len) << '\n';
    return 0;
}