#ifndef LAB_VECTOR_H
#define LAB_VECTOR_H

struct lab__vector_st{

};

struct lab__vector_iter_st{

};

// NOT MODIFY BELOW
typedef struct lab__vector_st VectorDescriptor;
typedef struct lab__vector_iter_st VectorIterator;

struct lab__vector_api_st{
    VectorDescriptor (*constructor)();
    void (*push_back)(VectorDescriptor* desc,void* elem,int size);
    VectorIterator (*begin)(VectorDescriptor* desc);
    VectorIterator (*end)(VectorDescriptor* desc);
    void* (*iter_dereference)(VectorIterator iter);
    VectorIterator (*iter_move)(VectorIterator iter,int delta); // simulates: iter+8;
    int (*size)(VectorDescriptor* desc);
    void (*pop_back)(VectorDescriptor* desc);
    void (*erase)(VectorDescriptor* desc,VectorIterator iter);
    void (*clear)(VectorDescriptor* desc);
    void (*destructor)(VectorDescriptor* desc);
    int (*capacity)(VectorDescriptor* desc);
    void (*shrink_to_fit)(VectorDescriptor* desc);
    void (*reserve)(VectorDescriptor* desc,int resv_size);
};

typedef struct lab__vector_api_st VectorAPI;

extern VectorAPI vector;

#endif