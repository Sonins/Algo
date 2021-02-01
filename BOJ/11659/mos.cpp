#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 100010

using namespace std;

struct Query {
    int l, r, i;
    bool operator<(Query &x){
        if (l != x.l)
            return r < x.r;
        return l < x.l;
    }
};

vector<Query> query;
int arr[MAX];
int ans[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, l, r;
    cin >> N >> M;
    for (size_t i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 0; i < M; i++) {
        cin >> l >> r;
        query.push_back({l, r, i});
    }

    sort(query.begin(), query.end());

    int res = 0;
    l = query[0].l;
    r = query[0].r;
    
    for (int i = l; i <= r; i++) {
        res += arr[i];
    }
    ans[query[0].i] = res;

    for (int i = 1; i < M; i++) {
        while (l < query[i].l) res -= arr[l++];
        while (l > query[i].l) res += arr[--l];
        while (r < query[i].r) res += arr[++r];
        while (r > query[i].r) res -= arr[r--];
        ans[query[i].i] = res;
    }

    for (size_t i = 0; i < M; i++)
        cout << ans[i] << '\n';

    return 0;
}