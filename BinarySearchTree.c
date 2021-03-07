#include<stdlib.h>
#include<stdio.h>

struct binaryTree {
    int data;
    struct binaryTree * right, * left;
};

typedef struct binaryTree node;

void insertintoTree(node ** tree, int val)
{
    node *temp = NULL;

    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insertintoTree(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insertintoTree(&(*tree)->right, val);
    }

}

void displayPreorder(node * tree)
{
    if(tree)
    {
        printf("%d ",tree->data);
        displayPreorder(tree->left);
        displayPreorder(tree->right);
    }
}

void displayInorder(node * tree)
{
    if (tree)
    {
        displayInorder(tree->left);
        printf("%d ",tree->data);
        displayInorder(tree->right);
    }
}

void displayPostorder(node * tree)
{
    if (tree)
    {
        displayPostorder(tree->left);
        displayPostorder(tree->right);
        printf("%d ",tree->data);
    }
}

void main()
{
    node *rootNode;

    rootNode = NULL;

    /* Inserting nodes into tree */
    insertintoTree(&rootNode, 21);
    insertintoTree(&rootNode, 13);
    insertintoTree(&rootNode, 29);
    insertintoTree(&rootNode, 9);
    insertintoTree(&rootNode, 25);
    insertintoTree(&rootNode, 7);
    insertintoTree(&rootNode, 23);
    insertintoTree(&rootNode, 17);
    insertintoTree(&rootNode, 32);
    insertintoTree(&rootNode, 11);
    insertintoTree(&rootNode, 3);
    insertintoTree(&rootNode, 24);
    insertintoTree(&rootNode, 27);

    /* Printing nodes of tree */
    printf("\n Pre Order Traversal:- ");
    displayPreorder(rootNode);
    printf("\n");

    printf("\n In Order Traversal:- ");
    displayInorder(rootNode);
    printf("\n");

    printf("\n Post Order Traversal:- ");
    displayPostorder(rootNode);
    printf("\n\n");
}
