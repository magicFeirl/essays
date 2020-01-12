#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct node {
    int data; //结点数据域，未实现ADT

    struct node* parent; //父节点
    struct node* left;
    struct node* right;
}Node, *PNode;

typedef struct tree {
    PNode root;
}Tree, *PTree;

//前、中序遍历的结点操作函数原形
typedef void (* TreeFunc)(PNode node);

/**
* 创建一颗树对象
* @param  root 根结点指针
* @return 树对象
*/
PTree createTree(PNode root);

/**
* 创建一个结点对象
* @param  val 结点值
* @return 结点对象
*/
PNode createNode(int val);

/**
* 按指定值查找结点
* @param  root 根结点指针
* @param  val 要查找的结点值
* @return 返回一个结点，如果未找到指定结点则返回NULL
*/
PNode findNode(PNode root,int val);

/**
* 判断指定节点是否为叶子结点
* @param  node 结点指针
* @return 若该节点为叶子结点，返回true，否则返回false
*/
bool isLeafNode(PNode node);

/**
* 判断指定节点是否左子孩子
* @param  node 结点指针
* @return 若该节点为左子孩子，返回true，否则返回false
*/
bool isLeftChild(PNode node);

/**
* 在指定树中插入一个值
* @param tree 树对象
* @param val 值
*/
void insert(PTree tree, int val);

/**
* 移除指定树中的指定结点
* @param node 结点
*/
void removeNode(PNode node);

/**
* 先序遍历树
* @param root 根节点
* @param func 指定遍历函数
*/
void preorder(PNode root,TreeFunc func) ;

/**
* 中序遍历树
* @param root 根节点
* @param func 指定遍历函数
*/
void inorder(PNode root,TreeFunc func) ;

#endif // TREE_H_INCLUDED
