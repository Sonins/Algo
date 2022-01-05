#include <string.h>

#include <cassert>
#include <iostream>
#include <stack>

#define MAX_EXECUTE 50000000
#define MEMORY_SIZE 100010
#define CODE_SIZE 4096

using namespace std;

int sm, sc, si;
int pointer;
unsigned char memory[MEMORY_SIZE];
bool executed[CODE_SIZE];
int input_pointer = 0;

char comm[CODE_SIZE];
char input[CODE_SIZE];
stack<int> return_point;

void pointer_increase() { pointer = (pointer + 1) % sm; }

void pointer_decrease() { pointer = (pointer + sm - 1) % sm; }

void value_increase() { memory[pointer] = (memory[pointer] + 1) % 256; }

void value_decrease() { memory[pointer] = (memory[pointer] + 255) % 256; }

bool is_pointer_zero() { return memory[pointer] == 0; }

void takes_input() {
    if (input_pointer < si)
        memory[pointer] = (unsigned char)input[input_pointer++];
    else
        memory[pointer] = (unsigned char)255;
}

int loop_end(int p) {
    int loop = 0;
    while (comm[p] != ']' || loop != 0) {
        if (comm[p] == '[') loop++;
        if (comm[p] == ']') loop--;
        p++;
    }
    return p;
}

void next_PC(int *PC) {
    switch (comm[*PC]) {
        case '[':
            if (is_pointer_zero()) {
                *PC = loop_end((*PC) + 1);
                return_point.pop();
            }
            break;
        case ']':
            if (!is_pointer_zero()) {
                *PC = return_point.top();
            } else {
                return_point.pop();
            }
            break;
    }
    *PC = *PC + 1;
}

void proceed(int *PC) {
    switch (comm[*PC]) {
        case '+':
            value_increase();
            break;
        case '-':
            value_decrease();
            break;
        case '<':
            pointer_decrease();
            break;
        case '>':
            pointer_increase();
            break;
        case '[':
            return_point.push(*PC);
            break;
        case ',':
            takes_input();
            break;
    }
    next_PC(PC);
}

void initialize(int *PC) {
    memset(memory, 0, MEMORY_SIZE * sizeof(unsigned char));
    memset(executed, 0, CODE_SIZE * sizeof(bool));
    memset(input, 0, CODE_SIZE * sizeof(char));
    memset(comm, 0, CODE_SIZE * sizeof(char));

    while (!return_point.empty()) return_point.pop();
    input_pointer = 0;
    pointer = 0;
    *PC = 0;
}

int main() {
    int T;
    scanf("%d", &T);
    int PC;
    while (T--) {
        initialize(&PC);
        scanf("%d %d %d", &sm, &sc, &si);
        scanf("%s", comm);
        scanf("%s", input);
        for (int i = 0; i < MAX_EXECUTE; i++) {
            proceed(&PC);
            if (PC == sc) break;
        }

        if (PC == sc)
            cout << "Terminates\n";
        else {
            memset(executed, 0, sizeof(bool) * CODE_SIZE);
            int start = sc;
            int end = 0;

            for (int i = 0; i < MAX_EXECUTE; i++) {
                executed[PC] = true;
                proceed(&PC);
                if (start > PC) start = PC;
                if (end < PC) end = PC;
            }

            printf("Loops %d %d\n", start - 1, end);
        }
    }
}