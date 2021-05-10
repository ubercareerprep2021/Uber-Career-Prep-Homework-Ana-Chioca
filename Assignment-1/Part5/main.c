#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

int main(){ 
    LIST* list = createList();

    // pushing some nodes...
    NODE* n = createNode(4);
    push(n, list);
    n = createNode(1);
    push(n, list);
    n = createNode(9);
    push(n, list);
    n = createNode(2);
    push(n, list);
    n = createNode(3);
    push(n, list);
    n = createNode(7);
    push(n, list);
    n = createNode(5);
    insertAt(n, list, 2);
    n = createNode(12);
    insertAt(n, list, size(list));

    printf("Initial list: ");
    printList(list);

    printf("\nReversed list - Iterative method: ");
    LIST* revListIt = reverseListIterative(list);
    printList(revListIt);

    printf("\nReversed list - Stack method: ");
    LIST* revListStack = reverseListStack(list);
    printList(revListStack);

    printf("\nReversed list - Recursive method: ");
    LIST* revListRecursive = reverseListRecursive(list);
    printList(revListRecursive);

    destroyList(list);
    destroyList(revListIt);
    destroyList(revListStack);
    destroyList(revListRecursive);

    return 0;
}