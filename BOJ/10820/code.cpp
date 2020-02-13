#include <stdio.h>
#include <string.h>
int main() {
    char str[110];
    int idx = -1;
    int ans[4] = {0};
    while (scanf("%[^\n]s", str) != EOF) {
        while (str[++idx]) {
            if ('a' <= str[idx] && str[idx] <= 'z') ans[0]++;
            else if ('A' <= str[idx] && str[idx] <= 'Z') ans[1]++;
            else if ('0' <= str[idx] && str[idx] <= '9') ans[2]++;
            else if (str[idx] == ' ') ans[3]++;
        }
        idx = -1;
        for (size_t i = 0; i < 4; i++)
            printf("%d ", ans[i]);
        printf("\n");
        memset(ans, 0, sizeof(ans));
        scanf("%c", str);
    }
    return 0;
}