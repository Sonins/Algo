#include <stdio.h>
using namespace std;

int main() {
    int N;
    unsigned int M, arr[10010];
    scanf("%d %d", &N, &M);
    arr[0] = 0;
    for (size_t i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }

    unsigned int sum;
    int high = 1, low = 0;
    int ans = 0;
    while (!(high == N && low == N)) {
        sum = arr[high] - arr[low];
        if (sum == M)
            ans++;
        
        if (sum <= M) {
            if (high != N)
                high++;
            else
                break;
        } else {
            if (low < high)
                low++;
            else if (high != N)
                high++;
            else
                break;
        }
    }
    printf("%d\n", ans);
    return 0;
}