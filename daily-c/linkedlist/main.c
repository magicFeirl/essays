#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void prtList(PLNODE pnode){
    printf("%d\n",*((int *)pnode->data));
}

//又是惯例的链表。刻意练习，熟练度up（他力本愿）

void LinkedListTest(){
    PLinkedList list;
    int data = 10;
    int data1 = 11;
    list = createList();
    addFirst(list,&data);
    addFirst(list,&data1);
    addFirst(list,&data1);
    addFirst(list,&data);

    deleteNode(list,getNode(list,2));
    data1+=10;

    //removeFirst(list);
    //removeLast(list);

    insertData(list,getNode(list,0),&data1);

    traverseListF(list,prtList);
}
int main()
{
    LinkedListTest();
    return 0;
}
