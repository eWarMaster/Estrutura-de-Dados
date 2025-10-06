#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Programa: Detective Quest - Mapa da Mansao (Arvore Binaria)
 * Objetivo: Representar o mapa da mansao usando uma arvore binaria e permitir exploracao interativa.
 * Autor: Adriano Emilio de Sousa
 */

// Estrutura que representa uma sala da mansao
typedef struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

// Funcao que cria dinamicamente uma sala com nome
Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*)malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memoria para a sala.\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// Funcao que permite o jogador explorar a mansao
void explorarSalas(Sala* salaAtual) {
    char opcao;

    while (salaAtual != NULL) {
        printf("\nVoce esta em: %s\n", salaAtual->nome);

        // Caso seja uma sala folha (sem caminhos)
        if (salaAtual->esquerda == NULL && salaAtual->direita == NULL) {
            printf("Nao ha mais caminhos a seguir. Fim da exploracao!\n");
            break;
        }

        printf("Escolha seu caminho:\n");
        if (salaAtual->esquerda != NULL)
            printf(" (e) Ir para a esquerda (%s)\n", salaAtual->esquerda->nome);
        if (salaAtual->direita != NULL)
            printf(" (d) Ir para a direita (%s)\n", salaAtual->direita->nome);
        printf(" (s) Sair do jogo\n");

        printf("Opcao: ");
        scanf(" %c", &opcao);

        if (opcao == 'e' && salaAtual->esquerda != NULL) {
            salaAtual = salaAtual->esquerda;
        } else if (opcao == 'd' && salaAtual->direita != NULL) {
            salaAtual = salaAtual->direita;
        } else if (opcao == 's') {
            printf("Exploracao encerrada. Ate a proxima!\n");
            break;
        } else {
            printf("Caminho invalido! Tente novamente.\n");
        }
    }
}

// Funcao principal: monta o mapa e inicia a exploracao
int main() {
    // Criando as salas da mansao
    Sala* hall = criarSala("Hall de entrada");
    Sala* salaEstar = criarSala("Sala de estar");
    Sala* cozinha = criarSala("Cozinha");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* jardim = criarSala("Jardim");
    Sala* porao = criarSala("Porao misterioso");

    // Montando o mapa da mansao
    hall->esquerda = salaEstar;
    hall->direita = cozinha;
    salaEstar->esquerda = biblioteca;
    salaEstar->direita = jardim;
    cozinha->direita = porao;

    // Iniciando a exploracao a partir do hall
    printf("=== Detective Quest ===\n");
    printf("Voce esta prestes a explorar a mansao!\n");
    explorarSalas(hall);

    // Liberando memoria antes de sair
    free(biblioteca);
    free(jardim);
    free(porao);
    free(salaEstar);
    free(cozinha);
    free(hall);

    return 0;
}
