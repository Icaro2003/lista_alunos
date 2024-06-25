#include <stdio.h>
#include <stdlib.h>
#include "lista_alunos.h"

struct lista
{
    int quantidade;
    int tamanho;
    Aluno **alunos;
};

// Esta função aloca uma lista e depois aloca um vetor de Aluno* (ponteiro de Aluno). Verifique se a quantidade de alunos é um valor positivo maior que 0, e se a alocação dinâmica funcionou, senão imprima uma mensagem de erro.
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

// Função que libera a toda a memória alocada para a lista.
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

// Função que retorna o tamanho da lista.
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

// Função que retorna 1 se a lista atingir seu tamanho maximo e 0 se não.
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

// Função que retorna 1 se a lista nao houver elementos e 0 se houver.
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

// Função que insere um aluno na primeira posição da lista. Não é possível inserir um aluno com uma matrícula já existente.
void insereAlunoInicio(Lista *l, Aluno *a)
{
    if (l != NULL && a != NULL)
    {
        if (listaCheia(l) == 0)
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
            printf("Lista cheia não é possível inserir elementos!\n");
        }
    }
    else
    {
        printf("Memória insuficiente para inserir aluno no início");
    }
}

// Função que insere um aluno na última posição da lista. Não é possível inserir um aluno com uma matrícula já existente.
void insereAlunoFinal(Lista *l, Aluno *a)
{
    if (l != NULL && a != NULL)
    {
        if (listaCheia(l) == 0)
        {
            int matriculaExistente = 0;

            for (int i = 0; i < l->quantidade; i++)
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
            printf("Lista cheia não é possível inserir elementos!\n");
        }
    }
    else
    {
        printf("Memória insuficiente para inserir aluno no final da lista!\n");
    }
}

// Função que remove um aluno da primeira posição da lista.
void removeAlunoInicio(Lista *l)
{
    if (l != NULL)
    {
        for (int i = 0; i < l->quantidade; i++)
        {
            l->alunos[i] = l->alunos[i + 1];
        }

        l->quantidade--;
    }
    else
    {
        printf("Memória insuficiente para remover aluno do início da lista!\n");
    }
}

// Função que altera o conteúdo de uma determinada posição i. Cuidado para não modificar a matrícula de um aluno com uma matrícula já existente.
void modificaAluno(Lista *l, int i, Aluno *a)
{
    if (l != NULL && a != NULL)
    {
        if (i >= 0 && i < l->quantidade)
        {
            if (acessaMatricula(l->alunos[i]) == acessaMatricula(a))
            {
                int encontrado = 0;
                int matricula;
                float nota;

                printf("Informe uma matrícula: ");
                scanf("%d", &matricula);

                printf("Informe uma nota: ");
                scanf("%f", &nota);

                for (int j = 0; j < l->quantidade; j++)
                {
                    if (acessaMatricula(l->alunos[j]) == matricula)
                    {
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado == 0)
                {
                    atribuiMatricula(l->alunos[i], matricula);
                    atribuiNota(l->alunos[i], nota);
                }
                else
                {
                    printf("Matrícula já existente!\nNão é possível modificar!\n");
                }
            }
            else
            {
                printf("Matrícula não existente!\nNão é possível modificar!\n");
            }
        }
        else
        {
            printf("Posição inválida para modificar aluno!\n");
        }
    }
    else
    {
        printf("Memória insuficiente para modificar aluno!\n");
    }
}

// Função que remove um aluno da última posição da lista.
void removeAlunoFinal(Lista *l)
{
    if (l != NULL)
    {
        if (listaVazia(l) == 0)
        {
            l->quantidade--;
        }
    }
    else
    {
        printf("Memória insuficiente para remover aluno do final da lista!\n");
    }
}

// Função que remove um aluno da lista.
void removeAluno(Lista *l, Aluno *a)
{
    if (l != NULL && a != NULL)
    {
        int encontrado = 0;
        for (int i = 0; i < l->quantidade; i++)
        {
            if (acessaMatricula(l->alunos[i]) == acessaMatricula(a))
            {
                encontrado = 1;
                break;
            }
        }

        if (encontrado == 1)
        {
            l->quantidade--;
        }
        else
        {
            printf("Matrícula já existente!\nNão é possível remover o aluno da lista\n");
        }
    }
    else
    {
        printf("Memória insuficiente para remover aluno da lista!\n");
    }
}

// Função que mostra o aluno em uma posição i.
void consultaPosicao(Lista *l, int i)
{
    if (l != NULL)
    {
        if (i >= 0 && i < l->quantidade)
        {
            mostraAluno(l->alunos[i]);
        }
    }
    else
    {
        printf("Memória insuficiente para consultar aluno!\n");
    }
}

// Função que retorna a posição de um aluno com uma matricula m.
int buscaPorMatricula(Lista *l, int m)
{
    if (l != NULL && m > 0)
    {
        int encontrado = 0, cont;

        for (int i = 0; i < l->quantidade; i++)
        {
            if (acessaMatricula(l->alunos[i]) == m)
            {
                encontrado = 1;
                cont = i;
                break;
            }
        }

        if (encontrado == 1)
        {
            return cont;
        }
        else
        {
            printf("Matrícula não encontrada!\n");
            return -1;
        }
    }
    else
    {
        printf("Memória insuficiente para buscar por matrícula!\n");
        return -1;
    }
}

// Função que imprime todos os alunos da lista.
void imprimeAlunos(Lista *l)
{
    if (l != NULL)
    {
        if (listaVazia(l) == 1)
        {
            printf("Lista vazia!\n");
        }

        for (int i = 0; i < l->quantidade; i++)
        {
            consultaPosicao(l, i);
        }
    }
    else
    {
        printf("Memória insuficiente para imprimir alunos!\n");
    }
}

// Função que apaga todos os alunos da lista.
void apagaLista(Lista *l)
{
    if (l != NULL)
    {
        int quantidade = l->quantidade;

        for (int i = 0; i < quantidade; i++)
        {
            l->quantidade--;
        }
    }
    else
    {
        printf("Memória insuficiente para apagar lista!\n");
    }
}

// Função que retorna a maior nota existente entre os alunos.
float maiorNota(Lista *l)
{
    if (l != NULL)
    {
        float maior = 0;
        for (int i = 0; i < l->quantidade; i++)
        {
            if (acessaNota(l->alunos[i]) > maior)
            {
                maior = acessaNota(l->alunos[i]);
            }
        }

        return maior;
    }
    else
    {
        printf("Memória insuficiente para retornar a maior nota!\n");
        return -1.0;
    }
}

// Função que retorna a menor nota existente entre os alunos.
float menorNota(Lista *l)
{
    if (l != NULL)
    {
        float menor = maiorNota(l);
        for (int i = 0; i < l->quantidade; i++)
        {
            if (acessaNota(l->alunos[i]) < menor)
            {
                menor = acessaNota(l->alunos[i]);
            }
        }

        return menor;
    }
    else
    {
        printf("Memória insuficiente para retornar a menor nota!\n");
        return -1.0;
    }
}

// Função que retorna a média de todas as notas.
float mediaNotas(Lista *l)
{
    if (l != NULL)
    {
        float media, soma = 0;

        for (int i = 0; i < l->quantidade; i++)
        {
            soma += acessaNota(l->alunos[i]);
        }
        
        media = soma / l->quantidade;

        return media;
    }
    else
    {
        printf("Memória insuficiente para retornar a média da lista!\n");
        return -1.0;
    }
    
}