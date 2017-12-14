#include "lab_list.h"
#include <stdio.h>
#include <malloc.h>

//自用函数部分//
//------------//
ListNode* node_constructor(void *itemData, size_t size){
    ListNode *node = (ListNode*)malloc(sizeof(size_t)+ 2*sizeof(ListNode*)+ size);
    node->data = itemData;
    node->data_size = size;
    node->prev = node->next = &__nullNode;
    return node;
}

void node_destructor(ListNode *node){
    printf("node with value:%d destructed\n",*(int*)node->data);
    free(node->data);
}

ListIterator iter_constructor(ListNode *listNode){
    ListIterator iter;
    iter.node = listNode;
    return iter;
}

int compareNode(const ListNode *node1, const ListNode *node2){
    return node1->data==node2->data;
}

int compareIter(ListIterator iter1, ListIterator iter2){
    return (iter1.node == iter2.node);
}

//API部分//
//-------//

ListDescriptor list_constructor(){
    ListDescriptor list;
    list.size = 0;
    list.front = list.back = &__nullNode;
    return list;
}

void list_push_back(ListDescriptor* desc, void* elem, int size) {
    ListNode *node = node_constructor(elem, (size_t)size);
    if(desc->size == 0){
        desc->front = node;
    }
    desc->back->next = node;
    node->prev = desc->back;
    desc->back = node;
    desc->size += 1;
}

void list_push_front(ListDescriptor* desc,void* elem,int size){
    ListNode *node = node_constructor(elem, (size_t)size);
    if(desc->size == 0){
        desc->back = node;
    }
    desc->front->prev = node;
    node->next = desc->front;
    desc->front = node;
    desc->size += 1;
}

ListIterator begin(ListDescriptor* desc){
    return iter_constructor(desc->front);
}

ListIterator end(ListDescriptor* desc){
    return iter_constructor(&__nullNode);
}

void* iter_dereference(ListIterator iter){
    return iter.node->data;
}

ListIterator iter_next(ListIterator iter){
    return iter_constructor(iter.node->next);
}

ListIterator iter_prev(ListIterator iter){
    return iter_constructor(iter.node->prev);
}
int list_size(ListDescriptor* desc){
    return desc->size;
}
void list_pop_front(ListDescriptor* desc){
    desc->front->next->prev = desc->front->prev;
    ListNode *temp = desc->front;
    desc->front = desc->front->next;
    node_destructor(temp);
    desc->size -= 1;
}

void list_pop_back(ListDescriptor* desc){
    desc->back->prev->next = desc->back->next;
    ListNode *temp = desc->back;
    desc->back = desc->back->prev;
    node_destructor(temp);
    desc->size -= 1;
}

void list_erase(ListDescriptor* desc,ListIterator iter){
    if(!compareNode(iter.node, desc->front)) {
        iter.node->prev->next = iter.node->next;
    }
    if(!compareNode(iter.node, desc->back)) {
        iter.node->next->prev = iter.node->prev;
    }
    node_destructor(iter.node);
    desc->size -= 1;
}

void list_clear(ListDescriptor* desc){
    for(ListIterator iter= begin(desc); !compareIter(iter, end(desc)); iter=iter_next(iter)){
        printf("node with value:%d destructed\n",*(int*)iter.node->data);
        free(iter_dereference(iter));
    }
    desc->size = 0;
    desc->front = desc->back = &__nullNode;
}

void list_destructor(ListDescriptor* desc){
    list_clear(desc);
}