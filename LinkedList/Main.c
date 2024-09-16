#include <stdlib.h>
#include <stdio.h>
#include "Functions.h"

int main(void) {
    LIST_INT * list = lst_create();
    for (int i = 1; i <= 8; i++) {
        list = lst_insertNode(list, i);
    }
    printf("\n First List: \n"); 
    lst_printList(list);

    int count = lst_count(list); 
    printf("Number of nodes/cells in the List: %d", count);

    LIST_INT * list2 = lst_copyList(list); 
    printf("\n Copy of First List : \n"); 
    lst_printList(list2);

    LIST_INT * listFinal = lst_concatenateList(list, list2); 
    printf("\n Final List: \n"); 
    lst_printList(listFinal);

    int n = 6;
    int V[6] = {4, 1, 5, 9, 13, 26};
    LIST_INT * listArray = lst_arrayToList(V, n); 
    printf("\n Array List: \n"); 
    lst_printList(listArray);

    LIST_INT * ascendingList = lst_ascendingList(listArray);
    printf("\n Ascending List: \n"); 
    lst_printList(ascendingList);

    LIST_INT * reverseList = lst_create();
    for (int i = 1; i <= 8; i++) {
        list = lst_insertNode(list, i);
    } 
    reverseList = lst_reverseList(reverseList);
    printf("\n Reverse List: \n"); 
    lst_printList(reverseList);

    return EXIT_SUCCESS;
}
