#ifndef PILHAESTATICA_H_INCLUDED
#define PILHAESTATICA_H_INCLUDED
#define MAX 30
typedef struct pilha {
char v[MAX][MAX];
int topo;
}Pilha;
Pilha *cria_pilha();
void push(Pilha *p, char times[MAX]);
void imprimir(Pilha*p);
Pilha* pop(Pilha *p);
char* retornap(Pilha*p,char *v);
#endif // PILHAESTATICA_H_INCLUDED
