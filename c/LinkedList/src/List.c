#include "List.h"
//List guid 4585bab1_e7624fb2_91d95801_7f832842
#define LIST_GUID1 0x4585bab1
#define LIST_GUID2 0xe7624fb2
#define LIST_GUID3 0x91d95801
#define LIST_GUID4 0x7f832842

typedef struct {
    void * prev;
    void * next;
    void * entry;
}ListEntry;

typedef struct {
    unsigned long guid1;
    unsigned long guid2;
    unsigned long guid3;
    unsigned long guid4;
    ListEntry * head;
    ListEntry * tail;
    ListEntry * current;
    int count;
} List;

void * ListCreate(){
    #ifdef DEBUG
    printf("Creating new list\n");
    #endif
    List * l = malloc(sizeof(List));
    l->guid1 = LIST_GUID1;
    l->guid2 = LIST_GUID2;
    l->guid3 = LIST_GUID3;
    l->guid4 = LIST_GUID4;
    return (void *)l;
}

char ListCmpGuid(const void * list){
    List * l = (List *)list;
    if (l->guid1 == LIST_GUID1 && l->guid2 == LIST_GUID2 && l->guid3 == LIST_GUID3 && l->guid4 == LIST_GUID4) {
        return 1;
    } else {
        return 0;
    }
}

char ListIsEmpty(const void * list){
    if (ListCmpGuid(list) == 0) {
        return 1;
    }
    List * l = (List *) list;
    if (l->head == 0){
        return 1;
    } else {
        return 0;
    }
}

int ListDelete(void * list){
    if (ListCmpGuid(list) == 0) {
        return -1;
    }
    #ifdef DEBUG
    printf("Deleting list: %p with entry count: %i\n", list, l->count);
    #endif

    List * l = (List*)list;
    l->current = l->head;
    while(l->current != 0){
        List * next = (List*)l->current;
        #ifdef DEBUG
        printf("Deleting entry: %p\n", next);
        #endif
        l->current = l->current->next;
        free(next);
    }
    #ifdef DEBUG
    printf("Finished entries and deleting list: %p\n", list);
    #endif
    free(list);
    return 0;
}

void * ListHead(const void * list){
    if (ListCmpGuid(list) == 0) {
        return NULL;
    }
    List * l = (List*)list;
    l->current = l->head;
    return (void *)l->current;
}
void * ListTail(const void * list){
    if (ListCmpGuid(list) == 0) {
        return NULL;
    }
    List * l = (List*)list;
    l->current = l->head;
    return (void *)l->current;
}

void * ListCurrent(const void * list){
    if (ListCmpGuid(list) == 0) {
        return NULL;
    }
    List * l = (List*)list;
    return (void *)l->current;
}
void * ListNext(const void * list){
    if (ListCmpGuid(list) == 0) {
        return NULL;
    }
    List * l = (List*)list;
    l->current = l->current->next;
    return (void *)l->current;
}

void * ListPrev(const void * list){
    if (ListCmpGuid(list) == 0) {
        return NULL;
    }
    List * l = (List*)list;
    l->current = l->current->prev;
    return (void *)l->current;
}

void * ListAppend(const void * list, void * data){
    if (ListCmpGuid(list) == 0) {
        return NULL;
    }
    List * l = (List*)list;
    ListEntry * e = (ListEntry *) malloc(sizeof(ListEntry));
    e->entry = data;
    
    #ifdef DEBUG
    printf("Appendnig to list: %p, data: %p\n", list, data);
    printf("Before append Head: %p, Tail: %p, current: %p, count: %i\n", l->head, l->tail, l->current, l->count);
    #endif
    
    if(l->head == 0){
        e->prev = 0;
        e->next = 0;
        l->head = e;
    } else {
        l->tail->next = e;
        e->prev = l->tail;
        e->next = 0;
    }
    l->tail = e;
    l->current = e;
    l->count++;
    
    #ifdef DEBUG
    printf("After append Head: %p, Tail: %p, current: %p, count: %i\n", l->head, l->tail, l->current, l->count);
    #endif

    return e;
}

void * ListConcat(const void * list1, const void * list2) {
    if (ListCmpGuid(list1) == 0 || ListCmpGuid(list2) == 0 ||
        list1 == list2) {
        return NULL;
    }
    List * l1 = (List*)list1;
    List * l2 = (List*)list2;
    return list1;
}

void ListIter(const void * list, void (*iter)(void * data)) {
    if (ListCmpGuid(list) == 0) {
        return;
    }
    ListEntry * e =  ListHead(list);
    while (e != 0) {
        iter(e->entry);
        e = ListNext(list);
    }
}

char ListExists(const void * list, char (*compare)(void * data)){
    if (ListCmpGuid(list) == 0) {
        return 0;
    }
    ListEntry * e =  ListHead(list);
    while (e != 0) {
        if (compare(e->entry) == 1)
        {
            return 1;
        }
        e = ListNext(list);
    }
    return 0;
}