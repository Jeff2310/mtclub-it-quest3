#ifndef LAB_UNORDERED_MAP_H
#define LAB_UNORDERED_MAP_H

#include "labafx.h"

struct lab__unordered_map_st{

};

struct lab__unordered_map_iter_st{

};

// DO NOT MODIFY BELOW
typedef struct lab__unordered_map_st UnorderedMapDescriptor;
typedef struct lab__unordered_map_iter_st UnorderedMapIterator;

struct lab__unordered_map_api_st{
    UnorderedMapDescriptor (*constructor)(Hasher hashfunc);
    int (*size)(UnorderedMapDescriptor* desc);
    void (*insert)(UnorderedMapDescriptor* desc,Pair kvpair);
    void (*erase)(UnorderedMapDescriptor* desc,UnorderedMapIterator iter);
    void (*clear)(UnorderedMapDescriptor* desc);
    UnorderedMapIterator (*begin)(UnorderedMapDescriptor* desc);
    UnorderedMapIterator (*end)(UnorderedMapDescriptor* desc);
    UnorderedMapIterator (*iter_next)(UnorderedMapIterator it);
    UnorderedMapIterator (*iter_prev)(UnorderedMapIterator it);
    Pair (*iter_dereference)(UnorderedMapIterator it);
    UnorderedMapIterator (*find)(UnorderedMapDescriptor* desc,void* key,int keysize);
    void (*destructor)(UnorderedMapDescriptor *desc);
};

typedef struct lab__unordered_map_api_st UnorderedMapAPI;
extern UnorderedMapAPI um;

#endif