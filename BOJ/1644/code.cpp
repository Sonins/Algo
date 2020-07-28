#include <stdio.h>
#include <vector>
using namespace std;
bool visit[4000001];
int main() {
    int N;
    scanf("%d", &N);
    vector<int> v;
    v.push_back(2);

    for (size_t i = 3; i <= N; i += 2) {
        if (visit[i])
            continue;

        v.push_back(i);
        for (size_t j = i * i; j <= N; j += 2 * i)
            visit[j] = true;
    }
    
    int low = 0, high = 0;
    int sum = 0;
    int ans = 0;
    while (1) {
        if (sum == N)
            ans++;
        if (sum > N)
            sum -= v[low++];
        else if (high < v.size())
            sum += v[high++];
        else
            break;
    }
    printf("%d\n", ans);
    return 0;
}