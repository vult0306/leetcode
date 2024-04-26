#include <stdio.h>
#include "main.h"
const int N = 20;
int main() {
    printf("Hello, World!\n");
    stack_init(N);
    for (int i=0; i<N; i++) {
        stack_push(i);
    }
    stack_print();

    stack_pop(NULL);
    stack_print();
    stack_pop(NULL);
    stack_print();
    stack_push(56);
    stack_print();
    stack_pop(NULL);
    stack_print();
    return 0;
}
