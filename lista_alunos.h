#ifndef LISTA_ALUNOS_H
#define LISTA_ALUNOS_H

#include "aluno/aluno.h"

typedef struct lista Lista;

Lista *criaListaAlunos(int tamanho_lista);
void liberaLista(Lista *l);
int tamanhoLista(Lista *l);
int listaCheia(Lista *l);
int listaVazia(Lista *l);
void insereAlunoInicio(Lista *l, Aluno *a);
void insereAlunoFinal(Lista *l, Aluno *a);
void removeAlunoInicio(Lista *l);
void modificaAluno(Lista *l, int i, Aluno *a);
void removeAlunoFinal(Lista *l);
void removeAluno(Lista* l, Aluno* a);
void consultaPosicao(Lista* l, int i);
int buscaPorMatricula(Lista* l, int m);
void imprimeAlunos(Lista* l);
void apagaLista(Lista* l);
float maiorNota(Lista* l);
float menorNota(Lista* l);
float mediaNotas(Lista* l);

#endif