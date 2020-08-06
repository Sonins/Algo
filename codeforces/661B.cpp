#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int N;
    long long int cand[51];
    long long int oran[51];
    long long int min_oran = __INT32_MAX__, min_cand = __INT32_MAX__;
    long long int cand_eat, oran_eat;
    long long int ans;
    for (size_t T = 0; T < t; T++) {
        cin >> N;
        ans = 0;
        min_oran = __INT32_MAX__;
        min_cand = __INT32_MAX__;
        for (size_t i = 0; i < N; i++) {
            cin >> cand[i];
            if (min_cand > cand[i])
                min_cand = cand[i];
        }

        for (size_t i = 0; i < N; i++) {
            cin >> oran[i];
            if (min_oran > oran[i])
                min_oran = oran[i];
        }

        for (size_t i = 0; i < N; i++) {
            cand_eat = cand[i] - min_cand;
            oran_eat = oran[i] - min_oran;
            if (cand_eat > oran_eat)
                ans += cand_eat;
            else {
                ans += oran_eat;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}