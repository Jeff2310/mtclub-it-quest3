#ifndef LAB_AFX_H
#define LAB_AFX_H

// look reference document for comparator behavior.
typedef int (*Comparator)(void* a,int asize,void* b,int bsize);

// this is a naive hash function abstraction but it should work well with small cases.
typedef unsigned int (*Hasher)(void* a,int size);

struct lab__pair_st{
    void* key;
    int keysize;
    void* value;
    int valuesize;
};

typedef struct lab__pair_st Pair;

#endif