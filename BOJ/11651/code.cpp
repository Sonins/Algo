#include <iostream>
#include <algorithm>
#define MAX 100010
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    pair<int, int> arr[MAX];
    int x, y;
    int N;
    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        cin >> x >> y;
        arr[i + 1] = make_pair(y, x);
    }

    sort(arr + 1, arr + N + 1);

    for (size_t i = 0; i < N; i++)
    {
        cout << arr[i + 1].second << " " << arr[i + 1].first << '\n';
    }

    return 0;
}