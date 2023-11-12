#include "biblioteca.h"
#include <stdio.h>
#include <string.h>
void limpa(){ // Função para limpar o buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} //
}

void printaEstado(int estado){

    printf("Estado: ");
    switch (estado) {
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
    printf("\n\n<--------------------->\n");
}
void ordena(int tam,  lista *tarefas){
    lista temporario[1];

    for(int j = 0; j < tam; j++){
        for(int i = 0; i < tam; i++){
            if(tarefas[j].prioridade < tarefas[i].prioridade){
                temporario[0].prioridade = tarefas[j].prioridade;
                strcpy(temporario[0].descricao, tarefas[j].descricao);
                strcpy(temporario[0].descricao, tarefas[j].descricao);
                temporario[0].estado = tarefas[j].estado;

                tarefas[j].prioridade = tarefas[i].prioridade;
                strcpy(tarefas[j].descricao, tarefas[i].descricao);
                strcpy(tarefas[j].descricao, tarefas[i].descricao);
                tarefas[j].estado = tarefas[i].estado;

                tarefas[i].prioridade = temporario[0].prioridade;
                strcpy(tarefas[j].descricao, temporario[0].descricao);
                strcpy(tarefas[j].descricao, temporario[0].descricao);
                tarefas[j].estado = temporario[0].estado;
            }
        }
    }
}

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

    int op1 = 0, op2;
    printf("Deseja adicionar um filtro ? (1 - sim / 0 - nao)");
    scanf("%d", &op1);
    if(op1){
        printf("Deseja filtar por:\n");
        printf("1. Prioridade\n");
        printf("2. Categoria");
        printf("3. Estado");
        printf("4. Prioridade e Categoria");
        scanf("%d", &op2);
    } else {

        for (int i = 0; i < tam; i++) {
            printf("<--------------------->\n");
            printf("Tarefa %d\n\n", i + 1);
            printf("Prioridade: %d\n", tarefas[i].prioridade);
            printf("Categoria: %s\n", tarefas[i].categoria);
            printf("Descricao: %s\n", tarefas[i].descricao);
            printaEstado(tarefas[i].estado);
        }
    }
}


int tamanho( lista *tarefas) {
    FILE *arquivo = fopen("lista_de_tarefas", "rb");
    int cont = 0;
    if (arquivo) {

        while (fread(&tarefas[cont], sizeof( lista), 1, arquivo) == 1) {
            cont++;
        }
        fclose(arquivo);
    }
    return cont;
}


void escreve(int tam,  lista *tarefas) {

    FILE *arquivo= fopen("lista_de_tarefas", "wb");;

    if (arquivo) {
        // Escreve as tarefas no arquivo
        fwrite(tarefas, sizeof( lista), tam, arquivo);
    }
    fclose(arquivo);
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


