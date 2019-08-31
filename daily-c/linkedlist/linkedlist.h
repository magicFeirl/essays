#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>

//链表结点数据定义
typedef void * DATA;

//链表节点定义（双向链表）
typedef struct _LNODE{
   DATA data;
   struct _LNODE *next;
   struct _LNODE *prev;
}LNODE,*PLNODE;

//链表结构定义
typedef struct {
    PLNODE head;
    PLNODE tail;
    int size;
}LinkedList,*PLinkedList;

//指定的遍历链表的函数的格式
typedef void (* TRAVERSE_FUNC)(PLNODE pnode);

//以下为要实现的基本功能 请忽视命名不规范等问题ww

//创建一个新链表
PLinkedList createList();
//获取链表长度
int getListSize(PLinkedList pl);
//判断链表是否为空
bool isEmpty(PLinkedList pl);

//添加数据
bool addFirst(PLinkedList pl,DATA data);
bool addLast(PLinkedList pl,DATA data);
//插入数据
bool insertData(PLinkedList pl,PLNODE after,DATA data);
//删除数据
bool deleteData(PLNODE pnode);
//删除结点
bool deleteNode(PLinkedList pl,PLNODE pnode);

//获取头/尾数据
DATA getLast(PLinkedList pl);
DATA getFirst(PLinkedList pl);
PLNODE getNode(PLinkedList pl,int index);

//移除头/尾结点
void removeFirst(PLinkedList pl);
void removeLast(PLinkedList pl);
//使用指定的函数遍历整个链表
void traverseListF(PLinkedList pl,TRAVERSE_FUNC pfunc);
void traverseListT(PLinkedList pl,TRAVERSE_FUNC pfunc);

//反转链表
void reverseList(PLinkedList pl);

#endif // LINKEDLIST_H_INCLUDED
