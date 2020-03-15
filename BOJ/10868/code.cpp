#include <cstring>
#include <iostream>

#define MAX (1 << 18)
#define N_MAX 100010
#define AN_MAX 1000000001

using namespace std;

int arr[MAX + 1];
int tree[MAX + 1];

int arr_min(int a, int b) {
    if (a == -1)
        return b;
    if (b == -1)
        return a;

    if (arr[a] <= arr[b])
        return a;
    else
        return b;
}

int init_tree(int node = 1, int start = 1, int end = N_MAX) {
    if (start == end) {
        return tree[node] = start;
    } else {
        return tree[node] = arr_min(init_tree(node * 2, start, (start + end) / 2), init_tree(node * 2 + 1, (start + end) / 2 + 1, end));
    }
}

int tree_query(int node, int start, int end, int l, int r) {
    if (start > r || end < l)
        return -1;
    if (l <= start && end <= r)
        return tree[node];

    return arr_min(tree_query(node * 2, start, (start + end) / 2, l, r), tree_query(node * 2 + 1, (start + end) / 2 + 1, end, l, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    memset(arr, AN_MAX, sizeof(arr));
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    init_tree(1, 1, N);
    int l, r;

    for (int i = 1; i <= M; i++) {
        cin >> l >> r;
        cout << arr[tree_query(1, 1, N, l, r)] << '\n';
    }
    return 0;
}