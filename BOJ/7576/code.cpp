#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int tomato[MAX][MAX];

const int xoff[] = {1, 0, -1, 0};
const int yoff[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> M >> N;

    queue<pair<int, int> > q;
    int tomatoNum = 0;

    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 1; j <= M; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
                q.push(make_pair(i, j));

            if (tomato[i][j] != -1)
                tomatoNum++;
        }
    }

    int qsize;
    int day = -1;
    int x, y;
    pair<int, int> cur;
    while (!q.empty() && tomatoNum) {
        qsize = q.size();
        day++;
        for (size_t i = 0; i < qsize; i++) {
            cur = q.front();
            q.pop();
            tomatoNum--;

            for (size_t i = 0; i < 4; i++) {
                x = cur.first + xoff[i];
                y = cur.second + yoff[i];
                if (x > 0 && x <= N && y > 0 && y <= M && !tomato[x][y]) {
                    tomato[x][y] = 1;
                    q.push(make_pair(x, y));
                }
            }
        }
    }

    if (tomatoNum > 0)
        cout << -1 << '\n';
    else
        cout << day << '\n';

    return 0;
}