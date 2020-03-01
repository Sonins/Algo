#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 30

using namespace std;

bool g[MAX][MAX];
bool visited[MAX][MAX];
int cnt;

void DFS(int i, int j) {
    cnt++;
    visited[i][j] = true;
    if (i + 1 < MAX && g[i + 1][j] && !visited[i + 1][j]) DFS(i + 1, j);
    if (j + 1 < MAX && g[i][j + 1] && !visited[i][j + 1]) DFS(i, j + 1);
    if (i - 1 > 0 && g[i - 1][j] && !visited[i - 1][j]) DFS(i - 1, j);
    if (j - 1 > 0 && g[i][j - 1] && !visited[i][j - 1]) DFS(i, j - 1);
}

int main() {
    int N;
    cin >> N;

    char s[30];

    for (size_t i = 1; i <= N; i++) {
        cin >> s;
        for (size_t j = 0; s[j] != '\0'; j++)
            g[i][j + 1] = s[j] - '0';
    }

    int num = 0;
    vector<int> number_of_aprt;

    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= N; j++) {
            if (!visited[i][j] && g[i][j]) {
                num++;
                DFS(i, j);
                number_of_aprt.push_back(cnt);
                cnt = 0;
            }
        }
    }

    sort(number_of_aprt.begin(), number_of_aprt.end());

    cout << num << '\n';
    for (auto i : number_of_aprt)  
        cout << i << '\n';
    return 0;
}