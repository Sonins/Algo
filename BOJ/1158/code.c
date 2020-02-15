#include <stdio.h>
#include <stdlib.h>
#define MALLOC(p, s) \
    if ((p = (typeof(p)) malloc(s)) == NULL) { \
        fprintf(stderr, "insufficient memory!\n"); \
        exit(EXIT_FAILURE); \
    }

typedef struct _n {
    int key;
    struct _n * next;
    struct _n * before;
} node;


node* init_list(int n) {
    node * ptr;
    MALLOC(ptr, sizeof(node));
    node * first = ptr;
    for (size_t i = 1; i <= n; i++) {
        MALLOC(ptr->next, sizeof(node));
        ptr->next->before = ptr;
        ptr = ptr->next;
        ptr->key = i;
    }
    ptr->next = first;
    first->before = ptr;
    return first;
}

node* pop(int k, node* ptr) {
    node* pt = ptr;
    for (size_t i = 0; i < k; i++) {
        pt = pt->next;
    }
    pt->before->next = pt->next;
    pt->next->before = pt->before;
    return pt;
}

int main() {
    int N;
    int K;
    scanf("%d", &N);
    scanf("%d", &K);
    node* ptr = init_list(N);

    for (size_t i = 0; i < N; i++)
    {
        printf("%d ", ptr->key);
        ptr = ptr->next;
    }
    

    for (size_t i = 0; i < N; i++) {
        ptr = pop(3, ptr);
        printf("%d\n", ptr->key);
        free(ptr);
    }
    return 0;
}