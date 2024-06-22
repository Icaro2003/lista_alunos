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
    
    int tamanhoListaAlunos = 4;

    Aluno *aluno1 = criaAluno(matricula1, nota1);
    Aluno *aluno2 = criaAluno(matricula2, nota2);
    Aluno *aluno3 = criaAluno(matricula3, nota3);
    Aluno *aluno4 = criaAluno(matricula4, nota4);
    Lista *listaAlunos = criaListaAlunos(tamanhoListaAlunos);
    int encheu = listaCheia(listaAlunos);
    int vazio = listaVazia(listaAlunos);

    insereAlunoInicio(listaAlunos, aluno1);
    insereAlunoFinal(listaAlunos, aluno2);
    insereAlunoFinal(listaAlunos, aluno3);
    insereAlunoFinal(listaAlunos, aluno4);

    imprimeAlunos(listaAlunos);

    liberaLista(listaAlunos);
    liberaAluno(aluno1);

    return 0;
}