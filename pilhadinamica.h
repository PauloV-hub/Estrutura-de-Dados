#ifndef PILHADINAMICA_H_INCLUDED
#define PILHADINAMICA_H_INCLUDED
#define MAX 30
typedef struct Nodo{
char t[MAX];
struct Nodo*prox;
}Nodo;
typedef struct Pilha
{
    Nodo*topo;
}Pilha;
Pilha* cria_pilha();
void push(Pilha*p,char times[MAX]);
void imprimir(Pilha*f);
Pilha *pop(Pilha *p);
int vazia(Pilha*p);
char* retornap(Pilha*p,char *v);
#endif // PILHADINAMICA_H_INCLUDED
