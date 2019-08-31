//����ľ���ʵ��
#include "linkedlist.h"
#define checkMem(P) if(!(P)) goto err

static PLNODE createNode(){
    return (PLNODE)malloc(sizeof(LNODE));
}

static PLNODE addNodeData(DATA data){
    PLNODE node = createNode();
    checkMem(node);

    node->data = data;
    node->next = node->prev = NULL;

    return node;

    err:
        return NULL;
}

static void firstAdd(PLinkedList pl,PLNODE node){
    pl->head = pl->tail = node;
}

//����һ��������
PLinkedList createList(){
    PLinkedList nlist = (PLinkedList)malloc(sizeof(LinkedList));
    nlist->head = nlist->tail = NULL;
    nlist->size = 0;

    return nlist;
}

//�ж������Ƿ�Ϊ��
bool isEmpty(PLinkedList pl){
    return pl->size == 0;
}

int getListSize(PLinkedList pl){
    return pl->size;
}

//�������
bool addFirst(PLinkedList pl,DATA data){
    PLNODE node = addNodeData(data);
    checkMem(node);

    if(isEmpty(pl)){
        firstAdd(pl,node);
    }else{
        node->next = pl->head;
        pl->head = node;
        pl->head->next->prev = node;
    }

    pl->size++;

    return true;

    err:
        return false;
}

bool addLast(PLinkedList pl,DATA data){
     PLNODE node = addNodeData(data);
     checkMem(node);

     if(isEmpty(pl)){
        firstAdd(pl,node);
     }else{
        node->prev = pl->tail;
        pl->tail->next = node;
        pl->tail = node;
     }

     pl->size++;

     return true;

     err:
         return false;
}

//��������
bool insertData(PLinkedList pl,PLNODE after,DATA data){
    checkMem(pl);
    checkMem(after);

    PLNODE p = addNodeData(data);
    checkMem(p);

    if(after == pl->tail){
        pl->tail->next = p;
        p->prev = pl->tail;
        pl->tail = p;
    }else{
        p->next = after->next;
        after->next = p;
        p->prev = after;
    }

    err:
        return false;
}

//ɾ������
bool deleteData(PLNODE pnode){
    checkMem(pnode);
    free(pnode->data);
    return true;

    err:
        return false;
}

//ɾ����ͷ
void removeFirst(PLinkedList pl){
    PLNODE node = pl->head;
    pl->head = node->next;
    free(node->data);
    free(node);
}

//ɾ����β
void removeLast(PLinkedList pl){
    PLNODE node = pl->tail;
    node->prev->next = NULL;
    free(node->data);
    free(node);
}

//ʹ��ָ���ĺ���������������
void traverseListF(PLinkedList pl,TRAVERSE_FUNC pfunc){
    checkMem(pl);
    PLNODE node = pl->head;
    while(node){
        pfunc(node);
        node = node->next;
    }

    err:return;
}

void traverseListT(PLinkedList pl,TRAVERSE_FUNC pfunc){
    checkMem(pl);
    PLNODE node = pl->tail;
    while(node){
        pfunc(node);
        node = node->prev;
    }

    err:return;
}

//��ת����
void reverseList(PLinkedList pl){
    checkMem(pl);
    if(pl->size == 1)
        return;

    PLNODE pc,pn,pp,tpr;
    pc = pl->head;
    pp = NULL;
    tpr = pc->next;

    while(pn){
       pn = pc->next;
       pc->next = pp;
       pp = pc;
       pc = pn;
    }

    pl->tail = pl->head;
    pl->head = pp;

    //�����η�תǰ��/���ָ��

    pp = NULL;
    pc = pl->head;

    while(pc){
        pc->prev = pp;
        pn = pc;
        pc = pc->next;
        pp = pn;
    }

    err:
        return;
}

//ɾ�����
bool deleteNode(PLinkedList pl,PLNODE pnode){
    checkMem(pnode);
    checkMem(pl);

    if(pnode == pl->head){
       removeFirst(pl);
    }else if(pnode == pl->tail){
        removeLast(pl);
    }else{
        pnode->prev->next = pnode->next;
        pnode->next->prev = pnode->prev;
        free(pnode->data);
        free(pnode);
    }

    pl->size--;
    return true;

    err:
        return false;
}

DATA getLast(PLinkedList pl){
    //������
    checkMem(pl);
    checkMem(pl->head);

    return pl->head->data;

    err:return NULL;
}

DATA getFirst(PLinkedList pl){
    checkMem(pl);
    checkMem(pl->head);

    return pl->tail->data;

    err:return NULL;
}

PLNODE getNode(PLinkedList pl,int index){

    checkMem(pl);
    int size = pl->size-1;
    if(index>size){
        return NULL;
    }
    if(index == size)
        return getLast(pl);

    int i;
    PLNODE p = pl->head;
    checkMem(p);

    for(i=0;i<index;i++)
        p = p->next;
    return p;

    err:
        return NULL;
}
