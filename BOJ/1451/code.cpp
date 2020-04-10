#include <iostream>
#include <vector>
using namespace std;

long long cal(pair<int, int> L, pair<int, int> R, vector<vector<int> > &v) {
    int rsize = R.first - L.first + 1;
    int csize = R.second - L.second + 1;
    vector<int> row_sum(rsize, 0);
    vector<int> col_sum(csize, 0);

    if (L.first == R.first && L.second == R.second)
        return 0;

    for (size_t i = L.first; i <= R.first; i++) {
        for (size_t j = L.second; j <= R.second; j++) {
            row_sum[i - L.first] += v[i][j];
            col_sum[j - L.second] += v[i][j];
        }
    }

    for (size_t i = 1; i < rsize; i++)
        row_sum[i] += row_sum[i - 1];

    for (size_t i = 1; i < csize; i++)
        col_sum[i] += col_sum[i - 1];

    long long result = -__INT32_MAX__;
    long long part_result;
    for (size_t i = 0; i < rsize - 1; i++) {
        part_result = row_sum[i] * (row_sum[rsize - 1] - row_sum[i]);
        if (part_result > result)
            result = part_result;
    }

    for (size_t i = 0; i < csize - 1; i++) {
        part_result = col_sum[i] * (col_sum[csize - 1] - col_sum[i]);
        if (part_result > result)
            result = part_result;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    vector<vector<int> > arr(N, vector<int>(M));
    vector<int> row_sum(N, 0);
    vector<int> col_sum(M, 0);
    char buf[256];

    for (size_t i = 0; i < N; i++) {
        cin >> buf;
        for (size_t j = 0; j < M; j++) {
            arr[i][j] = buf[j] - '0';
            row_sum[i] += arr[i][j];
            col_sum[j] += arr[i][j];
        }
    }

    for (size_t i = 1; i < N; i++)
        row_sum[i] += row_sum[i - 1];

    for (size_t i = 1; i < M; i++)
        col_sum[i] += col_sum[i - 1];

    long long result = -__INT32_MAX__;
    long long part_result = 0;

    for (size_t i = 0; i < N - 1; i++) {
        part_result = row_sum[i] * cal(make_pair(i + 1, 0), make_pair(N - 1, M - 1), arr);
        if (part_result > result)
            result = part_result;
        part_result = cal(make_pair(0, 0), make_pair(i, M - 1), arr) * (row_sum[N - 1] - row_sum[i]);
        if (part_result > result)
            result = part_result;
    }

    for (size_t i = 0; i < M - 1; i++) {
        part_result = col_sum[i] * cal(make_pair(0, i + 1), make_pair(N - 1, M - 1), arr);
        if (part_result > result)
            result = part_result;
        part_result = cal(make_pair(0, 0), make_pair(N - 1, i), arr) * (col_sum[M - 1] - col_sum[i]);
        if (part_result > result)
            result = part_result;
    }

    cout << result << '\n';
    return 0;
}