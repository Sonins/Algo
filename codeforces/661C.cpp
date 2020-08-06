#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int t, N;
    cin >> t;
    
    for (size_t T = 0; T < t; T++) {
        cin >> N;
        vector<int> arr(200, 0);
        int num, cur = 0, ans = 0;
        for (size_t i = 0; i < N; i++) {
            cin >> num;
            arr[num]++;
        }

        for (int s = 2; s <= 2 * N; s++) {
            for (int i = 1; i < s; i++)
                cur += (arr[i] < arr[s - i] ? arr[i] : arr[s - i]);
            cur /= 2;
            if (ans < cur)
                ans = cur;
            cur = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}