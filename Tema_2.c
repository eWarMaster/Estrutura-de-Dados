#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Programa: Sistema de Inventario do Jogador
 * Objetivo: Simular a mochila de loot inicial do jogador usando structs e listas sequenciais.
 * Autor: Adriano Emilio de Sousa
 */

#define MAX_ITENS 10  // Capacidade maxima da mochila

/*
 * Definicao da estrutura Item
 * Armazena informacoes basicas de cada objeto coletado.
 */
struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

/*
 * Declaracoes de funcoes
 */
void inserirItem(struct Item mochila[], int *total);
void removerItem(struct Item mochila[], int *total);
void listarItens(struct Item mochila[], int total);
void buscarItem(struct Item mochila[], int total);

/*
 * Funcao principal
 */
int main() {
    struct Item mochila[MAX_ITENS];  // Vetor que representa a mochila
    int total = 0;                   // Quantidade atual de itens
    int opcao;

    do {
        printf("\n=== SISTEMA DE INVENTARIO ===\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer de entrada

        switch (opcao) {
            case 1:
                inserirItem(mochila, &total);
                break;
            case 2:
                removerItem(mochila, &total);
                break;
            case 3:
                listarItens(mochila, total);
                break;
            case 4:
                buscarItem(mochila, total);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

/*
 * Funcao: inserirItem
 * Objetivo: Cadastrar um novo item na mochila.
 */
void inserirItem(struct Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("Mochila cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    printf("\n--- Inserir novo item ---\n");

    printf("Digite o nome do item: ");
    scanf(" %[^\n]", mochila[*total].nome);

    printf("Digite o tipo do item (ex: arma, municao, cura): ");
    scanf(" %[^\n]", mochila[*total].tipo);

    printf("Digite a quantidade: ");
    scanf("%d", &mochila[*total].quantidade);

    (*total)++;

    printf("Item adicionado com sucesso!\n");

    listarItens(mochila, *total);
}

/*
 * Funcao: removerItem
 * Objetivo: Remover um item da mochila pelo nome.
 */
void removerItem(struct Item mochila[], int *total) {
    if (*total == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item a ser removido: ");
    scanf(" %[^\n]", nomeBusca);

    int i, encontrado = -1;

    // Busca sequencial pelo item
    for (i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Item nao encontrado.\n");
        return;
    }

    // Move os itens para preencher o espaco removido
    for (i = encontrado; i < *total - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    (*total)--;

    printf("Item removido com sucesso!\n");
    listarItens(mochila, *total);
}

/*
 * Funcao: listarItens
 * Objetivo: Mostrar todos os itens da mochila.
 */
void listarItens(struct Item mochila[], int total) {
    if (total == 0) {
        printf("\nA mochila esta vazia.\n");
        return;
    }

    printf("\n--- Itens na mochila ---\n");
    for (int i = 0; i < total; i++) {
        printf("Item %d:\n", i + 1);
        printf(" Nome: %s\n", mochila[i].nome);
        printf(" Tipo: %s\n", mochila[i].tipo);
        printf(" Quantidade: %d\n", mochila[i].quantidade);
        printf("----------------------------\n");
    }
}

/*
 * Funcao: buscarItem
 * Objetivo: Procurar um item pelo nome e mostrar suas informacoes.
 */
void buscarItem(struct Item mochila[], int total) {
    if (total == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    char nomeBusca[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    scanf(" %[^\n]", nomeBusca);

    for (int i = 0; i < total; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf(" Nome: %s\n", mochila[i].nome);
            printf(" Tipo: %s\n", mochila[i].tipo);
            printf(" Quantidade: %d\n", mochila[i].quantidade);
            return;
        }
    }

    printf("Item nao encontrado.\n");
}
