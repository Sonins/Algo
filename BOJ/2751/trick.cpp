#include <stdio.h>
#define MAX (int)1e6 + 10
using namespace std;

bool _minus[MAX];
bool _plus[MAX];

int main() {
    int N;
    scanf("%d", &N);
    int num;
    for (int i = 0; i < N; i++)
    {   
        scanf("%d", &num);
        if (num < 0)
            _minus[-1 * num] = true;
        if (num >= 0)
            _plus[num] = true;
    }
    for (int i = MAX - 1; i > 0; i--)
    {
        if (_minus[i])
            printf("%d\n", -1 * i);
    }
    for (int i = 0; i < MAX; i++)
    {
        if (_plus[i])
            printf("%d\n", i);
    }
    
    return 0;
    
}