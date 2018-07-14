#include <stdlib.h>
#include <stdio.h>
#define NUM_NODES 7
#ifndef null
#define null (void*)0
#endif

/*
** Traverse the following structure
**         a
**      -------
**      b     c
**    ----- ----- 
**    d   e f   g
**
** to print out 'abdecfg'
**
*/
typedef struct Node
{
    char value;
    struct Node* left;
    struct Node*right;
};

int push(char val, struct Node* root, struct Node* left, struct Node* right )
{
    root->value = val;
    root->left = left;
    root->right = right;
}

void traverse(struct Node* curr)
{
    if(!curr) return;
    printf("%c", curr->value);
    traverse(curr->left);
    traverse(curr->right);
}

int main()
{
    struct Node* array = (struct Node*)malloc(sizeof(struct Node)*NUM_NODES);
    push('a', &array[0], &array[1], &array[2]);
    push('b', &array[1], &array[3], &array[4]);
    push('c', &array[2], &array[5], &array[6]);
    push('d', &array[3],  null,      null    );
    push('e', &array[4],  null,      null    );
    push('f', &array[5],  null,      null    );
    push('g', &array[6],  null,      null    );

    traverse(array);
    return 0;
}
