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
                free(novaLista);
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

// Mais funções em lista_alunos.h...