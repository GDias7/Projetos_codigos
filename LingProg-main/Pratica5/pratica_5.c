/*

* Program: [pratica5.c]

* Author: [Gabriel Dias Barros]

* Date: [03/04/2024]

* License: [GNU General Public License]

*/

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó na árvore binária
typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} tNode;

// Função para criar um novo nó
tNode *create_node(int key) {
    tNode *new_node = (tNode *) malloc(sizeof(tNode));
    if (new_node == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para novo nó.\n");
        exit(EXIT_FAILURE);
    }
    new_node->key = key;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// Função para inserir um nó na árvore
tNode *insert_node(tNode *root, int key) {
    if (root == NULL) {
        return create_node(key);
    }
    if (key < root->key) {
        root->left = insert_node(root->left, key);
    } else if (key > root->key) {
        root->right = insert_node(root->right, key);
    }
    return root;
}

// Função para encontrar o nó de valor mínimo em uma subárvore"
tNode *min_value_node(tNode *node) {
    tNode *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Função para remover um nó da BST (Binary Search Tree)
tNode *remove_node(tNode *root, int key) {
    if (root == NULL) {
        fprintf(stderr, "Erro: A chave não está presente na árvore.\n");
        return root;
    }

    if (key < root->key) {
        root->left = remove_node(root->left, key);
    } else if (key > root->key) {
        root->right = remove_node(root->right, key);
    } else {
        if (root->left == NULL) {
            tNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            tNode *temp = root->left;
            free(root);
            return temp;
        }

        tNode *temp = min_value_node(root->right);
        root->key = temp->key;
        root->right = remove_node(root->right, temp->key);
    }

    return root;
}

// Função para deletar a BST e liberar a memória.
void delete_tree(tNode *root) {
    if (root != NULL) {
        delete_tree(root->left);
        delete_tree(root->right);
        free(root);
    }
}

// Função para buscar um elemento na árvore
tNode *search_node(tNode *root, int k) {
    if (root == NULL || root->key == k) {
        return root;
    }
    if (k < root->key) {
        return search_node(root->left, k);
    } else {
        return search_node(root->right, k);
    }
}

// Função para imprimir a árvore em ordem (inorder traversal)
void inorder_traversal(tNode *root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->key);
        inorder_traversal(root->right);
    }
}

int main() {
    tNode *root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);

    printf("BST in inorder traversal: ");
    inorder_traversal(root);
    printf("\n");
    
    int element_to_search;
    
    printf("Digite o elemento a ser encontrado:\n");
    scanf("%d",&element_to_search);
    
    tNode *result = search_node(root, element_to_search);
    if (result != NULL) {
        printf("Elemento %d encontrado na árvore.\n", element_to_search);
    } else {
        printf("Elemento %d não encontrado na árvore.\n", element_to_search);
    }
    
    root = remove_node(root, 20);
    printf("BST after removing 20: ");
    inorder_traversal(root);
    printf("\n");

    delete_tree(root); // Liberando memória da árvore
    
    return 0;
}


