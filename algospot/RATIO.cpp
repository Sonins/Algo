#include <iostream>

using namespace std;

int cal_ratio(long long int n, long long int m, long long int x) {
    return (((m + x) * 100 / (n + x)) - (m * 100 / n)) - 1;
}

int main() {
    int T;
    cin >> T;

    for (int tcase = 0; tcase < T; tcase++) {
        long long int N, M;
        cin >> N >> M;

        long long int x1 = 0;
        long long int x2 = __INT32_MAX__;

        for (int iter = 0; iter < 100; iter++) {
            long long int mx = (x1 + x2) / 2LL;
            int cal = cal_ratio(N, M, mx);
            if (cal >= 0) {
                x2 = mx;
            } else {
                x1 = mx;
            }
        }
      
        if (cal_ratio(N, M, x2) < 0) {
            cout << -1 << endl;
        } else {
            cout << x2 << endl;
        }
        
    }

    return 0;
}