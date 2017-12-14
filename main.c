//
// Created by jeff2 on 2017/12/13.
//

#include <stdio.h>
#include <malloc.h>
#include "lab_list.h"

extern ListDescriptor list_constructor();
extern void list_push_back(ListDescriptor* desc, void* elem, int size);
extern void list_push_front(ListDescriptor* desc,void* elem,int size);
extern ListIterator begin(ListDescriptor* desc);
extern ListIterator end(ListDescriptor* desc);
extern void* iter_dereference(ListIterator iter);
extern ListIterator iter_next(ListIterator iter);
extern ListIterator iter_prev(ListIterator iter);
extern int list_size(ListDescriptor* desc);
extern void list_pop_front(ListDescriptor* desc);
extern void list_pop_back(ListDescriptor* desc);
extern void list_erase(ListDescriptor* desc,ListIterator iter);
extern void list_clear(ListDescriptor* desc);
extern void list_destructor(ListDescriptor* desc);

extern int compareIter(ListIterator iter1, ListIterator iter2);

ListNode __nullNode;

ListAPI list;

void displayList(ListDescriptor *desc){
    printf("!!!The list now is as follows:\n");
    for(ListIterator it = list.begin(desc); !compareIter(it, end(desc)); it = list.iter_next(it)){
        printf("%d ",*(int*)list.iter_dereference(it));
    }
    putchar('\n');
}
int main(){
    list.constructor = list_constructor;
    list.push_back = list_push_back;
    list.push_front = list_push_front;
    list.begin = begin;
    list.end = end;
    list.iter_dereference = iter_dereference;
    list.iter_next = iter_next;
    list.iter_prev = iter_prev;
    list.size = list_size;
    list.pop_front = list_pop_front;
    list.pop_back = list_pop_back;
    list.erase = list_erase;
    list.clear = list_clear;
    list.destructor = list_destructor;

    ListDescriptor mylist = list.constructor();

    printf(">>>initializing list elements.\n");
    for(int i=1; i<=10; i++){
        int *temp = (int*) malloc(sizeof(int));
        *temp = i;
        list.push_back(&mylist,(void *)temp,sizeof(int));
    }
    printf(">>>done.\n");
    displayList(&mylist);
    printf(">>>popping the frist three elements.\n");
    for(int i=1; i<=3; i++){
        list_pop_front(&mylist);
    }
    displayList(&mylist);
    printf(">>>popping the last three elements.\n");
    for(int i=1; i<=3; i++){
        list_pop_back(&mylist);
    }
    displayList(&mylist);
    printf(">>>erasing the second element.\n");
    list.erase(&mylist, list.iter_next(list.begin(&mylist)));
    displayList(&mylist);
    printf(">>>destructing the list\n");
    list.destructor(&mylist);
}