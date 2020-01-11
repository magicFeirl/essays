#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
}Node,*PNode;

typedef struct tree {
    PNode root;
}Tree,*PTree;

PNode createNode(int val){
    PNode node = (PNode)malloc(sizeof(Node));
    node->left = node->right = NULL;
    node->val = val;

    return node;
}

void insert(PTree tree,int data){
    PNode node = createNode(data);

    if(tree->root == NULL){
        tree->root = node;
    }else{
        PNode temp = tree->root;

        while(temp != NULL){
            if(data > temp->val){
                if(temp->right == NULL){
                    temp->right = node;
                    break;
                }else{
                    temp = temp->right;
                }
            }else if(data < temp->val){
                if(temp->left == NULL){
                    temp->left = node;
                    break;
                }else{
                    temp = temp->left;
                }
            }
        }
    }
}

void preorder(PNode node){
    if(node != NULL){
        printf("%d ",node->val);

        preorder(node->left);
        preorder(node->right);
    }
}

PTree createTree(){
    PTree tree = (PTree)malloc(sizeof(Tree));
    tree->root = NULL;

    return tree;
}

int main()
{
    int arr[] = {1,5,6,8,10,3,2},i,
    size = sizeof(arr)/sizeof(arr[0]);

    PTree bst = createTree();

    for(i=0;i<size;i++){
        insert(bst,arr[i]);
    }

    preorder(bst->root); //1 5 3 2 6 8 10
    printf("\n");

    return 0;
}
