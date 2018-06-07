#include <stdlib.h>
#include <stdio.h>
#ifndef List_h
#define List_h

void * ListCreate();
int    ListDelete(void * list);
char   ListIsEmpty(const void * list);
void * ListHead(const void * list);
void * ListTail(const void * list);
void * ListCurrent(const void * list);
void * ListNext(const void * list);
void * ListPrev(const void * list);
void * ListAppend(const void * list, void * data);
void * ListConcat(const void * list1, const void * list2);
void   ListIter(const void * list, void (*iter)(void * data));
char   ListExists(const void * list, char (*compare)(void * data));
void * ListFind(const void * list, void (*find)(void * data));
#endif