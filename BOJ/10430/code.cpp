#include <stdio.h>
int main() {
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    for (int i = 0; i < 2; i++)
        printf("%d\n", (A + B) % C);
    for (int i = 0; i < 2; i++)
        printf("%d\n", (A * B) % C);    
    return 0;
}