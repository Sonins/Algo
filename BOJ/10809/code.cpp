#include <stdio.h>
int main() {
    char str[110];
    int arr[26] = {0};
    scanf("%s", str);
    int idx = -1;
    while(str[++idx]) { if(!arr[str[idx] - 'a']) arr[str[idx] - 'a'] = idx + 1; }
    for (size_t i = 0; i < 26; i++)
        printf("%d ", --arr[i]);
    printf("\n");
    return 0;
}