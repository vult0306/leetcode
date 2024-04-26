#include <stdio.h>
#include "main.h"

int main() {
    printf("Hello, World!\n");
    int array[5] = {4, 2, 6, 5, 8};
    node_t* head = construct_list(array, sizeof(array)/sizeof(array[0]));
    print_list(head);

    // push
    push(head, 1);
    print_list(head);

    // insert
    push(head->next->next, 7);
    print_list(head);

    // append
    append(head, 12);
    print_list(head);

    // search
    node_t* item = search(head, 8);
    if (item != NULL) {
        printf("item found: %d\n", item->value);
    } else {
        printf("item not found\n");
    }

    // lazy_reverse
    head = reverse(head);
    print_list(head);
    head = lazy_reverse(head);
    print_list(head);

    // delete
    delete(head,5);
    delete(head,40);
    print_list(head);
    return 0;
}
