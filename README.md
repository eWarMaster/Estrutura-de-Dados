# Projetos de Estruturas de Dados em C

Este repositório contém quatro exercícios práticos em C, desenvolvidos para explorar conceitos fundamentais de estruturas de dados e programação estruturada. Cada exercício simula cenários de jogos ou sistemas interativos, permitindo aplicar conceitos como structs, vetores, filas e árvores binárias.

## 1. Cadastro de Territórios

### Objetivo
Criar um sistema simples para armazenar informações sobre territórios, simulando um cenário estratégico de jogo.

### Características
- Uso de struct para agrupar dados (nome, cor do exército, quantidade de tropas)
- Cadastro de 5 territórios via entrada do usuário
- Exibição das informações cadastradas
- Aplicação de boas práticas como mensagens claras, nomes de variáveis intuitivos e comentários explicativos

## 2. Sistema de Inventário (Mochila de Loot)

### Objetivo
Simular uma mochila de jogador em um jogo de sobrevivência, utilizando structs e listas sequenciais.

### Características
- Estrutura Item contendo nome, tipo e quantidade
- **Funcionalidades:**
  - Inserir itens (até 10)
  - Remover itens pelo nome
  - Listar todos os itens
  - Buscar itens pelo nome (busca sequencial)
- Interface clara para entrada de dados e respostas rápidas
- Uso de funções para modularizar o código e facilitar manutenção

## 3. Fila de Peças Futuras (Tetris Stack)

### Objetivo
Implementar a fila de peças de um jogo estilo Tetris, simulando a mecânica de "próximas peças".

### Características
- Estrutura Peca com tipo e id único
- Fila circular de tamanho fixo (MAX_FILA = 5)
- **Funcionalidades:**
  - Jogar peça (dequeue)
  - Inserir nova peça (enqueue)
  - Exibir estado atual da fila
- Peças geradas automaticamente com função gerarPeca()
- Aplicação prática de conceitos de fila circular, arrays e modularização

## 4. Mapa da Mansão (Detective Quest)

### Objetivo
Representar um mapa de jogo como árvore binária, permitindo exploração interativa pelo jogador.

### Características
- Estrutura Sala com nome e ponteiros para esquerda e direita
- Montagem manual do mapa da mansão
- **Exploração interativa:**
  - Escolha entre esquerda (e), direita (d) ou sair (s)
  - Navegação até salas folha (sem caminhos)
- Aplicação de conceitos de árvores binárias, alocação dinâmica, condicionais e modularização

## Tecnologias

- **Linguagem:** C
- **Compilador:** GCC (Windows, Linux, macOS)
- **Estruturas de dados:** Structs, Vetores, Fila Circular, Árvore Binária
- **Conceitos explorados:** Modularização, entrada/saída de dados, controle de fluxo, alocação dinâmica