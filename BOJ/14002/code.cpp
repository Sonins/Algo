#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX (int)1e6 + 10
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    
    pair<int, int> dp[MAX];

    for (size_t i = 0; i < N; i++)
        scanf("%d", &dp[i + 1].first);
    
    vector<int> v;
    int index = 0;
    int last;
    v.push_back(dp[1].first);
    dp[1].second = 0;
    last = 1;
    for (size_t i = 2; i <= N; i++) {
        index = lower_bound(v.begin(), v.end(), dp[i].first) - v.begin();
        if (index == v.size()) {
            v.push_back(dp[i].first);
            dp[i].second = index;
            last = i;
        }
        else {
            dp[i].second = index;
            v[index] = dp[i].first;
        }
    }
    printf("%lu\n", v.size());

    stack<int> ans;
    int size = dp[last].second;
    ans.push(dp[last].first);
    size--;
    for (size_t i = last - 1; i >= 1; i--) {
        if (dp[i].second == size && dp[i].first < ans.top()) {
            ans.push(dp[i].first);
            size--;
            if (size == -1)
                break;
        }
    }
    
    while (!ans.empty())
    {
        printf("%d ", ans.top());
        ans.pop();
    }
    
    printf("\n");
    
    return 0;
}
