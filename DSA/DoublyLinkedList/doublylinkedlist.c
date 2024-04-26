#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "main.h"

node_t* new_node(int value) {
    node_t* new = (node_t*)malloc(sizeof(node_t));
    new->value = value;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

node_t* construct_list(int* array, int N) {
    if (N <= 0)
        return NULL;

    node_t* head = new_node(array[0]);
    node_t* node = head;
    for (int i=1; i<N; i++) {
        node->next = new_node(array[i]);
        node->next->prev = node;
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

node_t* push(node_t* head, int value) {
    node_t* node = head;
    if (head != NULL) {
        node = new_node(value);
        node->next = head;
        head->prev = node;
    }
    return node;
}

void insert(node_t* p_node, int value) {
    if (p_node != NULL) {
        node_t* node = new_node(value);
        node->next = p_node->next;
        if (p_node->next != NULL)
            p_node->next->prev = node;
        node->prev = p_node;
        p_node->next = node;
    }
}

void append(node_t* head, int value) {
    if (head != NULL) {
        while (head->next != NULL) {
            head = head->next;
        }
        head->next = new_node(value);
        head->next->prev = head;
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
        if (head->next != NULL)
            head->next->prev = prev;
        free(head);
    }
}

int len(node_t* head) {
    int ret = 0;
    while(head != NULL)
        ret++;
    return ret;
}