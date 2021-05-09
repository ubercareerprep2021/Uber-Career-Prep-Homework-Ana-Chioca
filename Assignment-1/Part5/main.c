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

    printList(list);

    LIST* revListIt = reverseListIterative(list);
    printList(revListIt);

    LIST* revListStack = reverseListStack(list);
    printList(revListStack);

    destroyList(list);
    destroyList(revListIt);
    destroyList(revListStack);
}