#ifndef LAB_PRIORITY_QUEUE
#define LAB_PRIORITY_QUEUE

#include "labafx.h"

struct lab__priority_queue_st{

};


// DO NOT MODIFY BELOW

typedef struct lab__priority_queue_st PriorityQueueDescriptor;
// typedef struct lab__priority_queue_iter_st PriorityQueueIterator;

struct lab__priority_queue_api_st{
    PriorityQueueDescriptor (*constructor)(Comparator compfunc);
    int (*size)(PriorityQueueDescriptor* desc);
    void (*push)(PriorityQueueDescriptor* desc,void* key,int size);
    void* (*top)(PriorityQueueDescriptor* desc);
    void (*pop)(PriorityQueueDescriptor* desc);
    void (*clear)(PriorityQueueDescriptor* desc);
    void (*destructor)(PriorityQueueDescriptor* desc);
};

typedef struct lab__priority_queue_api_st PriorityQueueAPI;
extern PriorityQueueAPI prq;

#endif