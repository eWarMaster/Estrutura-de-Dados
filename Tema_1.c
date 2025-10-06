#include <stdio.h>
#include <string.h>

/*
 * Programa: Cadastro de Territorios
 * Objetivo: Demonstrar o uso de structs para armazenar e exibir informacoes de multiplos territorios.
 * Autor: Adriano Emilio de Sousa
 */

#define TOTAL_TERRITORIOS 5  // Quantidade fixa de territorios

/*
 * Definicao da estrutura Territorio
 * Agrupa informacoes relacionadas a um territorio: nome, cor do exercito e numero de tropas.
 */
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    struct Territorio territorios[TOTAL_TERRITORIOS];  // Vetor de structs para armazenar 5 territorios
    int i;

    printf("=== SISTEMA DE CADASTRO DE TERRITORIOS ===\n\n");

    // Entrada de dados dos territorios
    for (i = 0; i < TOTAL_TERRITORIOS; i++) {
        printf("Cadastro do Territorio %d\n", i + 1);

        // Le o nome do territorio
        printf("Digite o nome do territorio: ");
        scanf(" %[^\n]", territorios[i].nome);  // le ate o Enter (permite nomes com espacos)

        // Le a cor do exercito
        printf("Digite a cor do exercito: ");
        scanf(" %s", territorios[i].cor);

        // Le a quantidade de tropas
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("----------------------------------------\n");
    }

    // Exibicao dos dados cadastrados
    printf("\n=== LISTA DE TERRITORIOS CADASTRADOS ===\n\n");

    for (i = 0; i < TOTAL_TERRITORIOS; i++) {
        printf("Territorio %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exercito: %s\n", territorios[i].cor);
        printf("Quantidade de tropas: %d\n", territorios[i].tropas);
        printf("----------------------------------------\n");
    }

    printf("Cadastro concluido com sucesso!\n");

    return 0;
}
