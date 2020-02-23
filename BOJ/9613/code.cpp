#include <cstdio>
#include <cstring>
int main() {
    int t, n;
    long long result = 0;
    int arr[200];
    int a, b, r;
    scanf("%d", &t);
    for (size_t T = 0; T < t; T++)
    {   
        scanf("%d", &n);
        for (size_t j = 0; j < n; j++)
            scanf("%d", &arr[j]);

        for (size_t j = 0; j < n; j++) {
            for (size_t i = 0; i < j; i++) {
                a = arr[i]; 
                b = arr[j];
                while (b) {
                    r = a % b;
                    a = b;
                    b = r;
                }
                result += a;
            }
        }
        printf("%lld\n", result);
        result = 0;
        memset(arr, 0, sizeof(arr));
    }
    return 0;
}