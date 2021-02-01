#include <iostream>
#include <cmath>

#define MAX 100010
using namespace std;

int arr[MAX];
int sqrt_sum[400];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, l, r;
    cin >> N >> M;

    int sqrt_N = ceil(sqrt(N));

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    for (int i = 0; i < N; i++)
        sqrt_sum[i / sqrt_N] += arr[i];

    int sum;
    for (int i = 0; i < M; i++) {
        sum = 0;
        cin >> l >> r;
        l--;

        if (l / sqrt_N == r / sqrt_N) {
            for (int j = l; j < r; j++)
                sum += arr[j];
            
            cout << sum << '\n';
            continue;
        }

        for (int j = l; j < (l / sqrt_N + 1) * sqrt_N; j++)
            sum += arr[j];
        
        for (int j = l / sqrt_N + 1; j < r / sqrt_N; j++)
            sum += sqrt_sum[j];
        
        for (int j = r / sqrt_N * sqrt_N; j < r; j++)
            sum += arr[j];

        cout << sum << '\n';
    }
    return 0;
}