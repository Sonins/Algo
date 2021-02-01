#include <iostream>

#define MAX 100010

using namespace std;

int arr[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;

    cin >> N >> M;
    
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 2; i <= N; i++)
        arr[i] += arr[i - 1];
    
    int I, J;
    for (int i = 0; i < M; i++) {
        cin >> I >> J;
        cout << arr[J] - arr[I - 1] << '\n';
    }
    return 0;
}