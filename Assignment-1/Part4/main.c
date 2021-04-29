#include <stdlib.h>
#include <stdio.h>
#include "Part4.h"

int main(){ 
    LIST* list = createList();

    // pushing some nodes...
    NODE* n = createNode(4);
    push(n, list);
    NODE* m = createNode(1);
    push(m, list);
    NODE* p = createNode(9);
    push(p, list);

    printList(list);

    // Popping node:
    printf("Popping node:\n");
    NODE* poppedNode = pop(list);
    printNode(poppedNode);
    free(poppedNode);

    // Adding more nodes:
    printf("Pushing more nodes:\n");
    NODE* o = createNode(2);
    push(o, list);
    NODE* q = createNode(3);
    push(q, list);
    NODE* r = createNode(7);
    push(r, list);

    printList(list);

    printf("Removing element at index 2:\n");
    removeNode(list, 2);

    printList(list);

    printf("Size of list: %d\n", size(list));

    printf("Removing element at inexistent index:\n");
    removeNode(list, 20);

    printList(list);

    printf("Element at index 2:\n");
    NODE* element = elementAt(list, 2);
    printNode(element);

    printf("Element at index 8 (inexistent):\n");
    element = elementAt(list, 8);
    printNode(element);

    destroyList(list);
}