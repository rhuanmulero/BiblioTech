#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LIVROS 100


typedef struct {
    char titulo[100];
    char autor[100];
    int disponivel;
} Livro;

Livro biblioteca[MAX_LIVROS];




int numLivros = 0;

void adicionarLivro();
void consultarLivro();
void realizarEmprestimo();
void realizarDevolucao();

int main() {

    setlocale(LC_ALL, "Portuguese");
    char nome[50];
    int opcao;

    printf("Como você gostaria de ser chamado?\nDigite: ");
    scanf("%s", &nome);
    do {

        printf("\nBiblioteca - %s\n", nome);
        printf("1. Adicionar Livro\n");
        printf("2. Consultar Livro\n");
        printf("3. Realizar Empréstimo\n");
        printf("4. Realizar Devolução\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adicionarLivro();
                break;
            case 2:
                consultarLivro();
                break;
            case 3:
                realizarEmprestimo();
                break;
            case 4:
                realizarDevolucao();
                break;
            case 5:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

void adicionarLivro() {
    if (numLivros < MAX_LIVROS) {
        printf("Digite o título do livro: ");
        getchar();
        fgets(biblioteca[numLivros].titulo, 100, stdin);
        printf("Digite o autor do livro: ");
        fgets(biblioteca[numLivros].autor, 100, stdin);
        biblioteca[numLivros].disponivel = 1;
        numLivros++;
        printf("Livro adicionado com sucesso!\n");
    } else {
        printf("Não é possível adicionar mais livros. Limite atingido.\n");
    }
}

void consultarLivro() {
    if (numLivros > 0) {
        printf("Digite o título do livro a ser consultado: ");
        getchar();
        char tituloConsulta[100];
        fgets(tituloConsulta, 100, stdin);
        int encontrado = 0;

        for (int i = 0; i < numLivros; i++) {
            if (strcmp(biblioteca[i].titulo, tituloConsulta) == 0) {
                printf("Livro encontrado!\nTítulo: %sAutor: %sDisponível: %s\n", biblioteca[i].titulo, biblioteca[i].autor, (biblioteca[i].disponivel == 1) ? "Sim" : "Não");
                encontrado = 1;
                break;
            } else {
            printf("Livro não encontrado na biblioteca.\n");
        }
        }


    } else {
        printf("A biblioteca está vazia. Não há livros para consultar.\n");
    }
}

void realizarEmprestimo() {
    if (numLivros > 0) {
        printf("Digite o título do livro a ser emprestado: ");
        getchar();
        char tituloEmprestimo[100];
        fgets(tituloEmprestimo, 100, stdin);
        int encontrado = 0;

        for (int i = 0; i < numLivros; i++) {
            if (strcmp(biblioteca[i].titulo, tituloEmprestimo) == 0 && biblioteca[i].disponivel == 1) {
                biblioteca[i].disponivel = 0;
                printf("Livro emprestado com sucesso!\n");
                encontrado = 1;
                break;
            } else {
            printf("Livro não disponível para empréstimo ou não encontrado na biblioteca.\n");
        }
        }
    } else {
        printf("A biblioteca está vazia. Não há livros para emprestar.\n");
    }
}

void realizarDevolucao() {
    if (numLivros > 0) {
        printf("Digite o título do livro a ser devolvido: ");
        getchar();
        char tituloDevolucao[100];
        fgets(tituloDevolucao, 100, stdin);
        int encontrado = 0;

        for (int i = 0; i < numLivros; i++) {
            if (strcmp(biblioteca[i].titulo, tituloDevolucao) == 0 && biblioteca[i].disponivel == 0) {
                biblioteca[i].disponivel = 1;
                printf("Livro devolvido com sucesso!\n");
                encontrado = 1;
                break;
            } else {
            printf("Livro não encontrado na biblioteca ou não foi devolvido ainda.\n");
        }
        }
    } else {
        printf("A biblioteca está completa. Não há livros para devolver.\n");
    }
}

