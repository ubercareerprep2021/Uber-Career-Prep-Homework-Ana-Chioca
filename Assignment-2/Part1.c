#include <stdlib.h>
#include <stdio.h>


typedef struct node NODE;
typedef struct tree TREE;

struct node {
    int value;
    struct node* left;
    struct node* right;
};

struct tree{
    NODE* root;
};

NODE* newNode(int val){
    NODE* n = malloc(sizeof(NODE));
    n->value = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void printRecursion(NODE* n){
    if (!n) return;

    printf("%d ", n->value);
    printRecursion(n->left);
    printRecursion(n->right);
}

void printTree(TREE* t){
    if (!t) return;
    printRecursion(t->root);
    return;
}

int heightNode(NODE *n){
    if (!n) return 0;

    else {
        if (heightNode(n->left) > heightNode(n->right)) return heightNode(n->left)+1;
        return heightNode(n->right) + 1;
    }
}

int height(TREE* t){
    if (!t) return 0;

    return heightNode(t->root);
}

void printLevel(NODE* n, int level){
    if (!n) return;
    
    if (level == 1){
        printf("%d ", n->value);
        return;
    }

    if (level > 1){
        printLevel(n->left, level-1);
        printLevel(n->right, level-1);
    }
}

void printLevels(TREE *t){
    if (!t) return;
    int treeheight = height(t);

    for (int i = 1; i <= treeheight; i++){
        printf("Level %d: ", i);
        printLevel(t->root, i);
        printf("\n");
    }
}

int main(){
    TREE* t = malloc(sizeof(TREE));
    t->root = newNode(1);
    t->root->left = newNode(7);
    t->root->right = newNode(17);
    t->root->right->left = newNode(6);
    t->root->right->right = newNode(3);

    printf("Exercise 1:\n");
    printTree(t);

    printf("\n\nExercise 2:\n");
    printLevels(t);

    printf("\n\nExercise 3:\n");
    printf("Number of levels in tree: %d\n", height(t));

    return 0;
}
