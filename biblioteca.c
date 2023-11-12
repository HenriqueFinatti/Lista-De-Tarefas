#include "biblioteca.h"
#include <stdio.h>
#include <string.h>


void limpa(){ // Função para limpar o buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {} //
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
                    printa(i, tarefas, tarefas[i].estado);
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
                    printa(i, tarefas, tarefas[i].estado);
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
                printa(i, tarefas, tarefas[i].estado);
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
                printa(i, tarefas, tarefas[i].estado);
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
                printa(i, tarefas, tarefas[i].estado);
            }
        }
    }
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
            printa(i, tarefas, tarefas[i].estado);
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


