typedef struct element{
    char name;
    int priority;       // range 1 - 5
    int cycles; 
    struct element* ptr_next;
} LIST_INT;

typedef struct HEAP{
    LIST_INT* top;
} HEAP;

LIST_INT* ptr_in_execution; 

int Menu();
int empty_ptr_in_execution(LIST_INT* ptr_in_execution);
int empty_HEAP(HEAP* node); 
HEAP* create_HEAP(void);
void   display_execution(LIST_INT* ptr_in_execution);
void   display_HEAP(HEAP* node);
void   push_HEAP( HEAP* node);
void   order_HEAP_by_priority(HEAP* node); 
void   execute_one_cycle(LIST_INT* ptr_in_execution, HEAP* node);

// ok - Visualizar pilha de processamento.
// ok - Visualizar processo atual em execução.
// Adicionar novo processo.
// ok - Resetar a pilha de processos.
// ok - Passar ciclo.
