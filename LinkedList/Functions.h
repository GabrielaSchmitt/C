#include <stdlib.h>
#include <stdio.h>

typedef struct node_int {
    int info;
    struct node_int * ptr_next;
} LIST_INT;

LIST_INT * lst_create(void);
void lst_printList(LIST_INT * list) ;
LIST_INT * lst_insertNode(LIST_INT * list, int info); 
LIST_INT * lst_insertNodeEnd(LIST_INT * list, int info);
LIST_INT * lst_removeNode(LIST_INT * list, int info);
int lst_count(LIST_INT * list); 
LIST_INT * lst_copyList(LIST_INT * list);
LIST_INT * lst_concatenateList(LIST_INT * L1, LIST_INT * L2); 
LIST_INT * lst_arrayToList(int v[], int n);
LIST_INT * lst_ascendingList(LIST_INT * L); 
LIST_INT * lst_reverseList(LIST_INT * L); 
