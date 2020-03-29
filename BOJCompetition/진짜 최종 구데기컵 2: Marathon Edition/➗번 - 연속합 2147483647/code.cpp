#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 300010
using namespace std;

long long part_sum[MAX];
int arr[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> dec;
    vector<int> inc;

    for (size_t i = 0; i < N; i++)
        cin >> arr[i];

    int inc_idx;
    int dec_idx;

    for (size_t i = 0; i < N; i++) {
        inc_idx = upper_bound(inc.begin(), inc.end(), arr[i]) - inc.begin();
        dec_idx = upper_bound(dec.begin(), dec.end(), arr[N - i - 1]) - dec.begin();
        if (inc_idx == inc.size())
            inc.push_back(arr[i]);
        else
            inc[inc_idx] = arr[i];

        if (dec_idx == dec.size())
            dec.push_back(arr[N - i - 1]);
        else
            dec[dec_idx] = arr[N - i - 1];
    }
    /*
    if (dec.size() * inc.size() >= N) {
        cout << -1 << '\n';
        return 0;
    }
    */

    part_sum[0] = arr[0];
    long long _max = part_sum[0];
    for (size_t i = 1; i < N; i++) {
        if (arr[i] + part_sum[i - 1] > arr[i])
            part_sum[i] = arr[i] + part_sum[i - 1];
        else
            part_sum[i] = arr[i];
        _max = max(_max, part_sum[i]);
    }

    cout << _max << '\n';
    return 0;
}