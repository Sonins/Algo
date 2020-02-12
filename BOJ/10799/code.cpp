#include <stdio.h>
#define MAX 100010
using namespace std;

int main() {
    int top = 0;
    char str[MAX];
    int answer = 0;
    scanf("%s", str);
    
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            top++;
        } else if (str[i - 1] == '(') {
            top--;
            answer += top;
        } else {
            top--;
            answer++;
        }
    }
    
    printf("%d\n", answer);
    return 0;
}