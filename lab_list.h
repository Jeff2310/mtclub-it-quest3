#ifndef LAB_LIST_H
#define LAB_LIST_H

#include <stddef.h>


struct lab__list_node_st {
    void *data;                                      //通过void*指针和数据大小描述每个节点具体的数据
    size_t data_size;                                //---------------------------------------------
    struct lab__list_node_st *prev, *next;          //链表部分
};
extern struct lab__list_node_st __nullNode;

struct lab__list_iter_st{
    struct lab__list_node_st *node;
//    typedef struct lab__list_node_st _Node;
//    typedef struct lab__list_iter_st _Self;
};

struct lab__list_st{
    int size;
    struct lab__list_node_st *front;
    struct lab__list_node_st *back;
};


typedef struct lab__list_node_st ListNode;

// NOT MODIFY BELOW
typedef struct lab__list_st ListDescriptor;
typedef struct lab__list_iter_st ListIterator;

struct lab__list_api_st{
    ListDescriptor (*constructor)();
    void (*push_back)(ListDescriptor* desc,void* elem,int size);
    void (*push_front)(ListDescriptor* desc,void* elem,int size);
    ListIterator (*begin)(ListDescriptor* desc);
    ListIterator (*end)(ListDescriptor* desc);
    void* (*iter_dereference)(ListIterator iter);
    ListIterator (*iter_next)(ListIterator iter);
    ListIterator (*iter_prev)(ListIterator iter);
    int (*size)(ListDescriptor* desc);
    void (*pop_front)(ListDescriptor* desc);
    void (*pop_back)(ListDescriptor* desc);
    void (*erase)(ListDescriptor* desc,ListIterator iter);
    void (*clear)(ListDescriptor* desc);
    void (*destructor)(ListDescriptor* desc);
};

typedef struct lab__list_api_st ListAPI;

extern ListAPI list;

#endif