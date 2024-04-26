#ifndef MAIN_H
#define MAIN_H

typedef struct node {
    int value;
    struct node* next;
} node_t;

node_t* construct_list(int* array, int N);
void print_list(node_t* head);
void push(node_t* head, int value);
void insert(node_t* p_node, int value);
void append(node_t* head, int value);
node_t* search(node_t* head, int value);
void delete(node_t* head, int value);
int len(node_t* head);
node_t* lazy_reverse(node_t* head);
node_t* reverse(node_t* head);
#endif
