#include <iostream>
using namespace std;
int A[1000010];
int B[1000010];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    int curA = 0, curB = 0;
    for (size_t i = 0; i < N; i++)
        cin >> A[i];

    for (size_t i = 0; i < M; i++)
        cin >> B[i];

    while (curA < N && curB < M) {
        if (A[curA] < B[curB])
            cout << A[curA++] << " ";
        else
            cout << B[curB++] << " ";
    }

    for (size_t i = curA; i < N; i++)
        cout << A[curA++] << " ";

    for (size_t j = curB; j < M; j++)
        cout << B[curB++] << " ";
    cout << '\n';
    return 0;
}