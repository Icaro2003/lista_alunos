#include <stdio.h>
#include <stdlib.h>
#include "lista_alunos.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int matricula = 552838;
    float nota = 10;
    int tamanhoListaAlunos = 8;

    Aluno *aluno1 = criaAluno(matricula, nota);
    Lista *listaAlunos = criaListaAlunos(tamanhoListaAlunos);
    int encheu = listaCheia(listaAlunos);
    int vazio = listaVazia(listaAlunos);

    if (listaAlunos != NULL && aluno1 != NULL)
    {
        printf("Criou\n");
    }
    else
    {
        printf("Faiou\n");
    }

    if (encheu == 1)
    {
        printf("Lista está cheia\n");
    }
    else
    {
        printf("Cabe mais\n");
    }
    
    if (vazio == 1)
    {
        printf("Sem nada\n");
    }
    else
    {
        printf("Tem coisa\n");
    }
    

    free(listaAlunos);
    free(aluno1);

    return 0;
}