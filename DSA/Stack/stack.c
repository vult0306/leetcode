#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "main.h"

static int top = 0;
static int size = 0;

static int* stack = NULL;
int stack_init(size_t len) {
    if (len > STACK_MAX_SIZE)
        return -1;

    stack = (int*)malloc(len * sizeof(int));
    if (stack != NULL) {
        size = len;
        return size;
    }

    return -1;
}

void stack_uninit(void) {
    if (stack != NULL)
        free(stack);
}

// IsFull: Checks if the stack is full (in case of fixed-size arrays).
bool stack_is_full(void) {
    return (top == size);
}

// IsEmpty: Checks if the stack is empty.
bool stack_is_empty(void) {
    return (top == 0);
}

// Push: Adds an element to the top of the stack.
void stack_push(int data) {
    if (!stack_is_full())
        stack[top++] = data;
}

// Pop: Removes the top element from the stack.
int stack_pop(int* data) {
    if (!stack_is_empty()) {
        if (data != NULL)
            *data = stack[top-1];
        top--;
    } else {
        return -1;
    }
    return 0;
}

// Peek: Returns the top element without removing it.
int stack_peek(int* data) {
    if (!stack_is_empty()) {
        *data = stack[top-1];
    } else {
        return -1;
    }
    return 0;
}

void stack_print(void) {
    for (int i=0; i<top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\r\n");
}