#ifndef LAB_LIST_H
#define LAB_LIST_H

struct lab__list_st{

};

struct lab__list_iter_st{

};

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