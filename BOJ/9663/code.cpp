#include <stdio.h>

#include <vector>

using namespace std;

vector<pair<int, int>> position;

bool can_put(int x, int y) {
    for (auto k : position) {
        if (k.first == x || k.second == y || (x - k.first) == (y - k.second) ||
            (x - k.first) == -1 * (y - k.second)) {
            return false;
        }
    }
    return true;
}

int queen(int k, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (can_put(k, i)) {
            if (k == size - 1)
                count++;
            else {
                position.push_back(make_pair(k, i));
                count += queen(k + 1, size);
                position.pop_back();
            }
        }
    }
    return count;
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", queen(0, N));
    return 0;
}