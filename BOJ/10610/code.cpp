#include <stdio.h>
int main() {
    char c;
    int sum = 0;
    int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while ((c = getchar()) != EOF && c != '\n') {
        sum += c - '0';
        arr[c - '0']++;
    }

    if (!arr[0] || sum % 3) {
        printf("-1\n");
        return 0;
    }
    
    for (int i = 9; i >= 0; i--) {
        for (size_t j = 0; j < arr[i]; j++)
            printf("%d", i);
    }
    

    printf("\n");
    return 0;
}
