#include <cstdio>
#include <cstring>
#include <string>
int main() {
    char num1[20] = {0};
    char num2[20] = {0};
    scanf("%s", num1);
    scanf("%s", num1 + strlen(num1) * sizeof(char));
    scanf("%s", num2);
    scanf("%s", num2 + strlen(num2) * sizeof(char));
    printf("%lld\n", atoll(num1) + atoll(num2));
    return 0;
}