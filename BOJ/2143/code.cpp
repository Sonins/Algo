#include <algorithm>
#include <iostream>

using namespace std;

int A[1010];
int B[1010];

int AT[1000010];
int BB[1000010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N, M;
    cin >> T;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    cin >> M;
    for (int i = 1; i <= M; i++)
        cin >> B[i];

    int AT_size = 0;
    for (int i = 1; i <= N; i++) {
        A[i] += A[i - 1];
        for (int j = 0; j < i; j++) {
            AT[AT_size++] = T - (A[i] - A[j]);
        }
    }

    int BB_size = 0;
    for (int i = 1; i <= M; i++) {
        B[i] += B[i - 1];
        for (int j = 0; j < i; j++) {
            BB[BB_size++] = B[i] - B[j];
        }
    }

    sort(AT, AT + AT_size);
    sort(BB, BB + BB_size);

    long long int cnt = 0;

    int AT_i = 0, BB_i = 0;
    int AT_cnt = 0, BB_cnt = 0;
    while (BB_i < BB_size && AT_i < AT_size) {
        int AT_val = AT[AT_i];
        int BB_val = BB[BB_i];

        if (AT_val < BB_val) {
            while (AT[AT_i] == AT_val && AT_i < AT_size) AT_i++;
            continue;
        }

        if (AT_val > BB_val) {
            while (BB[BB_i] == BB_val && BB_i < BB_size) BB_i++;
            continue;
        }

        while (AT[AT_i] == AT_val && AT_i < AT_size) {
            AT_cnt++;
            AT_i++;
        }

        while (BB[BB_i] == BB_val && BB_i < BB_size) {
            BB_cnt++;
            BB_i++;
        }

        cnt += (long long int)BB_cnt * AT_cnt;
        AT_cnt = 0;
        BB_cnt = 0;
    }

    cout << cnt << '\n';
    return 0;
}