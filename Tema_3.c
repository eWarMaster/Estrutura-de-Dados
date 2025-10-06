#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Programa: Tetris Stack - Fila de Pecas Futuras
 * Objetivo: Simular a estrutura de fila que armazena as pecas futuras do jogo Tetris Stack.
 * Autor: Adriano Emilio de Sousa
 */

#define MAX_FILA 5  // Tamanho maximo da fila

/*
 * Estrutura que representa uma peca do Tetris
 */
struct Peca {
    char tipo;  // Tipo da peca ('I', 'O', 'T', 'L')
    int id;     // Identificador unico
};

/*
 * Estrutura da fila circular de pecas
 */
struct Fila {
    struct Peca pecas[MAX_FILA];
    int frente;  // Indice da primeira peca
    int tras;    // Indice da ultima peca
    int tamanho; // Quantidade atual de pecas
};

/*
 * Declaracao das funcoes
 */
void inicializarFila(struct Fila *fila);
int filaCheia(struct Fila *fila);
int filaVazia(struct Fila *fila);
void enfileirar(struct Fila *fila, struct Peca novaPeca);
void desenfileirar(struct Fila *fila);
void exibirFila(struct Fila *fila);
struct Peca gerarPeca();

/*
 * Funcao principal
 */
int main() {
    struct Fila fila;
    int opcao;
    int proximoId = 0; // controle para gerar IDs unicos

    srand(time(NULL)); // semente para gerar tipos aleatorios

    inicializarFila(&fila);

    // Inicializa a fila com 5 pecas
    for (int i = 0; i < MAX_FILA; i++) {
        enfileirar(&fila, gerarPeca());
        fila.pecas[fila.tras].id = proximoId++;
    }

    do {
        printf("\n=== TETRIS STACK - FILA DE PECAS FUTURAS ===\n");
        exibirFila(&fila);

        printf("\n1. Jogar peca (dequeue)\n");
        printf("2. Inserir nova peca (enqueue)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                desenfileirar(&fila);
                break;
            case 2: {
                struct Peca nova = gerarPeca();
                nova.id = proximoId++;
                enfileirar(&fila, nova);
                break;
            }
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}

/*
 * Inicializa a fila
 */
void inicializarFila(struct Fila *fila) {
    fila->frente = 0;
    fila->tras = -1;
    fila->tamanho = 0;
}

/*
 * Verifica se a fila esta cheia
 */
int filaCheia(struct Fila *fila) {
    return fila->tamanho == MAX_FILA;
}

/*
 * Verifica se a fila esta vazia
 */
int filaVazia(struct Fila *fila) {
    return fila->tamanho == 0;
}

/*
 * Insere uma nova peca no final da fila (enqueue)
 */
void enfileirar(struct Fila *fila, struct Peca novaPeca) {
    if (filaCheia(fila)) {
        printf("A fila esta cheia! Nao e possivel adicionar nova peca.\n");
        return;
    }

    fila->tras = (fila->tras + 1) % MAX_FILA;
    fila->pecas[fila->tras] = novaPeca;
    fila->tamanho++;
    printf("Nova peca [%c %d] adicionada!\n", novaPeca.tipo, novaPeca.id);
}

/*
 * Remove a peca da frente da fila (dequeue)
 */
void desenfileirar(struct Fila *fila) {
    if (filaVazia(fila)) {
        printf("A fila esta vazia! Nenhuma peca para jogar.\n");
        return;
    }

    struct Peca removida = fila->pecas[fila->frente];
    fila->frente = (fila->frente + 1) % MAX_FILA;
    fila->tamanho--;

    printf("Peca [%c %d] jogada!\n", removida.tipo, removida.id);
}

/*
 * Exibe todas as pecas atuais na fila
 */
void exibirFila(struct Fila *fila) {
    if (filaVazia(fila)) {
        printf("\nFila vazia.\n");
        return;
    }

    printf("\nFila de pecas:\n");

    int i = fila->frente;
    for (int count = 0; count < fila->tamanho; count++) {
        printf("[%c %d] ", fila->pecas[i].tipo, fila->pecas[i].id);
        i = (i + 1) % MAX_FILA;
    }

    printf("\n");
}

/*
 * Gera uma nova peca aleatoria com tipo e id
 */
struct Peca gerarPeca() {
    struct Peca nova;
    char tipos[] = {'I', 'O', 'T', 'L'};
    nova.tipo = tipos[rand() % 4];
    nova.id = 0; // o id sera definido no momento do enqueue
    return nova;
}
