#include <iostream>
#include <vector>
#include <string>
using namespace std;

int operate(int a, int b, char op) {
    switch (op) {
        case '-':
            return a - b;
        case '+':
            return a + b;
        case '*':
            return a * b;
        default:
            fprintf(stderr, "not valid operator!\n");
            exit(1);
            break;
    }
}

int main() {
    int N;
    cin >> N;

    string buf;
    cin >> buf;

    int M = N / 2;
    int ans = -__INT32_MAX__;
    vector<int> cal;

    for (size_t i = 0; i < (1 << M); i++) {
        bool overlap = false;
        for (int j = 0; j < M; j++) {
            if ((i & (1 << j)) && (i & (1 << (j + 1)))) {
                overlap = true;
                break;
            }
        }

        if (overlap)
            continue;
        
        cal.clear();
        cal.push_back(buf[0] - '0');

        for (int j = 0; j < M; j++) {
            char op = buf[2 * j + 1];
            int operand = buf[2 * j + 2] - '0';
            int res;
            if (i & (1 << j)) {
                res = operate(cal.back(), operand, op);
                cal.pop_back();
                cal.push_back(res);
            } else {
                cal.push_back(op);
                cal.push_back(operand);
            }
        }

        int size = cal.size();
        int ret = cal[0];
        for (int j = 1; j <= size / 2; j ++) {
            ret = operate(ret, cal[2 * j], cal[2 * j - 1]);
        }
        ans = max(ans, ret);
    }
    cout << ans << endl;
    return 0;
}