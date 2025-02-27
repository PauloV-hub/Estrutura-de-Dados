#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "filaestatica.h"
#define MAX 50
Fila *cria_fila()
{
Fila *f = (Fila*)malloc(sizeof(Fila));
f->inicio = f->fim = 0;
f->tam=0;
return f;
}
void pushfila(Fila *f,char time[MAX],char times[MAX])
{
f->tam=0;
strcpy(f->t[f->fim][f->tam],time);     /*Armazeno no vetor[f->fim][0]*/
f->tam++;
strcpy(f->t[f->fim][f->tam],times);    /*Armazeno no vetor[f->fim][1]*/
f->fim = (f->fim+1)%MAX;
}
Fila*popfila(Fila *f)
{
f->inicio++;
}
int placar(Fila*f)    /*Retorna 1 para time 1 vencedor , e 0 para time 2*/
{
int x; int y;int k=strlen(f->t[f->inicio][f->tam]);
f->tam=0;
do{

x=rand()%8;         /*While para que nao haja empates*/
y=rand()%8;}
while(x==y);
if(k>15){k=15-k;}if(k<15){k+=15-k;}
printf(" %*s %*d x %*d %*s\n",k,f->t[f->inicio][f->tam],1,x,1,y,1,f->t[f->inicio][f->tam+1]);
if(x>y)            /*O espaçamento varia de acordo com o tamanho da string do time,*/
{return 1;            /*fazendo com que o espaçamento mais o tamanho da string seja igual a 15, em todos os casos*/
}else{
return 0;}
}
char* retornaf(Fila*f,char*v)
{
int x=placar(f);
f->tam=0;
if(x==1)
    {
        strcpy(f->classi[f->inicio][f->tam],f->t[f->inicio][f->tam+1]); /*Copio o time perdedor para outro vetor*/
        strcpy(v,f->t[f->inicio][f->tam]);
        return v;                          /*Retorno time vencedor*/
    }else if(x==0){
        strcpy(f->classi[f->inicio][f->tam],f->t[f->inicio][f->tam]);     /*Copio o time perdedor para outro vetor*/
        strcpy(v,f->t[f->inicio][f->tam+1]);
        return v;                               /*Retorno time vencedor*/
}
}
void imprimirf(Fila*f)
{
    int x=f->inicio;int i;
    char espaco[8]="   x   ";
    int y=f->fim;
    f->tam=0;
    int k;
    printf("\n Fila Inicial\n");
    while(f->fim!=0)
    {
        k=strlen(f->t[f->inicio][f->tam]);
        if(k>15){k=15-k;}if(k<15){k+=15-k;}       /*O espaçamento varia de acordo com o tamanho da string do time,*/
        printf(" %*s",k,f->t[f->inicio][f->tam]); /*fazendo com que o espaçamento mais o tamanho da string seja igual a 15, em todos os casos*/
        printf("%s",espaco);
        printf("%*s\n",1,f->t[f->inicio][f->tam+1]);
        f->fim--;f->inicio++;    /*Diminuindo o fim enquanto percorro a fila aumentando ini*/
    }
    f->inicio=x;
    f->fim=y;
}
void classificacao(Fila*f,int j)
{
int i=j-2;                 /*J-2 porque fiz o campeao e o vice for do loop*/
int x=3;
printf("    Vice : %s\n",f->classi[i][0]);
for(i=i-1;i>=0;i--)
{
if(x>=10){printf("%do lugar: %s\n",x,f->classi[i][0]);x++;}else{       /*Vetor que armazenei todos os perdedores em ordem*/
        printf(" %do lugar: %s\n",x,f->classi[i][0]);x++;}
}
}
