#ifndef LISTA_DE_TAREFAS_BIBLIOTECA_H
#define LISTA_DE_TAREFAS_BIBLIOTECA_H

typedef struct {
    int prioridade; //inteiro que representa a prioridade da tarefa
    char categoria[300]; //  array de caractere com espaço para 300 char que armazena a categoria.
    char descricao[100]; // outro array de caractere com espaço de 100, na qual armazena a descrição da tarefa
    int estado;
}lista;

//Aqui sao definidas as funções que serão definidas no arquivo .c

void cria_tarefa( lista *tarefas);
void lista_tarefas(int tam,  lista *tarefas);
void deleta_tarefa(int *tam,  lista *tarefas, int numero_tarefa);
void altera_tarefa( lista *tarefas, int numero_tarefa);

#endif //LISTA_DE_TAREFAS_BIBLIOTECA_H
