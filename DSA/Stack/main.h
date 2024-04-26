#ifndef MAIN_H
#define MAIN_H
#include <stdint.h>
#include <stdbool.h>

#define STACK_MAX_SIZE  128

int stack_init(size_t len);
void stack_uninit(void);
// IsFull: Checks if the stack is full (in case of fixed-size arrays).
bool stack_is_full(void);
// IsEmpty: Checks if the stack is empty.
bool stack_is_empty(void);
// Push: Adds an element to the top of the stack.
void stack_push(int data);
// Pop: Removes the top element from the stack.
int stack_pop(int* data);
// Peek: Returns the top element without removing it.
int stack_peek(int* data);
void stack_print(void);
#endif
