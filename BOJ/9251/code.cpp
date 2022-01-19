#include <stdio.h>
#include <algorithm>


using namespace std;

char str1[1001];
char str2[1001];
int lcs[1001][1001];

int main() {
    scanf("%s", str1);
    scanf("%s", str2);
    lcs[0][0] = 0;
    int _max = -1;

    for (int i = 1; str1[i - 1] != '\0'; i++) {
        for (int j = 1; str2[j - 1] != '\0'; j++) {
            if (str1[i - 1] == str2[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
            _max = max(lcs[i][j], _max);
        }
    }

    printf("%d\n", _max);

    return 0;
}