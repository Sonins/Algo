#include <cstdio>
using namespace std;
int arr[350000];
char s[350000];
int main() {
    scanf("%s", s);
    int idx = 0;
    int cnt = 0;
    int digit;
    while (s[idx]) {
        digit = s[idx] - '0';
        for (size_t i = 0; i < 3; i++) {
            arr[cnt] /= 10;
            arr[cnt] += (digit & 1) * 100;
            digit >>= 1;
        }
        idx++;
        cnt++;
    }

    printf("%d", arr[0]);
    for (size_t i = 1; i < cnt; i++) {
        printf("%d", arr[i] / 100);
        arr[i] %= 100;
        printf("%d", arr[i] / 10);
        arr[i] %= 10;
        printf("%d", arr[i] / 1);
    }
    printf("\n");
    return 0;
}