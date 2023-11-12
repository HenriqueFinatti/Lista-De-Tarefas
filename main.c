#include <stdio.h>
#include "biblioteca.h"
#include "biblioteca_aux.h"

lista tarefas[100];

int main() {
    int  chek = 0, escolha, tam;

    tam = tamanho(tarefas);

    printf("Bem vindo ao controle de tarefas!!!\n-----------------------\n");


    while (1) {

        printf("\n1. Criar tarefas \n2. Deletar tarefas\n3. Listar suas tarefas\n4. Alterar Tarefas\n 5. Sair do controle de tarefas\n---------------------------\nInsira o numero da operacao desejada:  ");
        scanf("%d", &escolha);


        switch (escolha) {

            case(1):
                if(tam == 100){
                    printf("Tamanho máximo de tarefas cadastradas, exclua algumas para cadastrar mais.\n");
                }

                printf("\nBem vindo a criacao de tarefas\n");
                cria_tarefa(&tarefas[tam]);
                tam++;
                break;
            case(2):

                printf("\nBem vindo a remocao de tarefas\n");
                int numero_tarefa;
                printf("Insira o numero da tarefa que deseja deletar: ");
                scanf("%d", &numero_tarefa);
                deleta_tarefa(&tam, tarefas, numero_tarefa);
                break;

            case(3):
                printf("\nBem vindo a lista de tarefas \n");
                ordena(tam, tarefas);
                lista_tarefas(tam, tarefas);
                break;

            case(4):
                printf("Bem Vindo a Alterar Tarefas\n");
                int numero;
                printf("Insira o numero da tarefa que deseja alterar: ");
                scanf("%d", &numero);
                altera_tarefa(tarefas, numero);
                break;
            case(5):
                printf("\nTchau :)\n");
                ordena(tam, tarefas);
                escreve(tam, tarefas);
                chek = 1;
                break;
            default:
                printf("\nNumero invalido, escolha um numero valido\n");
                break;
        }
        if(chek)
            break;
    }
    printf("Controle de tarefas encerrado.\n\n");
}
