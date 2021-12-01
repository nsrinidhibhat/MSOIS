#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

void test_new(){

    BST tree1 = bst_new();
    BST *tree = &tree1;
    assert(bst_count(tree) == 0);

    tree = bst_add(tree,10);
    tree = bst_add(tree,20);
    tree = bst_add(tree,30);

    assert (bst_count(tree) == 3);

}
void test_inorder()
{
    BST tree1 = bst_new();
    BST *tree = &tree1;

    tree = bst_add(tree,50);
    tree = bst_add(tree,20);
    tree = bst_add(tree,90);
    tree = bst_add(tree,25);
    tree = bst_add(tree,70);
    tree = bst_add(tree,60);
    tree = bst_add(tree,85);
    tree = bst_add(tree,35);
    tree = bst_add(tree,10);

    bst_inorder(tree);
    printf("\n");
    bst_preorder(tree);
    printf("\n");
    bst_postorder(tree);
}

int main()
{
    test_new();
    test_inorder();
    return 0;
}
