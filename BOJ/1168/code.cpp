#include <iostream>
#include <vector>
using namespace std;

#define MAX 1 << 18

int tree[MAX];
int N, K;

int tree_init(int start, int end, int node) {
    if (start == end) {
        tree[node] = 1;
        return 1;
    }
    int mid = (start + end) / 2;
    tree[node] = 
        tree_init(start, mid, node << 1) + tree_init(mid + 1, end, (node << 1) + 1);
    return tree[node];
}

int update(int start, int end, int node, int k) {
    tree[node]--;

    if (start == end) {
        if (tree[1] != 0)
            cout << start << ", ";
        else
            cout << start;
        return 0;
    }
    int mid = (start + end) / 2;
    if (k <= tree[node << 1]) { 
        return update(start, mid, node << 1, k);
    }
    else {
        k -= tree[node << 1];
        return update(mid + 1, end, (node << 1) + 1, k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    tree_init(1, N, 1);
    int k = 1;
    cout << '<';
    while (tree[1] != 0) {
        k = (k + K - 1) % tree[1];
        k = k == 0 ? tree[1] : k;
        update(1, N, 1, k);
    }
    cout << ">\n";
    return 0;
}