#include "bst.h"

PTree createTree(PNode root){
    PTree tree = (PTree)malloc(sizeof(Tree));
    assert(tree != NULL && root != NULL);
    tree->root = root;

    return tree;
}

PNode createNode(int val){
    PNode node = (PNode)malloc(sizeof(Node));
    assert(node != NULL);

    node->data = val;
    node->parent = node->left = node->right = NULL;

    return node;
}

void insert(PTree tree, int val){
    PNode node = createNode(val);

    if(tree->root == NULL) {
        tree->root = node;
    } else {
        PNode temp = tree->root;
        while(temp) {
            if(val < temp->data) {
                if(temp->left == NULL) {
                    node->parent = temp;
                    temp->left = node;
                    break;
                } else {
                    temp = temp->left;
                }
            } else if(val > temp->data) {
                node->parent = temp;
                if(temp->right == NULL) {
                    temp->right = node;
                    break;
                } else {
                    temp = temp->right;
                }
            }else {
                break;
            }
        }
    }
}

bool isLeafNode(PNode node) {
    return (node != NULL && node->left == NULL && node->right == NULL);
}

bool isLeftChild(PNode node) {
    if(node == NULL) {
        return false;
    } else {
        PNode parent = node->parent;
        return (parent != NULL && node->data < parent->data);
    }
}

PNode findNode(PNode root,int val) {
    assert(root != NULL);

    PNode temp = root;

    while(temp != NULL){
        if(temp->data < val) {
            temp = temp->right;
        } else if(temp->data > val) {
           temp = temp->left;
        } else {
            return temp;
        }
    }

    return NULL;
}

void removeNode(PNode node) {
    if(node == NULL) {
        return ;
    }

    /*
        删除结点的三种情况：
        1.仅有一个结点
        2.为叶子结点
        3.含父节点和子节点的根节点
    */

    PNode parent = node->parent;

    //1.若仅有一个结点
    if(parent == NULL && isLeafNode(node)) {
        free(node);
        return ;
    }

    //2.若指定结点为叶子结点
    if(isLeafNode(node)) {
        if(node->data > parent->data) {
            parent->right = NULL;
        }else{
            parent->left = NULL;
        }

        free(node);
        return ;
    }

    //3.该情况下若节点有右节点，右节点上移，否则左结点上移
    if(node->right != NULL) {
        if(isLeftChild(node)) {
            parent->left = node->right;
        }else{
            parent->right = node->right;
        }

        node->right->left = node->left;
        free(node);
    } else {

    }
}

void preorder(PNode root, TreeFunc func) {
    if(root != NULL) {
        func(root);
        preorder(root->left,  func);
        preorder(root->right, func);
    }
}

void inorder(PNode root, TreeFunc func) {
    if(root != NULL) {
        inorder(root->left, func);
        func(root);
        inorder(root->right,func);
    }
}

//不要问我为什么不写后序遍历，因为函数名忘了w


