#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

Aluno* criaAluno(int matricula, float nota);
void liberaAluno(Aluno* a);
int acessaMatricula(Aluno* a);
float acessaNota(Aluno* a);
void atribuiNota(Aluno* a, float nota);
void atribuiMatricula(Aluno* a, int matricula);
void mostraAluno(Aluno* a);
int aprovacaoAluno(Aluno* a);

#endif