#ifndef FILAESTATICA_H_INCLUDED
#define FILAESTATICA_H_INCLUDED
#define MAX 50

typedef struct fila {
char t[MAX][MAX][30];
char classi[MAX][MAX][30];
int tam;
int inicio;
int fim;
}Fila;

Fila *cria_fila();
void pushfila(Fila *f, char time[MAX],char times[MAX]);
Fila* popfila(Fila *f);
char *retornaf(Fila*f,char *v);
void imprimirf(Fila*f);
void liberafila(Fila*f);
int placar(Fila*f);

#endif // FILAESTICA_H_INCLUDED
