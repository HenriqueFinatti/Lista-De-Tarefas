#include "biblioteca.h"
#include "biblioteca_aux.h"
#include <stdio.h>
#include <string.h>

void cria_tarefa(lista *tarefas) {
    int prioridade;
    int estado;
    do {
        limpa();
        printf("Insira a prioridade da tarefa (de 1 a 10): ");
        scanf("%d", &prioridade);

        if (prioridade < 1 || prioridade > 10) {
            printf("\nATENCAO! Prioridade invalida. Use numeros de 1 a 10.\n");
        }
    } while (prioridade < 1 || prioridade > 10);


    tarefas->prioridade = prioridade;
    printf("\nInsira a categoria da tarefa: "); scanf(" %299[^\n]", tarefas->categoria);
    limpa();

    printf("\nInsira a descricao da tarefa: ");scanf(" %99[^\n]", tarefas->descricao);

    do {
        limpa();
        printf("\nInsira o estado inicial da tarefa\n (1 - nao iniciado / 2 - em andamento): ");
        scanf("%d", &estado);

        if (estado != 2 && estado != 1) {
            printf("\nATENCAO! Estado invalida. Use 1 ou 2.\n");
        }
    } while (estado != 2 && estado != 1);
    tarefas->estado = estado;
    limpa();

}

void lista_tarefas(int tam,  lista *tarefas){

    int op1 = 0;
    printf("Deseja adicionar um filtro ? (1 - sim / 0 - nao)");
    scanf("%d", &op1);
    limpa();
    if(op1){
        int op2 = 0;
        printf("Deseja filtar por:\n");
        printf("1. Prioridade\n");
        printf("2. Categoria\n");
        printf("3. Estado\n");
        printf("4. Prioridade e Categoria\n");
        scanf("%d", &op2);
        limpa();
        filtros(op2, tam, tarefas);
    } else {
        for (int i = 0; i < tam; i++) {
            printa(i, tarefas);
        }
    }
}






void deleta_tarefa(int *tam,  lista *tarefas, int numero_tarefa) {
    if (numero_tarefa < 1 || numero_tarefa > *tam) {
        printf("Numero de tarefa invalido. Use um numero de 1 a %d.\n", *tam);
        return;
    }

    for (int i = numero_tarefa - 1; i < *tam - 1; i++) {
        tarefas[i] = tarefas[i + 1];
    }

    (*tam)--;
    printf("Tarefa numero %d foi deletada com sucesso.\n", numero_tarefa);
}

void altera_tarefa( lista *tarefas, int numero_tarefa){
    int op;

    printf("-----------------------\n");
    printf("Tarefa: %d\n", numero_tarefa);
    printf("Prioridade: %d\n", tarefas[numero_tarefa-1].prioridade);
    printf("Categoria: %s\n", tarefas[numero_tarefa-1].categoria);
    printf("Descricao: %s\n", tarefas[numero_tarefa-1].descricao);
    printf("Estado: ");
    switch (tarefas[numero_tarefa-1].estado) {
        case 1:
            printf("Nao Iniciado");
            break;
        case 2:
            printf("Em Andamento");
            break;
        default:
            printf("Completa");
            break;
    }
    printf("\n");
    printf("-----------------------\n");
    printf("Qual destes itens deseja alterar ?\n");
    printf("1. Prioridade \n2. Categoria\n3. Descricao\n4. Estado\n");
    scanf("%d", &op);
    limpa();

    int escolha;
    char temp[300];
    switch (op) {
        case 1:
            printf("Insira a nova prioridade: (numero de 1 - 10)");
            scanf("%d", &escolha);
            limpa();
            tarefas[numero_tarefa-1].prioridade = escolha;
            break;
        case 2:
            printf("Insira a nova Categoria: ");
            scanf("%s", temp);
            limpa();

            strcpy(tarefas[numero_tarefa-1].categoria, temp);
            break;

        case 3:
            printf("Insira a nova Descricao: ");
            scanf("%s", temp);
            limpa();

            strcpy(tarefas[numero_tarefa-1].descricao, temp);
            break;

        case 4:
            printf("Insira o novo estado: (1 - nao iniciado / 2 - em andamento / 3 - Completo):");
            scanf("%d", &escolha);
            limpa();

            tarefas[numero_tarefa-1].estado = escolha;
            break;

    }


}


