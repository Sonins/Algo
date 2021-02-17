#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int cal_score(bool base[3], int hit) {
    int score = 0;

    if (hit == 4) {
        score++;
        for (int i = 0; i < 3; i++) {
            score += base[i];
            base[i] = false;
        }
        return score;
    }

    for (int i = 0; i < hit; i++) {
        score += base[2 - i];
        base[2 - i] = false;
    }

    for (int i = 2; i - hit >= 0; i--) {
        base[i] = base[i - hit];
        base[i - hit] = false;
    }
    
    base[hit - 1] = true;
    return score;
}

int main() {
    int N;
    cin >> N;

    vector<int> order;
    for (int i = 2; i <= 9; i++) {
        order.push_back(i);
    }

    int hit[60][10];

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> hit[i][j];
        }
    }

    int inning = 0;
    int out = 0;
    bool base[3] = {0, };
    int score = 0;
    int ans = -1;
    vector<int> test;
    do {
        while (inning < N) {
            int cur;
            for (int i = 0; i < 3; i++) {
                cur = order[i];
                if (hit[inning][cur] == 0) {
                    out++;
                    if (out == 3) {
                        out = 0;
                        inning++;
                        for (int i = 0; i < 3; i++)
                            base[i] = false;
                        if (inning == N)
                            break;
                    }
                } else {
                    score += cal_score(base, hit[inning][cur]);
                }
            }
            
            if (inning == N) {
                break;
            }


            test.push_back(1);
            if (hit[inning][1] == 0) {
                out++;
                if (out == 3) {
                    out = 0;
                    inning++;
                    for (int i = 0; i < 3; i++)
                        base[i] = false;
                    if (inning == N) {
                        break;
                    }
                }
            } else {
                score += cal_score(base, hit[inning][1]);
            }

            for (int i = 3; i < 8; i++) {
                cur = order[i];
                test.push_back(cur);
                if (hit[inning][cur] == 0) {
                    out++;
                    if (out == 3) {
                        out = 0;
                        inning++;
                        for (int i = 0; i < 3; i++)
                            base[i] = false;
                        if (inning == N) {
                            break;
                        }
                    }
                } else {
                    score += cal_score(base, hit[inning][cur]);
                }
            }
            
        }
        inning = 0;
        test.clear();
        ans = max(ans, score);
        score = 0;
        for (int i = 0; i < 3; i++)
            base[i] = false;
        
    } while (next_permutation(order.begin(), order.end()));

    cout << ans << endl;
    return 0;
}