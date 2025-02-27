#include <stdio.h>
#include "pilhaestatica.h"
#define MAX 30
Pilha *cria_pilha()
{
    Pilha*p=(Pilha*)malloc(sizeof(Pilha));
    p->topo=-1;
    return p;
}

void push(Pilha *p,char times[MAX])
{
    if(p->topo>MAX)return printf("Pilha Cheia");
    p->topo++;
    strcpy(p->v[p->topo],times);
}
Pilha* pop(Pilha *p)
{
p->topo--;
return p;
}
char* retornap(Pilha *p,char *v)
{
strcpy(v,p->v[p->topo]);       /*Retorno o conteudo*/
return v;
}
