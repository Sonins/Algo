#include <stdio.h>
char rot32 (char a) {
    char b = (a >= 'a' ? a - 'a' : a - 'A');
    return (b + 13) % 26 + (a >= 'a' ? 'a' : 'A');
} 
int main() {
    char str[110];
    fgets(str, sizeof(str), stdin);
    int idx = -1;
    while (str[++idx]) {
        if (('a' <= str[idx] && str[idx] <= 'z')
            || ('A' <= str[idx] && str[idx] <= 'Z'))
            printf("%c", rot32(str[idx]));
        else
            printf("%c", str[idx]);
    }
    return 0;
}