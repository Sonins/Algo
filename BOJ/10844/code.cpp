#include <iostream>
#define DIV 1000000000
using namespace std;
int count_num[10][101];
int memo[101];
int main()
{
    int N;
    cin >> N;
    memo[1] = 9;

    for (size_t i = 1; i < 10; i++)
    {
        count_num[i][1] = 1;
    }
    int count_0or9;
    for (size_t i = 2; i <= N; i++)
    {
        count_num[1][i] += count_num[0][i - 1] % DIV;
        count_num[8][i] += count_num[9][i - 1] % DIV;
        for (size_t j = 1; j < 9; j++) {
            count_num[j + 1][i] += count_num[j][i - 1] % DIV;
            count_num[j - 1][i] += count_num[j][i - 1] % DIV;
            count_num[j + 1][i] %= DIV;
            count_num[j - 1][i] %= DIV;
        }
        count_0or9 = (count_num[0][i - 1] + count_num[9][i - 1]) % DIV;
        if (memo[i - 1] * 2 > count_0or9)
            memo[i] = (memo[i - 1] * 2 - count_0or9) % DIV;
        else
            memo[i] = (DIV - count_0or9 + memo[i - 1] * 2) % DIV;
    }
    cout << memo[N] << endl;
    return 0;
}