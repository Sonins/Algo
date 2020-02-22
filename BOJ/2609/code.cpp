#include <stdio.h>
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int aa = a, bb = b, r;
    while (bb != 0) {
        r = aa % bb;
        aa = bb;
        bb = r;
    }
    printf("%d\n", aa);
    printf("%d\n", a * b / aa);
    return 0;
}