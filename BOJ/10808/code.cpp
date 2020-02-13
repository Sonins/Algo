#include <stdio.h>
#include <string.h>
int main() {
    char str[110];
    int arr[26];
    memset(arr, 0, sizeof(arr));
    scanf("%s", str);
    for (size_t i = 0; str[i] != '\0'; i++)
        arr[str[i] - 'a']++;
    for (size_t i = 0; i < 26; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}