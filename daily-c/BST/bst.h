#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct node {
    int data; //���������δʵ��ADT

    struct node* parent; //���ڵ�
    struct node* left;
    struct node* right;
}Node, *PNode;

typedef struct tree {
    PNode root;
}Tree, *PTree;

//ǰ����������Ľ���������ԭ��
typedef void (* TreeFunc)(PNode node);

/**
* ����һ��������
* @param  root �����ָ��
* @return ������
*/
PTree createTree(PNode root);

/**
* ����һ��������
* @param  val ���ֵ
* @return ������
*/
PNode createNode(int val);

/**
* ��ָ��ֵ���ҽ��
* @param  root �����ָ��
* @param  val Ҫ���ҵĽ��ֵ
* @return ����һ����㣬���δ�ҵ�ָ������򷵻�NULL
*/
PNode findNode(PNode root,int val);

/**
* �ж�ָ���ڵ��Ƿ�ΪҶ�ӽ��
* @param  node ���ָ��
* @return ���ýڵ�ΪҶ�ӽ�㣬����true�����򷵻�false
*/
bool isLeafNode(PNode node);

/**
* �ж�ָ���ڵ��Ƿ����Ӻ���
* @param  node ���ָ��
* @return ���ýڵ�Ϊ���Ӻ��ӣ�����true�����򷵻�false
*/
bool isLeftChild(PNode node);

/**
* ��ָ�����в���һ��ֵ
* @param tree ������
* @param val ֵ
*/
void insert(PTree tree, int val);

/**
* �Ƴ�ָ�����е�ָ�����
* @param node ���
*/
void removeNode(PNode node);

/**
* ���������
* @param root ���ڵ�
* @param func ָ����������
*/
void preorder(PNode root,TreeFunc func) ;

/**
* ���������
* @param root ���ڵ�
* @param func ָ����������
*/
void inorder(PNode root,TreeFunc func) ;

#endif // TREE_H_INCLUDED
