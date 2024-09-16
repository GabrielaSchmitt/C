#include "Functions.h"

LIST_INT * lst_create(void) {
    return (LIST_INT *) NULL;
}

LIST_INT * lst_insertNode(LIST_INT * list, int info) {
    LIST_INT * node = (LIST_INT *) malloc(sizeof(LIST_INT));
    node->info = info;
    node->ptr_next = list;
    return node;
}

void lst_printList(LIST_INT * list) {
    LIST_INT * node = list;
    while (node != NULL) {
        printf("\n%d\n", node->info);
        node = node->ptr_next;
    }
}

LIST_INT * lst_insertNodeEnd(LIST_INT * list, int info) {
    LIST_INT * node = list;
    LIST_INT * node_new = NULL;
    if (node == NULL) {
        node = (LIST_INT *) malloc(sizeof(LIST_INT));
        node->info = info;
        node->ptr_next = NULL;
        return node;
    } else {
        while (node->ptr_next != NULL) {
            node = node->ptr_next;
        }
        node_new = (LIST_INT *) malloc(sizeof(LIST_INT));
        node_new->info = info;
        node_new->ptr_next = NULL;
        node->ptr_next = node_new;
        return list;
    }
}

LIST_INT * lst_removeNode(LIST_INT * list, int info) {
    LIST_INT * node = list;
    LIST_INT * last_node = NULL;

    while (node != NULL && node->info != info) {
        last_node = node;
        node = node->ptr_next;
    }

    if (node == NULL) return list;

    if (last_node == NULL) {
        list = node->ptr_next;
    } else {
        last_node->ptr_next = node->ptr_next;
    }

    free(node);
    return list;
}

/*1 - Write a function that takes the pointer to a list
chained and returns the number of cells (nodes) in the list. */

int lst_count(LIST_INT * list) {
    LIST_INT * node = list;
    int cells = 0;
    if (node == NULL) return cells;

    while (node != NULL) {
        cells++ ;
        node = node->ptr_next;
    }   
    return cells; 
}

/*2 - Write a function that takes a list, as a parameter,
makes a copy of the given list and returns the pointer to the new one
list. Attention, the resulting list must be the same as the original
(the nodes must be in the same order). */ 

LIST_INT * lst_copyList(LIST_INT * list) {
    LIST_INT * list2 = lst_create();
    LIST_INT * node = list; 
    while (node != NULL){
        list2 = lst_insertNodeEnd(list2, node->info);
        node = node->ptr_next;   
    }
	return list2; 
}

/* 3 - Write a function that takes, as parameters, two lists L1 and L2 and concatenates
L1 at the end of L2. Use the prototype: list *concatenate(LIST_INT *L1, LIST_INT *L2).*/

LIST_INT * lst_concatenateList(LIST_INT * L1, LIST_INT * L2) {
    LIST_INT * listFinal = lst_create();
    LIST_INT * node = L2; 

    while (node != NULL){
        listFinal = lst_insertNodeEnd(listFinal, node->info);
        node = node->ptr_next;   
    }

    node = L1; 

    while (node != NULL){
        listFinal = lst_insertNodeEnd(listFinal, node->info);
        node = node->ptr_next;   
    }

	return listFinal; 
}

/* 4 - Write a function that takes, as parameters, a vector V with n elements and
build a linked list with the n elements of the vector. If n=0 the function should return
an empty list. Example: If the given vector is V={4, 1, 5, 9, 13, 26} the function should return
a list where the first element of the list is 4, the second is 1, and the last is 26. */

LIST_INT * lst_arrayToList(int v[], int n){
    LIST_INT * listArray = lst_create();
    for (int i = 0; i < n; i++){
        listArray = lst_insertNodeEnd(listArray, v[i]);
    }
    return listArray;
}

/* 7 - Write a function that reverses the order of cells in a linked list (first becomes 
last, second becomes second to last, etc.). Do this without using auxiliary space; just 
change the pointers.*/

LIST_INT * lst_reverseList(LIST_INT * L) {
    //LIST_INT * L == 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> NULL 
    LIST_INT * node = L; //vai mudar nas iteracoes
    LIST_INT * initialFirstNode = L; // guarda a cabeça original == 8
    LIST_INT * predecessorNode;  // guarda o penultimo node conforme iteracoes
    LIST_INT * newfirstNode; // guarda a nova cabeca da lista reversa == 1
    int temp = 1; //usada para na primeira iteração guardar a nova cabeça 
    
    //while para inicializar predecessorNode
    LIST_INT * node1 = L;
    while( node1->ptr_next != NULL ){ //varre a lista 
        predecessorNode = node1; // inicializa o penultimo 
        //predecessorNode->info = node1->info; // inicializa o penultimo 
        node1 = node1->ptr_next;       // proximo node
    } 
 
    while( predecessorNode->info != initialFirstNode->info ){ // se penultimo for coincidente com inicial
        node = initialFirstNode; 
        while( node->ptr_next != NULL ){ //varre a lista 
            predecessorNode = node;      // guarda penultimo
            node = node->ptr_next;       // guarda ultimo 
        }
        
    if(temp == 1){                   // se for a primeira iteracao guarda as informações da nova cabeca 
            newfirstNode = node;         
            newfirstNode->ptr_next = predecessorNode; 
    }
    temp++;                           // nao sera mais a primeira iteracao
    
    node->ptr_next = predecessorNode; // ultimo node aponta para penultimo, ou seja,inverte o sentido do ponteiro
    predecessorNode->ptr_next = NULL; // penultimo aponta para null (se não nosso segundo while vai para o saco kkkkk) 
    }
    
    initialFirstNode = NULL; // agora é a calda, ou seja, 8 antes era cabeça mas agora aponta para o final == null
    return L = newfirstNode; 
}

/* 8 - Write a function that, given an unordered linked list L, creates a list K
sorted, with the same nodes as in list L. The function removes elements from list L, always
from largest to smallest, and inserts them at the beginning of the K list, which in this way 
becomes a list sorted (in ascending order). Note: extra nodes must not be created, you must 
use the same nodes allocated to list L. At the end of the process, list L will be empty and 
list K will contain the nodes previously allocated to list L. */ 

LIST_INT * lst_ascendingList(LIST_INT * L) {
    LIST_INT * ascendingList = lst_create();
    LIST_INT * node = L;
    int smaller = node->info;
    int nL = lst_count(L);

    while (nL != 0) {
        while (node != NULL) {
            if (node->info < smaller) {
                smaller = node->info;
            }
            node = node->ptr_next;
        }
    
        ascendingList = lst_insertNodeEnd(ascendingList, smaller);
        L = lst_removeNode(L, smaller);
        nL = lst_count(L);
        node = L;
        if (node != NULL)
            smaller = node->info;
    }

    return ascendingList;
}
