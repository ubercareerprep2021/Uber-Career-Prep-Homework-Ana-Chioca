#ifndef LINKEDLIST_H
    #define LINKEDLIST_H


    typedef struct node_ NODE;
    typedef struct list_ LIST;

    LIST* createList(void);
    NODE* createNode(int n);
    void push(NODE* node, LIST* l);
    void insertAt(NODE* node, LIST* l, int index);
    NODE* pop(LIST* l);
    void removeNode(LIST* l, uint index);
    NODE* elementAt(LIST* l, uint index);
    uint size(LIST* l);
    LIST* reverseListIterative(LIST* list);
    LIST* reverseListStack(LIST* list);
    LIST* reverseListRecursive(LIST* list);
    void printList(LIST* l);
    void printNode(NODE* n);
    void destroyList(LIST* l);

#endif

