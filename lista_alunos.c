#include <stdio.h>
#include <stdlib.h>
#include "lista_alunos.h"

struct lista
{
    int quantidade;
    int tamanho;
    Aluno **alunos;
};

Lista *criaListaAlunos(int tamanhoLista)
{
    if (tamanhoLista > 0)
    {
        Lista *novaLista = (Lista *)malloc(sizeof(Lista));

        if (novaLista != NULL)
        {
            novaLista->quantidade = 0;
            novaLista->tamanho = tamanhoLista;
            novaLista->alunos = (Aluno **)malloc(tamanhoLista * sizeof(Aluno *));

            if (novaLista->alunos == NULL)
            {
                printf("Não existem alunos para a lista!\n");
                liberaLista(novaLista);
                exit(1);
            }

            return novaLista;
        }
        else
        {
            printf("Memória insuficiente para criação de lista\n");
            exit(1);
        }
    }
    else
    {
        printf("Tamanho da lista inválido!\n");
        exit(1);
    }
}

void liberaLista(Lista *l)
{
    if (l != NULL)
    {
        free(l->alunos);
        free(l);
    }
    else
    {
        printf("Memória insuficiente para liberação da lista!\n");
    }
}

int tamanhoLista(Lista *l)
{
    if (l != NULL)
    {
        return l->tamanho;
    }
    else
    {
        printf("Memória insuficiente para retornar tamanho da lista!\n");
        return -1;
    }
}

int listaCheia(Lista *l)
{
    if (l != NULL)
    {
        if (l->quantidade >= l->tamanho)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("Memória insuficiente para verificar se a lista está cheia!\n");
        return -1;
    }
}

int listaVazia(Lista *l)
{
    if (l != NULL)
    {
        if (l->quantidade <= 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("Memória insuficiente para verificar se a lista está vazia!\n");
        return -1;
    }
}

void insereAlunoInicio(Lista *l, Aluno *a)
{
    if (l != NULL && a != NULL)
    {
        int matriculaExistente = 0, i;

        if (l->quantidade < l->tamanho)
        {
            for (i = 0; i < l->quantidade; i++)
            {
                if (acessaMatricula(l->alunos[i]) == acessaMatricula(a))
                {
                    matriculaExistente = 1;
                    break;
                }
            }

            for (i = l->quantidade; i > 0; i--)
            {
                l->alunos[i] = l->alunos[i - 1];
            }

            if (matriculaExistente == 0)
            {
                l->alunos[0] = a;
                l->quantidade++;
            }
            else
            {
                printf("Matrícula já existente\nNão é possível inserir no início\n");
            }
        }
        else
        {
            printf("Passou do limite da lista!\n");
        }
    }
    else
    {
        printf("Memória insuficiente para inserir aluno no início");
    }
}

void insereAlunoFinal(Lista *l, Aluno *a)
{
    if (l != NULL && a != NULL)
    {
        int matriculaExistente = 0, i;

        for (i = 0; i < l->quantidade; i++)
        {
            if (acessaMatricula(l->alunos[i]) == acessaMatricula(a))
            {
                matriculaExistente = 1;
                break;
            }
        }
        
        if (matriculaExistente == 0)
        {
            l->alunos[l->quantidade] = a;
            l->quantidade++;
        }
        else
        {
            printf("Matrícula já existente\nNão é possível inserir no final\n");
        }
        
    }
    else
    {
        printf("Memória insuficiente para inserir aluno no final da lista!\n");
    }
}

// Mais funções em lista_alunos.h...

void imprimeAlunos(Lista *l)
{
    if (l != NULL)
    {
        for (int i = 0; i < l->quantidade; i++)
        {
            mostraAluno(l->alunos[i]);
        }
    }
    else
    {
        printf("Memória insuficiente para imprimir alunos!\n");
    }
}