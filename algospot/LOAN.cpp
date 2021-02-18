#include <iostream>

using namespace std;

int main() {
    int T;
    ios::sync_with_stdio(false);
    cin >> T;
    cout.precision(10);
    cout << fixed;

    double answer[60];

    for (int tcase = 0; tcase < T; tcase++) {
        double N, P;
        int M;
        cin >> N >> M >> P;
        double x1 = 0;
        double x2 = 2 * N;
        for (int iter = 0; iter < 100; iter++) {
            double remain = N;
            double mx = (x1 + x2) / 2;
            for (int i = 0; i < M; i++) {
                remain *= 1 + (P / (12 * 100));
                remain -= mx;
            }

            if (remain > 0) {
                x1 = mx;
            } else {
                x2 = mx;
            }
        }

        answer[tcase] = x2;
    }

    for (int i = 0; i < T; i++) {
        cout << answer[i] << endl;
    }
    return 0;
}