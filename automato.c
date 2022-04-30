#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

//---------------------------------------------------------//
//-----------------------PilhaDinamica---------------------//
//---------------------------------------------------------//
typedef struct NoPilha* PtrNoPilha;

//---------------------------------------------------------//
typedef struct NoPilha {//struct NoPilha
    char objeto;
    PtrNoPilha prox;
}NoPilha;

//---------------------------------------------------------//
typedef struct {//struct PilhaDinamica
    PtrNoPilha topo;
    int tamanho;
}PilhaDinaminca;

//---------------------------------------------------------//
void iniciaDinamica(PilhaDinaminca* pilha) {//inicia PilhaDinamica
    pilha->topo = NULL;//topo inicia em NULL
    pilha->tamanho = 0;// tamanho � igual a 0
}//iniciaDinamica

//---------------------------------------------------------//
bool vazioDinamica(PilhaDinaminca* pilha) {
    if (pilha->topo == NULL) {//verifica se o topo � igual a NULL
        printf("A pilha dinamica esta vazia");
    }
    else {
        printf("Nao esta vazio");
    }
}//vazioDinamica

//---------------------------------------------------------//
void empilhaDinamica(char letra, PilhaDinaminca* pilha) {//empilha um numero dentro da pilha
    PtrNoPilha aux;
    aux = (PtrNoPilha)malloc(sizeof(NoPilha));
    aux->objeto = letra;//aux recebe o numero
    aux->prox = pilha->topo;// o proximo recebe o topo
    pilha->topo = aux;//topo recebe aux
    pilha->tamanho++;// aumenta 1 no tamanho
}//empilhaDinamica

//---------------------------------------------------------//
int desempilhaDinamica(PilhaDinaminca* pilha) {
    char letra;
    if (!(pilha->topo == NULL)) {//se for diferente de NULL vai come�ar a desempilhar
        PtrNoPilha aux;//ponteiro para um no de pilha
        aux = pilha->topo;//aux recebe topo da pilha
        letra = aux->objeto;// letra recebe o Letra que vai desempilhar
        pilha->topo = aux->prox;//topo recebendo o proximo do aux
        free(aux);//libera memoria do aux
        pilha->tamanho--;//diminui o tamanho 
        return letra;//retorna o Letra para a main
    }
    else {
        printf("Pilha esta Vazia");
    }
}//desempilhaDinamica

//---------------------------------------------------------//
void tamanhoDinamica(PilhaDinaminca* pilha) {
    printf("tamanho = %d\n", pilha->tamanho);
}//tamanhoDinamica

//---------------------------------------------------------//
void topoDinamica(PilhaDinaminca* pilha) {// mostra o tamanho da pilha
    PtrNoPilha aux;// onteiro n� de pilha
    aux = pilha->topo;//aux recebe o proximo
    printf("Topo = %c", aux->objeto);//monstrando o letra do topo
}//topoDinamica

//---------------------------------------------------------//
void imprimeDinamica(PilhaDinaminca* pilha) {
    PtrNoPilha aux;//ponteiro n� de pilha
    printf("{ ");
    for (aux = pilha->topo; aux != NULL; aux = aux->prox) {//condi��o
        printf("%c", aux->objeto);
    }//for
    printf("}\n");
}//imprimeDinamica

//---------------------------------------------------------//
void destruirDinamica(PilhaDinaminca* pilha) {
    while (!(pilha->topo == NULL)) {//condi��o
        PtrNoPilha aux;//ponteiro n� de pilha
        aux = pilha->topo;//aux recebendo o topo
        pilha->topo = aux->prox;//topo recebendo o proximo
        free(aux);//liberando memoria
        pilha->tamanho--;//diminuindo o tamanho menos 1
    }//while
}//destruirDinamica

//---------------------------------------------------------//

//---------------------------------------------------------//

int main() {
    


    return 0;
         
}

