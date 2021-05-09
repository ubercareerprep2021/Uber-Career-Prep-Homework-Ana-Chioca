#include <stdlib.h>
#include <stdio.h>

typedef struct node_ NODE;
typedef struct list_ LIST;

struct node_{
    int item;
    NODE* next;
};

struct list_{
    int size;
    NODE* head;
    NODE* end;
};

LIST* createList(void){
    LIST* l = (LIST*)malloc(sizeof(LIST));
    if (l != NULL){
        l->head = (NODE*)malloc(sizeof(NODE));
        l->size = 0;
        l->head->next = NULL;
        l->end = NULL;
        return l;
    }
}

NODE* createNode(int n){
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->item = n;
    return node;
}

void push(NODE* node, LIST* l){
    if(l != NULL){
        node->next = NULL;

        // if it is the first node being inserted
        if (l->size == 0){
            l->head->next = node;
            l->end = node;
        } 
        
        else{
            l->end->next = node;
            l->end = node;
        }
        l->size++;
    }
}

void insertAt(NODE* node, LIST* l, int index){
    if(l != NULL){
        node->next = NULL;

        if (index == l->size){
            push(node, l);
        }

        else if (index == 0){
            NODE* aux = l->head->next;
            l->head->next = node;
            node->next = aux;
            l->size++;
        } 

        else{
            NODE *p, *q;
            p = l->head;
            for(int i = 0; i < index+1; i++){
                q = p;
                p = p->next;
            }
            q->next = node;
            node->next = p;
            l->size++;
        }

        
    }
}

NODE* pop(LIST* l){
    if(l != NULL){
        if (l->size == 0){
            printf("List is empty.");
            return NULL;
        }

        NODE *p, *q;
        for(p = l->head; p->next != NULL; p = p->next){
            q = p;
        }
        // printNode(q);
        if (p == NULL) return NULL;
        q->next = NULL;
        l->end = q;
        // printList(l);
        // free(q);
        l->size--;
        return p;
    }

}

void removeNode(LIST* l, uint index){
    if(l != NULL){
        if (index > l->size - 1) return;
        NODE *p, *q;
        p = l->head;
        for(int i = 0; i < index+1; i++){
            q = p;
            p = p->next;
        }
        if (p == NULL) return;

        // if there's only one item in the list
        if (l->head == l->end){
            l->head = NULL;
            l->end = NULL;
        }
        // if the item is at the end of the list
        if (p->next == NULL){
            q->next = NULL;
            l->end = q;
        }
        // if the item is in the middle of the list
        else{
            q->next = p->next;
        }
        free(p);
        l->size--;
    }
}

NODE* elementAt(LIST* l, uint index){
    if (l != NULL){
        if (index > l->size - 1) return NULL;
        NODE *p, *q;
        p = l->head;
        for(int i = 0; i < index+1; i++){
            q = p;
            p = p->next;
        }
        return p;
    }
}

uint size(LIST* l){
    return (uint)l->size;
}

LIST* reverseListIterative(LIST* list){
    if (list == NULL) return NULL;
    LIST* revList = createList();
    if (size(list) == 0) return revList;
    
    NODE *p, *q, *newNode;
    for(p = list->head->next; p != NULL; p = p->next){
        newNode = createNode(p->item);
        insertAt(newNode, revList, 0);
        q = p;
    }
    
    return revList;
}

LIST* reverseListStack(LIST* list){
    if (list == NULL) return NULL;
    LIST* revList = createList();
    if (size(list) == 0) return revList;
    
    NODE* myStack[size(list)];
    NODE *p, *q, *newNode;
    int index = 0;

    for(p = list->head->next; p != NULL; p = p->next){
        newNode = createNode(p->item);
        myStack[index] = newNode;
        q = p;
        index++;
    }

    for(;index > 0; index--){
        // printNode(myStack[index-1]);
        push(myStack[index-1], revList);
    }
    
    return revList;
}

void printList(LIST* l){
    if (l != NULL){
        NODE* aux = l->head->next;
        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
        printf("\n");
    }
}

void printNode(NODE* n){
    if (n == NULL){
        printf("Node is NULL\n");
    }
    else printf("Node item: %d\n", n->item);
}

void destroyList(LIST* l){
    NODE* aux1 = l->head->next;
    NODE* aux2;
    while (aux1 != NULL){
        aux2 = aux1->next;
        free(aux1);
        aux1 = aux2;
    }
    free(l->head);
    free(l);
}