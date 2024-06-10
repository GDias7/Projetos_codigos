#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} tNode;

typedef struct {
    tNode* topo;
} tPilha;

typedef struct {
    tNode* first_elem;
} tList;

typedef struct {
    tNode* inicio; // Ponteiro para o início da fila
    tNode* fim;    // Ponteiro para o fim da fila
} tFila;

// Inicializa uma fila vazia
void inicializarFila(tFila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

// Insere um elemento no final da fila
void insert_rear(tFila* fila, int novo_dado) {
    tNode* novo_no = (tNode*)malloc(sizeof(tNode));
    if (novo_no == NULL) {
        printf("Erro: Não há espaço na memória.\n");
        return;
    }

    novo_no->data = novo_dado;
    novo_no->next = NULL;

    if (fila->inicio == NULL) {
        // Se a fila estiver vazia, o novo nó será tanto o início quanto o fim da fila
        fila->inicio = novo_no;
    } else {
        // Caso contrário, atualizamos o próximo do último nó para apontar para o novo nó
        fila->fim->next = novo_no;
    }

    // Atualiza o fim da fila para o novo nó
    fila->fim = novo_no;
}

// Remove um elemento do início da fila
int remove_front(tFila* fila) {
    if (fila->inicio == NULL) {
        printf("Erro: A fila está vazia.\n");
        return -1; // Valor de erro, você pode escolher um valor adequado dependendo do contexto
    }

    tNode* no_removido = fila->inicio;
    int dado_removido = no_removido->data;

    // Atualiza o início da fila para o próximo nó
    fila->inicio = fila->inicio->next;

    // Se o nó removido for o último nó da fila, atualiza o fim da fila para NULL
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    // Libera o nó removido da memória
    free(no_removido);

    return dado_removido;
}

// Inicializa uma pilha vazia
void inicializarPilha(tPilha* pilha) {
    pilha->topo = NULL;
}

// Insere um elemento no topo da pilha (push)
void push(tPilha* pilha, int novo_dado) {
    tNode* novo_no = (tNode*)malloc(sizeof(tNode));
    if (novo_no == NULL) {
        printf("Erro: Não há espaço na memória.\n");
        return;
    }

    novo_no->data = novo_dado;
    novo_no->next = pilha->topo; // O próximo do novo nó aponta para o antigo topo da pilha
    pilha->topo = novo_no; // Atualiza o topo da pilha para o novo nó
}

// Remove o elemento do topo da pilha (pop)
int pop(tPilha* pilha) {
    if (pilha->topo == NULL) {
        printf("Erro: A pilha está vazia.\n");
        return -1; // Valor de erro, você pode escolher um valor adequado dependendo do contexto
    }

    tNode* no_removido = pilha->topo;
    int dado_removido = no_removido->data;
    pilha->topo = pilha->topo->next; // Atualiza o topo da pilha para o próximo nó
    free(no_removido); // Libera o nó removido da memória
    return dado_removido;
}

// Insert element at the beggining
void insert_list(tList *list, int new_data) {
    tNode* new_node = (tNode*) malloc(sizeof(tNode));
    if (new_node == NULL) {
        printf("Error: No space left in memory.\n");
        return;
    }

    new_node->data = new_data;
    new_node->next = list->first_elem; // Set next of new node
    list->first_elem = new_node; // Update list external pointer to new node
}

// Remove an element of value del_data
void remove_list(tList *list, int del_data) {
    // Check if the list is empty
    if (list->first_elem == NULL) {
        printf("Cannot delete from an empty list.\n");
        return;
    }

    tNode* current = list->first_elem;
    tNode* prev = NULL;

    // Traverse the list to find the node to delete
    while (current != NULL && current->data != del_data) {
        prev = current;
        current = current->next;
    }

    // If the node to delete is found
    if (current != NULL) {
        // If the node to delete is the first node
        if (prev == NULL) {
            list->first_elem = current->next;  // Update list pointer to skip the first node
        } else {
            prev->next = current->next;  // Link the previous node to the next of the current node
        }
    
        free(current);  // Free memory allocated for the node
    } else {
        printf("Node with data %d not found in the list.\n", del_data);
    }
}

// Release allocated memory for the list
void free_list(tList *list) {
    tNode* current = list->first_elem;
    tNode* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);  // Free memory allocated for each node
    }

    list->first_elem = NULL;  // Set list pointer to NULL after freeing all nodes
}

// Print all elements of the list
void print_list(tList *list) {
    tNode* current = list->first_elem;

    printf("List elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// List constructor
tList create_list() {
    tList list;
    list.first_elem = NULL;  // Initialize the list with NULL pointer
    return list;
}



int main(){
    tPilha pilha;
    inicializarPilha(&pilha);
  
    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);
    push(&pilha, 40);
    push(&pilha, 50);
    
    printf("Elemento removido: %d\n", pop(&pilha));
    printf("Elemento removido: %d\n", pop(&pilha));
    printf("Elemento removido: %d\n", pop(&pilha));
    printf("Elemento removido: %d\n", pop(&pilha)); 
    printf("Elemento removido: %d\n", pop(&pilha)); 
    printf("Elemento removido: %d\n", pop(&pilha)); // Tentativa de remover de uma pilha vazia
    
    tFila fila;
    inicializarFila(&fila);

    insert_rear(&fila, 10);
    insert_rear(&fila, 20);
    insert_rear(&fila, 30);
    insert_rear(&fila, 40);
    insert_rear(&fila, 50);

    printf("Elemento removido: %d\n", remove_front(&fila));
    printf("Elemento removido: %d\n", remove_front(&fila));
    printf("Elemento removido: %d\n", remove_front(&fila));
    printf("Elemento removido: %d\n", remove_front(&fila)); 
    printf("Elemento removido: %d\n", remove_front(&fila));
    printf("Elemento removido: %d\n", remove_front(&fila)); // Tentativa de remover de uma fila vazia
    
    tList list = create_list();
  
    insert_list(&list, 10);
    insert_list(&list, 20);
    insert_list(&list, 30);
    insert_list(&list, 40);
    insert_list(&list, 50);

    print_list(&list);
    
    free_list(&list);
    
    return 0;
}
