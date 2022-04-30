#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

//---------------------------------------------------------//
//-----------------------PilhaDinamica---------------------//
//---------------------------------------------------------//
typedef struct NoPilha *PtrNoPilha;

//---------------------------------------------------------//
typedef struct NoPilha
{ // struct NoPilha
    char objeto;
    PtrNoPilha prox;
} NoPilha;

//---------------------------------------------------------//
typedef struct
{ // struct PilhaDinamica
    PtrNoPilha topo;
    int tamanho;
} PilhaDinamica;

//---------------------------------------------------------//
void iniciaDinamica(PilhaDinamica *pilha)
{                       // inicia PilhaDinamica
    pilha->topo = NULL; // topo inicia em NULL
    pilha->tamanho = 0; // tamanho é igual a 0
} // iniciaDinamica

//---------------------------------------------------------//
bool vazioDinamica(PilhaDinamica *pilha)
{
    if (pilha->topo == NULL)
    { // verifica se o topo é igual a NULL
        printf("A pilha dinamica esta vazia");
    }
    else
    {
        printf("Nao esta vazio");
    }
} // vazioDinamica

//---------------------------------------------------------//
void empilhaDinamica(char letra, PilhaDinamica *pilha)
{ // empilha um numero dentro da pilha
    PtrNoPilha aux;
    aux = (PtrNoPilha)malloc(sizeof(NoPilha));
    aux->objeto = letra;     // aux recebe o numero
    aux->prox = pilha->topo; // o proximo recebe o topo
    pilha->topo = aux;       // topo recebe aux
    pilha->tamanho++;        // aumenta 1 no tamanho
} // empilhaDinamica

//---------------------------------------------------------//
int desempilhaDinamica(PilhaDinamica *pilha)
{
    char letra;
    if (!(pilha->topo == NULL))
    {                            // se for diferente de NULL vai come�ar a desempilhar
        PtrNoPilha aux;          // ponteiro para um no de pilha
        aux = pilha->topo;       // aux recebe topo da pilha
        letra = aux->objeto;     // letra recebe o Letra que vai desempilhar
        pilha->topo = aux->prox; // topo recebendo o proximo do aux
        free(aux);               // libera memoria do aux
        pilha->tamanho--;        // diminui o tamanho
        return letra;            // retorna o Letra para a main
    }
    else
    {
        printf("Pilha esta Vazia");
    }
} // desempilhaDinamica

//---------------------------------------------------------//
void tamanhoDinamica(PilhaDinamica *pilha)
{
    printf("tamanho = %d\n", pilha->tamanho);
} // tamanhoDinamica

//---------------------------------------------------------//
void topoDinamica(PilhaDinamica *pilha)
{                                     // mostra o tamanho da pilha
    PtrNoPilha aux;                   // ponteiro nó de pilha
    aux = pilha->topo;                // aux recebe o proximo
    printf("Topo = %c", aux->objeto); // monstrando o letra do topo
} // topoDinamica

//---------------------------------------------------------//
void imprimeDinamica(PilhaDinamica *pilha)
{
    PtrNoPilha aux; // ponteiro nó de pilha
    for (aux = pilha->topo; aux != NULL; aux = aux->prox)
    { // condição
        printf("%c", aux->objeto);
    } // for
} // imprimeDinamica

//---------------------------------------------------------//
void destruirDinamica(PilhaDinamica *pilha)
{
    while (!(pilha->topo == NULL))
    {                            // condição
        PtrNoPilha aux;          // ponteiro nó de pilha
        aux = pilha->topo;       // aux recebendo o topo
        pilha->topo = aux->prox; // topo recebendo o proximo
        free(aux);               // liberando memoria
        pilha->tamanho--;        // diminuindo o tamanho menos 1
    }                            // while
} // destruirDinamica

//---------------------------------------------------------//
void automatoPar(PilhaDinamica *pilha, char *string, int contador1, int meio)
{
    char letra;
    int contador2 = 0;
    for (int i = 0; i < contador1; i++)
    {
        letra = string[i];
        contador2++;
        if (contador2 <= meio)
        {
            empilhaDinamica(letra, pilha);
        }
        else if (contador2 > meio)
        {
            if (letra == pilha->topo)
            {
                desempilhaDinamica(pilha);
            }
        }
    }
    if (pilha->topo == NULL)
    {
        printf("palavra -> %s eh um palindromo", string);
    }
    else
    {
        printf("palavra -> %s nao eh um palindromo", string);
    }

    destruirDinamica(pilha);
}

//---------------------------------------------------------//
void automatoImPar(PilhaDinamica *pilha, char *string, int contador1, int meio)
{
    char letra;
    int contador2 = 1;
    //printf("a string eh %s\n", string);
    //printf("a contador1 eh %d\n", contador1);
    for (int i = 0; i < contador1; i++){
        letra = string[i];
        printf("letra na posicao [%d] eh %c\n", i, letra);
        contador2++;
        if (contador2 <= meio){
            empilhaDinamica(letra, &pilha);
            printf("letra %c empilhada com sucesso\n", letra);
        }
        else if (contador2 > meio)
        {
            if (letra == pilha->topo)
            {
                desempilhaDinamica(pilha);
            }
        }
    }
    
    if (pilha->topo == NULL){
        printf("palavra -> %s eh um palindromo", string);
    }
    else
    {
        printf("palavra -> %s nao eh um palindromo", string);
    }

    destruirDinamica(pilha);
    
}

//---------------------------------------------------------//
int main()
{

    // aabbaa  6/2 = 0 -> 2  a 1, a 2, b 3, b == topo, b desempilha b , topo == a topo é vazio
    // aabbaa é palindromo

    PilhaDinamica p;
    iniciaDinamica(&p);

    int contador1 = 0, meio;
    char string[100];
    printf("Digite a palavra para descobrir se eh um palindromo\n");
    scanf("%s", string);

    contador1 = strlen(string);
    meio = contador1 / 2;
   

    if (contador1 % 2 == 0){
        //        printf("%s eh par\n", string);
        automatoPar(&p, string, contador1, meio);
    }
    else
    {
        //        printf("%s eh impar\n", string);
        automatoImPar(&p, string, contador1, meio);
    }

    return 0;
}
