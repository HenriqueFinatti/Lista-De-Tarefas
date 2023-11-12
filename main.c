#include <stdio.h>
#include "biblioteca.h"
#include "biblioteca_aux.h"

lista tarefas[100];

int main() {
    int  chek = 0, escolha, tam, numero_tarefa, numero;

    tam = tamanho(tarefas);

    while (1) {

        menu();//Função de menu
        scanf("%d", &escolha);

        switch (escolha) {

            case(1)://Caso para criar tarefas
                if(tam == 100){
                    printf("Tamanho máximo de tarefas cadastradas, exclua algumas para cadastrar mais.\n");
                    //Condição para o limite de tarefas
                }
                else{
                    cria_tarefa(&tarefas[tam]);
                    tam++;
                }
                break;
            case(2):
                //Caso para a função de deletar tarefas
                printf("Insira o numero da tarefa que deseja deletar: ");
                scanf("%d", &numero_tarefa);
                deleta_tarefa(&tam, tarefas, numero_tarefa);
                break;

            case(3):
                //Cao para a função de listar tarefas
                ordena(tam, tarefas);
                lista_tarefas(tam, tarefas);
                break;

            case(4):
                //Caso para a função de alterar tarefas
                printf("Insira o numero da tarefa que deseja alterar: ");
                scanf("%d", &numero);
                altera_tarefa(tarefas, numero);
                break;

            case(5):
                //Caso para a função de saida
                printf("\nTchau :)\n");
                ordena(tam, tarefas);
                escreve(tam, tarefas);
                chek = 1;
                break;

            default:
                //Caso de função inválida
                printf("\nNumero invalido, escolha um numero valido\n");
                break;
        }
        if(chek)
            break;
    }
    printf("Controle de tarefas encerrado.\n\n");
}
