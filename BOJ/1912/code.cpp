#include <cstdio>
#include <algorithm>
#define MAX 100010
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);

    int arr[MAX];
    int dp[MAX] = {0};
    for (size_t i = 0; i < N; i++)
        scanf("%d", &arr[i + 1]);
    
    dp[1] = arr[1];
    int _max = arr[1];
    for (size_t i = 2; i <= N; i++)
    {
        if (dp[i - 1] + arr[i] > arr[i])
            dp[i] = dp[i - 1] + arr[i];
        else
            dp[i] = arr[i];
        _max = max(_max, dp[i]);
    }
    
    printf("%d", _max);
    

    return 0;
}
