#include <cstdio>

int fn(int x, int y) {
    return y ? fn(y, x % y) : x;
}
int a, b, T;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", a * b / fn(a, b));
    }
    return 0;
}