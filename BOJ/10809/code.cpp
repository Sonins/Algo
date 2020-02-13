#include <stdio.h>
#include <string.h>
int main() {
    char str[110];
    int arr[26];
    memset(arr, -1, sizeof(arr));
    scanf("%s", str);
    size_t idx = -1;
    while(str[++idx])
        arr[str[idx] - 'a'] = (arr[str[idx] - 'a'] == -1 ? idx : arr[str[idx] - 'a']);
    for (size_t i = 0; i < 26; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}