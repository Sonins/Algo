#include <stdio.h>
#include <algorithm>
#define MAX 1000000
using namespace std;
bool ch[MAX];

bool check(int N, int br) {
    if (N == 0 && br == 0)
        return true;
    while (N != 0) {
        if ((N % 10) - br == 0)
            return true;
        N /= 10;
    }
    return false;
}

int main() {
    int N;
    scanf("%d", &N);
    int M;
    scanf("%d", &M);

    for (size_t i = 0; i < MAX; i++)
        ch[i] = true;

    int broken;
    for (size_t i = 0; i < M; i++) {
        scanf("%d", &broken);
        for (size_t j = 0; j < MAX; j++) {
            if(check(j, broken))
                ch[j] = false;
        }
    }

    int nearest = 0;
    int _min = 2 * MAX;
    for (int i = 0; i < MAX; i++) {
        if (ch[i] && _min > abs(i - N)) {
            _min = abs(i - N);
            nearest = i;
        }
    }
    if (nearest == 0)
        _min++;
    
    while (nearest != 0) {
        nearest /= 10;
        _min++;
    }

    if (_min < abs(N - 100))
        printf("%d\n", _min);
    else
        printf("%d\n", abs(N - 100));
    return 0;
}