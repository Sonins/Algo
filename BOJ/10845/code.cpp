#include <stdio.h>
#include <string.h>
using namespace std;

int main() {
    int arr[10010];
    int top = 0, bot = -1;
    int N;
    scanf("%d", &N);
    char com[10];
    int num;
    for (size_t i = 0; i < N; i++)
    {
        scanf("%s", com);
        if (!strcmp(com, "push")) {
            scanf("%d", &arr[++bot]);
        } else if (!strcmp(com, "pop")) {
            if (top <= bot)
                printf("%d\n", arr[top++]);
            else
                printf("-1\n");
        } else if (!strcmp(com, "size"))
            printf("%d\n", bot - top + 1);
        else if (!strcmp(com, "empty")) {
            if (top <= bot)
                printf("0\n");
            else
                printf("1\n");
        } else if (!strcmp(com, "front")) {
            if (top <= bot)
                printf("%d\n", arr[top]);
            else
                printf("-1\n");
        } else if (!strcmp(com, "back")) {
            if (top <= bot)
                printf("%d\n", arr[bot]);
            else
                printf("-1\n");
        }
    }
    return 0;
    
}