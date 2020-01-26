#include <stdio.h>
#include <vector>
int arr[11];
int main() {
    int N;
    size_t T;
    std::vector<int> nlist;
    scanf("%d", &T);
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (size_t i = 4; i < 11; i++)
    {
        arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
    }
    arr[1]--; arr[2]--; arr[3]--;
    for (size_t i = 0; i < T; i++)
    {
        scanf("%d", &N);
        nlist.push_back(N);
    }
    for (auto i : nlist)
        printf("%d\n", arr[i]);

    return 0;
}