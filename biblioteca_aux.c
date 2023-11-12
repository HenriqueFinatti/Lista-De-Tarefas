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

    FILE *arquivo2 = fopen("lista.txt", "w");
    fprintf(arquivo2, "Lista de Tarefas\n");
    fclose(arquivo2);
    //Formata o txt para a apenas o menu.
}


int tamanho( lista *tarefas) {
    FILE *arquivo = fopen("lista_de_tarefas", "rb");
    int cont = 0;
    if (arquivo) {
        //Retorna o tamanho da lista total de tarefas
        while (fread(&tarefas[cont], sizeof( lista), 1, arquivo) == 1) {
            cont++;
        }
        fclose(arquivo);
    }
    return cont;
}

void ordena(int tam,  lista *tarefas){
    lista temporario[1];
    //Ordena cada item da struct em ordem crescente
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


void printa(int ind, lista *tarefas){

    FILE *arquivo = fopen("lista.txt", "a"); // Abre o arquivo para escrita

    fprintf(arquivo, "-------------------------\n"); // Imprime uma linha divisória no arquivo

    fprintf(arquivo, "Tarefa %d:\n", ind + 1); //imprime o número da tarefa

    fprintf(arquivo, "Prioridade: %d\n", tarefas[ind].prioridade); // imprime todas as informações do arquivo
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
    //Imprime o estado da tarefa
    fprintf(arquivo, "\n\n<--------------------->\n");
    fclose(arquivo);//Fecha o arquivo

    printf("Informações inseridas no txt");
    //Confirmação para o usuário de que as informações estão no txt
}

void filtros(int op, int tam, lista *tarefas){
    //Casos para cada escolha de filtro
    if(op == 1) {
        int escolha, op1, op2;

        printf("Gostaria de estabelecer um intervalo de prioridade? (1 - sim/ 0 - nao)\n");
        //Pergunto se o usuário gostaria de um intervalo de prioridades.
        //Exemplo: Printar todas as tarefas de prioridade 1 - 3
        scanf("%d", &escolha);
        limpa();
        if (escolha == 1) {
            printf("Insira o inicio do intervalo de prioridade: ");
            scanf("%d", &op1);
            limpa();//Recebo o inicio e o fim do intervalo
            printf("Insira o fim do intervalo de prioridade: ");
            scanf("%d", &op2);
            limpa();
            for (int i = 0; i < tam; i++) {
                //Restrição para printar apenas os valores dentro do intervalo
                if(tarefas[i].prioridade >= op1 && op2 >= tarefas[i].prioridade){
                    printa(i, tarefas);
                }
            }
        }
        else
        {
            //Caso não queira um intervalo
            printf("Insira a prioridade: ");
            scanf("%d", &op1);
            limpa();
            for (int i = 0; i < tam; i++) {
                //Restricao para apenas a prioridade escolhida
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
        //Recebo a categoria desejada
        limpa();

        for (int i = 0; i < tam; i++) {
            if(strncmp(cat, tarefas[i].categoria, 21) == 0){
                //Restricao de categoria
                printa(i, tarefas);
            }
        }
    }
    else if(op ==3){
        int op1;

        printf("Insira o estado de tarefas que deseja acessar: (1 - Nao Iniciado / 2 - Em andamento / 3 - Completo\n");
        scanf("%d", &op1);
        limpa();
        //Recebo o estado das tarefas que o usuário deseja ver
        for (int i = 0; i < tam; i++) {
            if(tarefas[i].estado == op1){
                //Restricao de estado
                printa(i, tarefas);
            }
        }
    } else{
        int op1;
        char cat[20];
        //Caso o usuário queira inserir um filtro de prioridade e categoria
        printf("Insira a prioridade: ");
        scanf("%d", &op1);
        limpa();
        printf("Insira a categoria: ");
        scanf("%s", cat);
        //Recebo a prioridade e a categoria

        limpa();
        for (int i = 0; i < tam; i++) {
            //Restricao para ambos os fatores
            if(tarefas[i].prioridade == op1 && strncmp(cat, tarefas[i].categoria, 21) == 0){
                printa(i, tarefas);
            }
        }
    }
}

void menu(){
    //Função de menu
    printf("Bem vindo ao controle de tarefas!!!);"
           "\n-----------------------\n"
           "Insira o numero da operacao desejada: \n"
           "1. Criar Tarefas\n"
           "2. Deletar Tarefas\n"
           "3. Listar suas tarefas\n"
           "4. Alterar Tarefas\n"
           "5. Sair do controle de tarefas\n"
           "\n-----------------------\n");
}