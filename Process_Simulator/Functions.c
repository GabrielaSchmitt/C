#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

int Menu(){
    int option;
    printf("\n ------      MENU      ------ \n\n");

    printf("   [1] - Display Process HEAP \n");
    printf("   [2] - Display Process in execution \n");
    printf("   [3] - Add new Process \n");
    printf("   [4] - Reset Process HEAP \n");
    printf("   [5] - Execute a cycle \n\n");

    printf("   [0] - Exit \n");

    printf("\n ------ ENTER A OPTION ------ \n");
    scanf(" %d", &option); 
    while (option < 0 || option > 5){
        printf("\n ERROR - Enter a valid option: \n");
        scanf(" %d", &option); 
    }
    return option;     
}

int empty_ptr_in_execution(LIST_INT* ptr_in_execution){
    return ptr_in_execution == NULL; // 0 or 1
}

int empty_HEAP(HEAP* node){
    return node->top == NULL; // 0 or 1
}

HEAP* create_HEAP(void){
    HEAP* first_node = (HEAP*) malloc(sizeof(HEAP));
    first_node->top = NULL;
    return first_node;
}

void   display_execution(LIST_INT* ptr_in_execution){
    if (empty_ptr_in_execution(ptr_in_execution)){
        printf("\n ERROR - There's no process in execution.");
    }else{
        printf("Name: %c \nPriority: %d \nCycles: %d", ptr_in_execution->name, ptr_in_execution->priority, ptr_in_execution->cycles);
    }
}

void   display_HEAP(HEAP* first_node){
    if (empty_HEAP(first_node)){
        printf("\n ERROR - The HEAP is empty. ");
    }else{
        LIST_INT* node = (LIST_INT*) malloc(sizeof(LIST_INT));
        while (node != first_node->top ){
           printf("Name: %c \nPriority: %d \nCycles: %d", node->name, node->priority, node->cycles); 
           node = node->ptr_next; 
        }
    }
}

void push_HEAP( HEAP* first_node){
    LIST_INT* node = (LIST_INT*) malloc(sizeof(LIST_INT));
    node->ptr_next = first_node->top;

    printf("\nEnter the name of the process: ");
    scanf(" %c", &node->name); 

    printf("\nEnter process priority (1-5): ");
    scanf(" %d", &node->priority); 
    while (node->priority < 1 || node->priority > 5){
        printf("\nERROR - The process must be between 1 to 5: ");
        scanf(" %d", &node->priority); 
    }

    printf("\nEnter process cycles: ");
    scanf(" %d", &node->cycles);

    first_node->top = node;
    //order_HEAP_by_priority(first_node);
}

int busca_sequencial(HEAP* first_node, HEAP* node) {
    HEAP *  node_heap = first_node;

    while (node->priority != node_heap->priority ){
        first_node = first_node->ptr_next;
    }
    
    return ;
}

// void order_HEAP_by_priority(HEAP* first_node){
//     LIST_INT* node = (LIST_INT*) malloc(sizeof(LIST_INT));
//     node = first_node; 
//     while (node->ptr_next != first_node->top){
//         if (node->ptr_next->priority > node->priority){
//             //troca
//         }else {
//             node = node->ptr_next; 
//         }
        
//     }

// // why we have order it all and not just the last 2 nodes 
// // 3 - 2
// // 2 - 3
// // 2
// // 3
// // 5
// // 5

// }

void execute_one_cycle(LIST_INT* ptr_in_execution, HEAP* first_node){
    ptr_in_execution->cycles--;
    if (ptr_in_execution->cycles == 0){
            ptr_in_execution = first_node->top; 
            printf("\nThe Process cycles got to the end. Executing next Process from the HEAP: ");
            display_execution(ptr_in_execution); 
    }
}
