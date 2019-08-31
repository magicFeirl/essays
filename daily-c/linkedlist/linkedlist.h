#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>

//���������ݶ���
typedef void * DATA;

//����ڵ㶨�壨˫������
typedef struct _LNODE{
   DATA data;
   struct _LNODE *next;
   struct _LNODE *prev;
}LNODE,*PLNODE;

//����ṹ����
typedef struct {
    PLNODE head;
    PLNODE tail;
    int size;
}LinkedList,*PLinkedList;

//ָ���ı�������ĺ����ĸ�ʽ
typedef void (* TRAVERSE_FUNC)(PLNODE pnode);

//����ΪҪʵ�ֵĻ������� ������������淶������ww

//����һ��������
PLinkedList createList();
//��ȡ������
int getListSize(PLinkedList pl);
//�ж������Ƿ�Ϊ��
bool isEmpty(PLinkedList pl);

//�������
bool addFirst(PLinkedList pl,DATA data);
bool addLast(PLinkedList pl,DATA data);
//��������
bool insertData(PLinkedList pl,PLNODE after,DATA data);
//ɾ������
bool deleteData(PLNODE pnode);
//ɾ�����
bool deleteNode(PLinkedList pl,PLNODE pnode);

//��ȡͷ/β����
DATA getLast(PLinkedList pl);
DATA getFirst(PLinkedList pl);
PLNODE getNode(PLinkedList pl,int index);

//�Ƴ�ͷ/β���
void removeFirst(PLinkedList pl);
void removeLast(PLinkedList pl);
//ʹ��ָ���ĺ���������������
void traverseListF(PLinkedList pl,TRAVERSE_FUNC pfunc);
void traverseListT(PLinkedList pl,TRAVERSE_FUNC pfunc);

//��ת����
void reverseList(PLinkedList pl);

#endif // LINKEDLIST_H_INCLUDED
