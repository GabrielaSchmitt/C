#include <stdio.h>
#include <stdlib.h>
#include "Functions.c"

int main(void){
    setbuf(stdout, NULL);
    int option = Menu(); 
    HEAP* first_node = create_HEAP(); 

    while(option != 0){
        switch (option){
            case 1:
                display_HEAP(first_node);
                break;

            case 2:
                display_execution(ptr_in_execution);
                break;

            case 3:
                // add verifications 
                // if - Caso o processo atual em execução tenha uma prioridade maior que o processo de entrada.
                // else if -Caso o processo atual em execução tenha uma prioridade igual que o processo de entrada.
                // else if - Caso o processo atual em execução tenha menos que três ciclos para ser finalizado.
                if(empty_ptr_in_execution(ptr_in_execution)){
                    
                    printf("\nEnter the name of the process: ");
                        scanf(" %c", &ptr_in_execution->name); 
                    printf("\nEnter process priority (1-5): ");
                        scanf(" %d", &ptr_in_execution->priority); 
                    while (ptr_in_execution->priority < 1 || ptr_in_execution->priority > 5){
                        printf("\nERROR - The process must be between 1 to 5: ");
                        scanf(" %d", &ptr_in_execution->priority); 
                    }
                    printf("\nEnter process execution time: ");
                        scanf(" %d", &ptr_in_execution->cycles); 

                }else{
                    push_HEAP( first_node );
                }
            break;

            case 4:
                free(first_node);
                free(ptr_in_execution); 
                break;

            case 5:
                execute_one_cycle(ptr_in_execution, first_node); 
                break;

            case 0:
                free(first_node);
                free(ptr_in_execution); 
                return EXIT_SUCCESS; 
        }
        option = Menu(); 
    }

    return EXIT_SUCCESS; 
}
