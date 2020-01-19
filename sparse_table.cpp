#include <ios>

#define MAX 100000
#define LOG_MAX 17
typedef long long ll;

/**
 * Sparse Table
 * function이 결합법칙이 성립하고 ( F(a, F(b, c)) == F(F(a, b), c) )
 * Arr라는 변하지 않는 배열이 존재할 때, 
 * Arr의 부분 수열을 Parmeter로 갖는 Function의 결과 값 계산을 위한 자료구조.
 * 
 * Sparse Table 을 T[i][j]로 정의할 때,
 * T[i][j] = function(Arr[i], Arr[i + 1], ... , Arr[i + 2^j - 1])
 * 가 성립한다. 이 때,
 * 
 * T[i + 2^j][j] = function(Arr[i + 2^j], Arr[i + 2^j + 1], ... , Arr[i + 2^(j + 1) - 1])
 * 이다. 따라서,
 * 
 * T[i][j + 1] = fucntion(Arr[i], Arr[i + 1], ... , Arr[i + 2^(j + 1) - 1])
 *             = fucntion(T[i][j], T[i + 2^j][j])
 * 
 * 이를 이용해서 Table을 초기화 할 수 있고, 비용은 O(NlogN).
*/

ll table[MAX][LOG_MAX];

// func는 최댓값을 구하는 것으로 했다.

ll func(ll a, ll b) {
    if (a > b)
        return a;
    else
        return b;
}

/**
 * 아래 init_table()이 제대로 작동하려면,
 * table[i][0]가 Arr[i]와 값이 같아야 한다.
 * 즉, 이 함수를 호출하기 전에 미리 main 함수에서 초기화를 해줘야 한다.
*/

void init_table() {
    for (int j = 1; j <= LOG_MAX; j++) {
        for (int i = 0; i < MAX; i++) {
            table[i][j] = func(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

/**
 * L ~ R 의 구간을
 * L ~ (L + 2^j - 1), (L + 2^j) ~ (L + 2^j + 2^(j`) - 1), ... ,(L + 2^j + 2^(j`) + 2^(j``) + ...) ~ R로
 * 잘개 쪼개서 쿼리를 한다.
 * 
 * 모든 정수는 2^k1 + 2^k2 + .. + 2^kj 로 표현 가능하므로 (이진수 생각하면 편할 듯)
 * L ~ R 의 구간 또한 위와 같이 쪼갤 수 있다.
 * 구간은 R - L + 1 과 같다.
*/

ll table_query(int L, int R) {
    ll result = __LONG_LONG_MAX__;

    for (int j = LOG_MAX; j >= 0; j--) {
        if ((R - L + 1) >= (1 << j)) {
            result = func(result, table[L][j]);
            L = L + (1 << j);
        }
    }

    return result;
}

int main() {
    
}