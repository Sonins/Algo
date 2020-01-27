#include <iostream>
#define DIV 1000000000
using namespace std;
int count_num[10][101];
int main()
{
    int N;
    cin >> N;
    int sum = 0;

    for (size_t i = 1; i < 10; i++)
    {
        count_num[i][1] = 1;
    }
    for (size_t i = 2; i <= N; i++)
    {
        count_num[0][i] = count_num[1][i - 1] % DIV;
        count_num[9][i] = count_num[8][i - 1] % DIV;
        for (size_t j = 1; j <= 8; j++)
            count_num[j][i] = (count_num[j - 1][i - 1] + count_num[j + 1][i - 1]) % DIV;
    }
    for (size_t i = 0; i < 10; i++) {
        sum += count_num[i][N] % DIV;
        sum %= DIV;
    }
    cout << sum << endl;
    return 0;
}