#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> arr(N);
    for (size_t i = 0; i < N; i++)
        cin >> arr[i];

    int result = -__INT32_MAX__;
    int sum = 0;
    sort(arr.begin(), arr.end());
    do {
        for (size_t i = 1; i < N; i++)
            sum += abs(arr[i - 1] - arr[i]);
        if (sum > result)
            result = sum;
        sum = 0;
     }
     while (next_permutation(arr.begin(), arr.end()));
         cout << result << '\n';
     return 0;
}