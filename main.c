#include <stdio.h>
#include "biblioteca.h" // Inclui um arquivo de cabeçalho personalizado
lista tarefas[100]; // Declara um array de tarefas com espaço para 100 elementos

int main() {
    int  chek = 0, escolha, tam; //Tres variaveis que serão usadas posteriomente para controle

    tam = tamanho(tarefas); // Obtém o tamanho atual da lista de tarefas

    printf("Bem vindo ao controle de tarefas!!!\n-----------------------\n");

    //While True para que o usuario tenha controle aos acessos com agilidade e eficiencia
    while (1) {
        // Apresenta um menu de opções ao usuário
        printf("\n1. Criar tarefas \n2. Deletar tarefas\n3. Listar suas tarefas\n4. Sair do controle de tarefas\n---------------------------\nInsira o numero da operacao desejada:  ");
        scanf("%d", &escolha);

        //Switch case é usado para menu de opções na qual o programa le a escolha do usuario.
        switch (escolha) {
            //Caso o usuario escolha 1, verifica se o tamanho atual da lista de tarefas é igual a 100 e exibe uma mensagem de erro.
            case(1):
                if(tam == 100){
                    printf("Tamanho máximo de tarefas cadastradas, exclua algumas para cadastrar mais.\n");
                }
                //Aqui chama a função criar tarefa passando o endereço da posição do array para criar uma nova tarefa
                printf("\nBem vindo a criacao de tarefas\n");
                cria_tarefa(&tarefas[tam]); // Chama a função para criar uma nova tarefa
                tam++; // Incrementa o tamanho da lista de tarefas
                break;
            case(2):
                //Caso o usuario escolha 2, irá chamar a função de deletar tarefa, passando o tamanho atual da lista, o array e o numero da tarefa.
                printf("\nBem vindo a remocao de tarefas\n");
                int numero_tarefa;
                printf("Insira o numero da tarefa que deseja deletar: ");
                scanf("%d", &numero_tarefa);
                deleta_tarefa(&tam, tarefas, numero_tarefa); // Chama a função para deletar uma tarefa
                break;

                //Cao seja 3, exibe uma mensagem de boas vindas e chama a função de listar tarefa, passando o tamanho atual da lista de terefas e o array de tarefas
            case(3):
                printf("\nBem vindo a lista de tarefas %d\n", tam);
                ordena(tam, tarefas);
                lista_tarefas(tam, tarefas); // Chama a função para listar as tarefas
                break;

                //Caso seja 4, dizemos tchau e a variavel chek passa como 1 para sair do loop.
            case(4):

                break;
            case(5):
                printf("\nTchau :)\n");
                ordena(tam, tarefas);
                escreve(tam, tarefas); // Chama a função para escrever as tarefas em um arquivo e encerra o programa
                chek = 1; // Define a variável 'chek' como 1 para sair do loop
                break;
            default:
                printf("\nNumero invalido, escolha um numero valido\n"); // Mensagem de erro para escolha inválida
                break;
        }
        if(chek) // Sai do loop se 'chek' for igual a 1
            break;
    }
    printf("Controle de tarefas encerrado.\n\n");
}
