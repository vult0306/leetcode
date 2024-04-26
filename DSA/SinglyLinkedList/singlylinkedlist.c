#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "main.h"

node_t* new_node(int value) {
    node_t* new = (node_t*)malloc(sizeof(node_t));
    new->value = value;
    new->next = NULL;
    return new;
}

node_t* construct_list(int* array, int N) {
    if (N <= 0)
        return NULL;

    node_t* head = new_node(array[0]);
    node_t* node = head;
    for (int i=1; i<N; i++) {
        node->next = new_node(array[i]);
        node = node->next;
    }
    return head;
}

void print_list(node_t* head) {
    while(head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\r\n");
}

void push(node_t* head, int value) {
    if (head != NULL) {
        node_t* node = new_node(head->value);
        node->next = head->next;
        head->value = value;
        head->next = node;
    }
}

void insert(node_t* p_node, int value) {
    if (p_node != NULL) {
        node_t* node = new_node(value);
        node->next = p_node->next;
        p_node->next = node;
    }
}

void append(node_t* head, int value) {
    if (head != NULL) {
        while (head->next != NULL) {
            head = head->next;
        }
        head->next = new_node(value);
    }
}

node_t* search(node_t* head, int value) {
    while(head != NULL && head->value != value) {
        head = head->next;
    }
    return head;
}

void delete(node_t* head, int value) {
    node_t* prev = NULL;
    while(head != NULL && head->value != value) {
        prev = head;
        head = head->next;
    }
    if (head != NULL) {
        prev->next = head->next;
        free(head);
    }
}

int len(node_t* head) {
    int ret = 0;
    while(head != NULL)
        ret++;
    return ret;
}

void swap(node_t* a, node_t *b) {
    node_t* node = new_node(a->value);
    node->next = a->next;
    a->value = b->value;
    a->next = b->next;
    b->value = node->value;
    b->next = node->next;
}

// O(N), O(N)
node_t* lazy_reverse(node_t* head) {
    // find tail
    node_t* new_head = new_node(head->value);

    while(head->next != NULL) {
        push(new_head, head->next->value);
        head = head->next;
    }
    return new_head;
}

// O(N), O(1)
node_t* reverse(node_t* head) {
    // find tail
    node_t* prev = NULL;
    node_t* cur = head;
    node_t* next = NULL;

    while(cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}