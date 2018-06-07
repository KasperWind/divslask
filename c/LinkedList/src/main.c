#include<stdio.h>

#include "List.h"

#define LAMBDA(c_) ({ c_ _;})

void printInt(void * data){
	printf("Printing int data %i\n", *(int*)data);
}

int main(int argc, char* argv[]) {
	void * list = ListCreate();
	
	int i[10] = {10,20,30,40,50,60,70,80,90,100};
	for (int l = 0; l < 10; l++){
		ListAppend(list, (void*)&i[l]);
	}
	
	printf("List For\n");
	ListIter(list, printInt);
	ListIter(list, LAMBDA(void _(void * v)  {
		printf("Printing int data %i\n", *(int*)v);
	}));
	int cmpi1 = 20;
	int cmpi2 = 22;
	printf("List contains %i, res: %i\n", cmpi2, ListExists(list, LAMBDA(char _(void * data) {
		if (cmpi1 == (*(int*) data)){
			return 1;
		} else {
			return 0;
		}
	})));

	ListDelete(list);
	return 0;
}