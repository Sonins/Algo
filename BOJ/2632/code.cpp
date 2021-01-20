#include <iostream>
#define MAX 1002
using namespace std;


int A[MAX];
int B[MAX];

int Asum[MAX * MAX];

bool isinRange(int num) {
    return num >= 0 && num < MAX * MAX;
}

int main() {
    int N, M;
    int S;
    ios::sync_with_stdio(false);
    cin >> S;
    cin >> M >> N;

    for (int i = 0; i < M; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++)
        cin >> B[i];

    for (int i = 1; i < M; i++)
        A[i] += A[i - 1];

    for (int i = 1; i < N; i++)
        B[i] += B[i - 1];

    int sum = 0;
    long long int cnt = 0;

    Asum[0] = 1;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < i; j++) {
            Asum[A[i] - A[j]]++;
            Asum[A[M - 1] - (A[i] - A[j])]++;
        }
    }
    Asum[A[M - 1]]++;
    cnt += Asum[S];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {

            if (isinRange(S - (B[i] - B[j])))
                cnt += Asum[S - (B[i] - B[j])];

            if (isinRange(S - (B[N - 1] - (B[i] - B[j]))))
                cnt += Asum[S - (B[N - 1] - (B[i] - B[j]))];
        }
    }

    if (isinRange(S - B[N - 1]))
        cnt += Asum[S - B[N - 1]];

    cout << cnt << endl;
    return 0;
}

/**
 * 빼먹은 경우의 수 없는지 항상 확인할것
*/