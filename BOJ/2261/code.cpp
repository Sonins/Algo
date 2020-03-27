#include <algorithm>
#include <iostream>
#include <vector>
#define x first
#define y second
using namespace std;

int dist(pair<int, int> p1, pair<int, int> p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool compy(pair<int, int> p1, pair<int, int> p2) {
    return p1.y < p2.y;
}

int closest_pair(vector<pair<int, int> >::iterator it, int N) {
    if (N == 2)
        return dist(it[0], it[1]);

    if (N == 3) {
        return min({dist(it[0], it[1]), dist(it[0], it[2]), dist(it[1], it[2])});
    }

    int k = min(closest_pair(it, N / 2), closest_pair(it + N / 2, N - N / 2));
    int mid = (it[N / 2 - 1].x + it[N / 2].x) / 2;

    vector<pair<int, int> > m;
    m.reserve(N);

    for (size_t i = 0; i < N; i++) {
        if ((mid - it[i].x) * (mid - it[i].x) < k)
            m.push_back(it[i]);
    }

    sort(m.begin(), m.end(), compy);

    int min_dist = k;
    int cur_dist;

    for (size_t i = 0; i < m.size(); i++) {
        for (size_t j = i + 1; j < m.size(); j++) {
            if ((m[j].y - m[i].y) * (m[j].y - m[i].y) > k) break;

            if (dist(m[i], m[j]) < min_dist)
                min_dist = dist(m[i], m[j]);
        }
    }
    return min_dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int, int> > v(N);

    for (auto it = v.begin(); it != v.end(); it++)
        cin >> it->x >> it->y;

    sort(v.begin(), v.end());

    cout << closest_pair(v.begin(), N) << '\n';
    return 0;
}