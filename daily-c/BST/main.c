#include "bst.h"
//使用该BST的前提假设：没有重复数据

void prtNodeVal(PNode node){
    printf("%d ", node->data);
}

int main()
{
    PNode root = createNode(5);
    PTree tree = createTree(root);
    int arr[] = {1, 2, 3, 4, -1, 1};
    int size = sizeof(arr)/sizeof(arr[0]), i;

    for(i=0;i<size;i++) {
        insert(tree, arr[i]);
    }

    //removeNode(findNode(tree->root, findNode(tree->root,3)));
    //preorder(tree->root, prtNodeVal);
    //printf("\n");
    inorder(tree->root, prtNodeVal);

    return 0;
}
