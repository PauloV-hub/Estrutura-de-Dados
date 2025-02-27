#include <stdio.h>
#include <string.h>
#include <time.h>
#include "filadinamica.h"
#define MAX 30
Fila *cria_fila() {
Fila *f = (Fila*)malloc(sizeof(Fila));
f->inicio = f->fim = NULL;
return f;
}
void pushfila(Fila *f,char time[MAX],char times[MAX]) {
nodo *novo = (nodo*)malloc(sizeof(nodo));
strcpy(novo->time1,time);                   /*Aramazeno dois times em uma posicao da fila*/
strcpy(novo->time2,times);
novo->prox = NULL;
if (f->fim != NULL)
{
    f->fim->prox = novo;
}
f->fim = novo;
if (f->inicio==NULL)
    f->inicio = novo;
}
char* retornaf(Fila*f,char*v)
{
int x=placar(f);
if(x==1)
    {
        strcpy(f->inicio->time3,f->inicio->time2);         /*Aramazeno o time perdedor em um vetor auxiliar*/
        strcpy(v,f->inicio->time1);
        return v;
    }else {
        strcpy(f->inicio->time3,f->inicio->time1);         /*Aramazeno o time perdedor em um vetor auxiliar*/
        strcpy(v,f->inicio->time2);
        return v;
        }
}
Fila*popfila(Fila *f)
{
nodo *aux = f->inicio->prox;
 if(f->fim == f->inicio)
    f->fim= NULL;
f->inicio = aux;
 }

int placar(Fila*f)
{
    int k=strlen(f->inicio->time1);
int x; int y;
do{
x=rand()%8;
y=rand()%8;}
while(x==y);
if(k>15){k=15-k;}if(k<15){k+=15-k;}   /*O espaçamento varia de acordo com o tamanho da string do time,*/
printf(" %*s %*d x %*d %*s\n",k,f->inicio->time1,1,x,1,y,1,f->inicio->time2);/*fazendo com que o espaçamento mais o tamanho da string seja igual a 15, em todos os casos*/
if(x>y)
{
    return 1;
}else{
return 0;}
}
void imprimirf(Fila*f)
{
    nodo*aux=f->inicio;
    f->aux=f->inicio;               /*Armazena o inicio da fila em f->aux*/
    char espaco[8]="   x   ";
    int k;
    while(f->inicio!=NULL)
    {
    k=strlen(f->inicio->time1);
    if(k>15){k=15-k;}if(k<15){k+=15-k;}
    printf("      %*s",k,f->inicio->time1);
    printf("%s",espaco);
    printf("%*s\n",1,f->inicio->time2);
    f->inicio=f->inicio->prox;
    }
    f->inicio=aux;
}
void classificacao(Fila*f,int j)
{
    char vet[j+1][MAX];int i;int x=3;
    printf("     Vice: %s\n",f->inicio->time3);
    f->inicio=f->aux;                 /*F->aux esta armazenado o inicio da fila antes de usar os pop*/
        for(i=0;i<j-1;i++)
        {
            if(f->inicio==NULL)break;
            strcpy(vet[i],f->inicio->time3);          /*Times peredores estao em ordem inversa*/
            f->inicio=f->inicio->prox;                /*Armazenei em um vetor*/
        }
        for(i=j-3;i>=0;i--)                           /*j-3 por fazer o campeao e o vice fora do loop*/
        {
            if(x>=10){printf("%do lugar: %s\n",x,vet[i]);x++;}    /*Imprimi em ordem inversa*/
            else{printf(" %do lugar: %s\n",x,vet[i]);x++;}
        }
}
