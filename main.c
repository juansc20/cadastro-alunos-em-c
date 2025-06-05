#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 100

struct Aluno {
    char nome[100];
    float nota1;
    float nota2;
    float media;
};

void cadastrarAlunos(struct Aluno alunos[], int *quantidade) {
    printf("\nQuantos alunos deseja cadastrar? ");
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[*quantidade].nome);
        printf("Nota 1: ");
        scanf("%f", &alunos[*quantidade].nota1);
        printf("Nota 2: ");
        scanf("%f", &alunos[*quantidade].nota2);

        alunos[*quantidade].media = (alunos[*quantidade].nota1 + alunos[*quantidade].nota2) / 2.0;
        (*quantidade)++;
    }
}

void listarAlunos(struct Aluno alunos[], int quantidade) {
    printf("\n=== Lista de Alunos ===\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d. %s - Média: %.2f\n", i + 1, alunos[i].nome, alunos[i].media);
    }
}

int main() {
    struct Aluno alunos[MAX_ALUNOS];
    int quantidade = 0;
    int opcao;

    do {
        printf("\n=== Menu ===\n");
        printf("1. Cadastrar Alunos\n");
        printf("2. Listar Alunos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAlunos(alunos, &quantidade);
                break;
            case 2:
                listarAlunos(alunos, quantidade);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
