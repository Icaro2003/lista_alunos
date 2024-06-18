#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

struct aluno
{
    int matricula;
    float nota;
};

Aluno *criaAluno(int matricula, float nota)
{
    if ((matricula >= 0) && (nota >= 0 && nota <= 10))
    {
        Aluno *novo = (Aluno *)malloc(sizeof(Aluno));

        if (novo == NULL)
        {
            printf("Memoria Insuficiente!\n");
            exit(1);
        }

        novo->matricula = matricula;
        novo->nota = nota;

        return novo;
    }
    else
    {
        printf("Nota ou Matricula invalida!\n");
        return NULL;
    }
}

void liberaAluno(Aluno *a)
{
    if (a != NULL)
    {
        free(a);
    }
    else
    {
        printf("Aluno invalido!\n");
    }
}

int acessaMatricula(Aluno *a)
{
    if (a != NULL)
    {
        return a->matricula;
    }
    else
    {
        printf("Aluno invalido!\n");
        return -1;
    }
}

float acessaNota(Aluno *a)
{
    if (a != NULL)
    {
        return a->nota;
    }
    else
    {
        printf("Aluno invalido!\n");
        return -1;
    }
}

void atribuiNota(Aluno *a, float nota)
{
    if (a != NULL)
    {
        if (nota >= 0 && nota <= 10)
        {
            a->nota = nota;
        }
        else
        {
            printf("Nota invalida!\n");
        }
    }
    else
    {
        printf("Aluno invalido!\n");
    }
}

void atribuiMatricula(Aluno *a, int matricula)
{
    if (a != NULL)
    {
        if (matricula >= 0)
        {
            a->matricula = matricula;
        }
        else
        {
            printf("Matricula invalida!\n");
        }
    }
    else
    {
        printf("Aluno invalido!\n");
    }
}

void mostraAluno(Aluno *a)
{
    if (a != NULL)
    {
        printf("Matricula: %d -- Nota: %.1f\n", a->matricula, a->nota);
    }
    else
    {
        printf("Aluno invalido!\n");
    }
}

int aprovacaoAluno(Aluno *a)
{
    if (a != NULL)
    {
        if (a->nota >= 5)
        {
            printf("Aluno Aprovado!\n");
            return 1;
        }
        else
        {
            printf("Aluno Reprovado!\n");
            return 0;
        }
    }
    else
    {
        printf("Aluno invalido!\n");
        return -1;
    }
}
