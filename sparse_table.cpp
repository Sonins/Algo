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