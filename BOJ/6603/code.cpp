#include <stdio.h>

using namespace std;

int K;
int arr[13];
bool visit[13];

void DFS(int cnt, int idx) {
    if (cnt == 6) {
        for (size_t i = 0; i < K; i++)
            if (visit[i])
                printf("%d ", arr[i]);
        printf("\n");
        return;
    }

    
    for (size_t i = idx; i < K; i++) {
        visit[i] = true;
        DFS(cnt + 1, i + 1);
        visit[i] = false;
    }
}

int main() {
    while (true) {
        scanf("%d", &K);

        if (!K)
            break;

        for (size_t i = 0; i < K; i++)
            scanf("%d", &arr[i]);

        DFS(0, 0);
        printf("\n");
    }
    return 0;
}