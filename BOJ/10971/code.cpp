#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int W[10][10];
    int N;
    cin >> N;

    vector<int> order;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++)
            cin >> W[i][j];
        order.push_back(i);
    }

    int sum = 0;
    int result = __INT32_MAX__;
    do {
        sum = 0;
        for (size_t i = 1; i < N; i++) {
            if (W[order[i - 1]][order[i]])
                sum += W[order[i - 1]][order[i]];
            else {
                sum = -1;
                break;
            }
            if (sum > result)
                break;
        }
        
        if (W[order[N - 1]][order[0]] && sum != -1 && sum < result)
            sum += W[order[N - 1]][order[0]];
        else 
            continue;

        if (result > sum)
            result = sum;
    } while (next_permutation(order.begin(), order.end()));

    cout << result << '\n';
    return 0;
}