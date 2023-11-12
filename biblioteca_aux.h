
#ifndef LISTA_DE_TAREFAS_BIBLIOTECA_AUX_H
#define LISTA_DE_TAREFAS_BIBLIOTECA_AUX_H

//Declaro as funções do arquivo "biblioteca_aux.c"
void escreve(int tam,  lista *tarefas);
int tamanho( lista *tarefas);
void ordena(int tam,  lista *tarefas);
void filtros(int op, int tam, lista *tarefas);
void limpa();
void printa(int ind, lista *tarefas);
void menu();
#endif //LISTA_DE_TAREFAS_BIBLIOTECA_AUX_H
