#include <stdio.h>
#include <stdlib.h>

typedef struct E{
    int dado;
    struct E *ant;
    struct E *prox;
} t_elemento;

int len(t_elemento *inicio){
    int tam = 0;

    if(inicio == NULL){
        return 0;
    }

    while(inicio -> prox != NULL){
        tam++;
        inicio = inicio -> prox;
    }
    return tam + 1;
}

t_elemento *append(t_elemento *inicio, t_elemento *fim, int valor){
    t_elemento *no = malloc(sizeof(t_elemento));
    no -> dado = valor;
    no -> ant = fim;
    no -> prox = NULL;
    return inicio;
}

int main(){
    t_elemento *lista, *fim;
    lista = (t_elemento *)malloc(sizeof(t_elemento));
    lista -> dado = 23;
    lista -> ant = NULL;
    lista -> prox = (t_elemento *)malloc(sizeof(t_elemento));
    fim = lista -> prox;

    fim -> dado = 45;
    fim -> ant = lista;
    fim -> prox = (t_elemento *)malloc(sizeof(t_elemento));
    fim = fim -> prox;

    fim -> dado = 97;
    fim -> ant = lista -> prox;
    fim -> prox = NULL;


    printf("%d\n", len(lista));
    lista = append(lista, fim, 233);
    printf("%d", len(lista));

    return 0;
}
