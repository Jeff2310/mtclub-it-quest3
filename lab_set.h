#ifndef LAB_SET_H
#define LAB_SET_H

#include "labafx.h"

struct lab__set_st{

};

struct lab__set_iter_st{

};

// DO NOT MODIFY BELOW

typedef struct lab__set_st SetDescriptor;
typedef struct lab__set_iter_st SetIterator;

struct lab__set_api_st{
    SetDescriptor (*constructor)(Comparator compfunc);
    int (*size)(SetDescriptor* desc);
    void (*insert)(SetDescriptor* desc,void* key,int size);
    SetIterator (*find)(SetDescriptor* desc,void* key,int size);
    void (*erase)(SetDescriptor* desc,SetIterator it);
    SetIterator (*begin)(SetDescriptor* desc);
    SetIterator (*end)(SetDescriptor* desc);
    SetIterator (*iter_prev)(SetIterator it);
    void* (*iter_dereference)(SetIterator it);
    SetIterator (*iter_next)(SetIterator it);
    void (*clear)(SetDescriptor* desc);
    void (*destructor)(SetDescriptor* desc);
};

typedef struct lab__set_api_st SetAPI;
extern SetAPI set;

#endif