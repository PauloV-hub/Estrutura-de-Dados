#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED
#define MAX 30
typedef struct nodo
{
    char time1[MAX];
    char time2[MAX];
    char time3[MAX];
    struct nodo*prox;
}nodo;
typedef struct fila{
nodo *inicio;
nodo *fim;
nodo*aux;
}Fila;
Fila *cria_fila();
void pushfila(Fila *f, char time[MAX],char times[MAX]);
Fila* popfila(Fila *f);
char*retornaf(Fila*f,char*v);
void imprimirf(Fila*f);
int placar(Fila*f);
void classificacao(Fila*f,int j);
#endif // FILAESTATICA_H_INCLUDED
