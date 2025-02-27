#include <stdio.h>
#include <stdlib.h>
#include "pilhaestatica.h"
#include "filaestatica.h"
#include <time.h>
#define MAX 30
int main()
{
    int i,x=0,k=0,j,tam;
    char tt[50][MAX];
    char *v=malloc(sizeof(char));
    char *p=malloc(sizeof(char));
    Pilha *vetor[MAX];
    Fila*f=cria_fila();
    scanf("%d %d",&j,&k);
    for(i=0;i<k;i++)
    {
        vetor[i]=cria_pilha();              /*Crio vetores de pilhas*/
    }
    for(i=0;i<j;i++)
    {
        if(x==k)                           /*Se a variavel for igual o numero de potes*/
        {
           x=0;                             /*Eu retorno ela a 0, para voltar ao pote inicial*/
        }
        scanf("%s",&tt[i]);
        push(vetor[x],&tt[i]);
        x++;
    }
    x=0;
    for(i=0;i<=j;i++)
    {

        if((i%2)==0 && (i>0))               /*Variavel for par e maior que 0 enfilero*/
        {
            pushfila(f,v,p);        /*Push nos times armazenados*/

        }if(i==j){break;}
        if(x==k)                    /*Se a variavel for igual o numero de potes*/
        {
           x=0;                     /*Eu retorno ela a 0, para voltar ao pote inicial*/
        }

        if(i%2==0)
            {
            v=retornap(vetor[x],v);  /*Armazeno o time 1*/
            vetor[x]=pop(vetor[x]);
            }
        else{
            p=retornap(vetor[x],p);  /*Armazeno time 2*/
            vetor[x]=pop(vetor[x]);
            }
        x++;
    }
    imprimirf(f);
   tam=j/2;
   srand(time(NULL));  /*Nao repetir os resultados*/
    for(i=1;i<=tam;i++)/*Percorrendo a fila*/
    {
        if(i==tam)                     /*No ultimo  confronto eu terei apenas um POP*/
        {
            printf("\n Grande Final\n");
            v=retornaf(f,v);           /*retorna o time vencedor do confronto*/
            printf("\n  Campeao: %s\n",v);
            classificacao(f,j);        /*Tabela do campeao ao ultimo colocado*/
            break;
        }
    printf("\n Dia %d:\n",i);
    v=retornaf(f,v);               /*retorna o time vencedor do confronto*/
    f=popfila(f);                  /*Desenfilera e atualiza f*/
    p=retornaf(f,p);               /*retorna o time vencedor do confronto*/
    f=popfila(f);                  /*Desenfilera e atualiza f*/
    pushfila(f,v,p);                /*Enfilera os dois times vencedores*/
    }
    free(f);
    free(v);
    free(p);
    free(vetor);
    return 0;
}
