#include "biblioteca.h"
#include "biblioteca_aux.h"
#include <stdio.h>
#include <string.h>

void limpa(){ // Função para limpar o buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} //
}

void escreve(int tam,  lista *tarefas) {

    FILE *arquivo= fopen("lista_de_tarefas", "wb");;

    if (arquivo) {
        // Escreve as tarefas no arquivo
        fwrite(tarefas, sizeof( lista), tam, arquivo);
    }
    fclose(arquivo);
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

void ordena(int tam,  lista *tarefas){
    lista temporario[1];

    for(int j = 0; j < tam; j++){
        for(int i = 0; i < tam; i++){
            if(tarefas[j].prioridade > tarefas[i].prioridade){
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

void filtros(int op, int tam, lista *tarefas){

    if(op == 1) {
        int escolha, op1, op2;

        printf("Gostaria de estabelecer um intervalo de prioridade? (1 - sim/ 0 - nao)\n");
        scanf("%d", &escolha);
        limpa();
        if (escolha == 1) {
            printf("Insira o inicio do intervalo de prioridade: ");
            scanf("%d", &op1);
            limpa();
            printf("Insira o fim do intervalo de prioridade: ");
            scanf("%d", &op2);
            limpa();
            for (int i = 0; i < tam; i++) {
                if(tarefas[i].prioridade >= op1 && op2 >= tarefas[i].prioridade){
                    printa(i, tarefas);
                }
            }
        }
        else
        {
            printf("Insira a prioridade: ");
            scanf("%d", &op1);
            limpa();
            for (int i = 0; i < tam; i++) {
                if(tarefas[i].prioridade == op1){
                    printa(i, tarefas);
                }
            }
        }
    }
    else if(op == 2){
        char cat[20];
        printf("Insira a categoria que gostaria de filtrar: ");
        scanf("%s", cat);
        limpa();

        for (int i = 0; i < tam; i++) {
            if(strncmp(cat, tarefas[i].categoria, 21) == 0){
                printa(i, tarefas);
            }
        }
    }
    else if(op ==3){
        int op1;

        printf("Insira o estado de tarefas que deseja acessar: (1 - Nao Iniciado / 2 - Em andamento / 3 - Completo\n");
        scanf("%d", &op1);
        limpa();
        for (int i = 0; i < tam; i++) {
            if(tarefas[i].estado == op1){
                printa(i, tarefas);
            }
        }
    } else{
        int op1;
        char cat[20];

        printf("Insira a prioridade: ");
        scanf("%d", &op1);
        limpa();
        printf("Insira a categoria: ");
        scanf("%s", cat);
        limpa();
        for (int i = 0; i < tam; i++) {
            if(tarefas[i].prioridade == op1 && strncmp(cat, tarefas[i].categoria, 21) == 0){
                printa(i, tarefas);
            }
        }
    }
}



void printa(int ind, lista *tarefas){

    FILE *arquivo = fopen("lista.txt", "a"); // Abre o arquivo para escrita

    fprintf(arquivo, "-------------------------\n"); // Imprime uma linha divisória no arquivo

    fprintf(arquivo, "Tarefa %d:\n", ind + 1); // Imprime o número da transação no arquivo

    fprintf(arquivo, "Prioridade: %d\n", tarefas[ind].prioridade); // Imprime a descrição da transação no arquivo
    fprintf(arquivo, "Categoria: %s\n", tarefas[ind].categoria);
    fprintf(arquivo, "Descricao: %s\n", tarefas[ind].descricao);

    fprintf(arquivo, "Estado: ");
    switch (tarefas[ind].estado) {
        case 1:
            fprintf(arquivo,"Nao Iniciado");
            break;
        case 2:
            fprintf(arquivo, "Em Andamento");
            break;
        default:
            fprintf(arquivo,"Completa");
            break;
    }
    fprintf(arquivo, "\n\n<--------------------->\n");
    fclose(arquivo);

    printf("Informações inseridas no txt");
}