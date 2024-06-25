#include <stdio.h>
#include <stdlib.h>
#include "lista_alunos.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int matricula1 = 552838;
    float nota1 = 10;
    int matricula2 = 12345;
    float nota2 = 8;
    int matricula3 = 6789;
    float nota3 = 7;
    int matricula4 = 131561;
    float nota4 = 6;
    int matricula5 = 125646;
    float nota5 = 7.5;
    
    int tamanhoListaAlunos = 4;

    Aluno *aluno1 = criaAluno(matricula1, nota1);
    Aluno *aluno2 = criaAluno(matricula2, nota2);
    Aluno *aluno3 = criaAluno(matricula3, nota3);
    Aluno *aluno4 = criaAluno(matricula4, nota4);
    Aluno *aluno5 = criaAluno(matricula5, nota5);
    Lista *listaAlunos = criaListaAlunos(tamanhoListaAlunos);
    int vazio = listaVazia(listaAlunos);

    insereAlunoInicio(listaAlunos, aluno1);
    insereAlunoFinal(listaAlunos, aluno2);
    insereAlunoFinal(listaAlunos, aluno3);
    insereAlunoFinal(listaAlunos, aluno4);

    // insereAlunoFinal(listaAlunos, aluno5);

    // removeAlunoInicio(listaAlunos);
    // removeAlunoFinal(listaAlunos);

    // modificaAluno(listaAlunos, 0, aluno1);

    // removeAluno(listaAlunos, aluno1);

    imprimeAlunos(listaAlunos);

    printf("Posição da matrícula: %d\n", buscaPorMatricula(listaAlunos, matricula4));

    // apagaLista(listaAlunos);
    // imprimeAlunos(listaAlunos);

    // printf("Maior nota: %.2f\n", maiorNota(listaAlunos));
    // printf("Menor nota: %.2f\n", menorNota(listaAlunos));
    // printf("Média: %.2f\n", mediaNotas(listaAlunos));

    liberaLista(listaAlunos);
    liberaAluno(aluno1);

    return 0;
}