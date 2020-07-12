#include <iostream>

int arr[30];
bool visit[30];
int ans, N, S;
using namespace std;

void dfs(int idx) {
    int sum = 0;

    for (size_t i = idx; i < N; i++) {
        if (!visit[i]) {
            visit[i] = true;
            sum = 0;
            for (size_t j = 0; j < N; j++) {
                if (visit[j])
                    sum += arr[j];
            }
            if (sum == S)
                ans++;
            dfs(i);
            visit[i] = false;
        }
    }
}

int main() {
    cin >> N >> S;
    for (size_t i = 0; i < N; i++)
        cin >> arr[i];

    dfs(0);

    cout << ans << '\n';
    return 0;
}