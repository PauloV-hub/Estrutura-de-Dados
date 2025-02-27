#include <stdio.h>
#include <string.h>
#include "pilhadinamica.h"
#define MAX 30
Pilha*cria_pilha()
{
    Pilha*p=(Pilha*)malloc(sizeof(Pilha));
    p->topo=NULL;
    return p;
}
void push(Pilha*p,char times[MAX])
{
    Nodo*novo=(Nodo*)malloc(sizeof(Nodo));
    strcpy(novo->t,times);
    novo->prox=p->topo;
    p->topo=novo;
}
char* retornap(Pilha *p,char *v)
{
strcpy(v,p->topo->t);            /*Retorna o conteudo*/
return v;
}
Pilha *pop(Pilha *p) {

free(p->topo);
p->topo = p->topo->prox;
return p;
}
