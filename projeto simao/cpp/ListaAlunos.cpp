#include "ListaAlunos.h"
#include <iostream>
#include <cstring>
using namespace std;

ListaAlunos::ListaAlunos(int na, char* n)
{
    numero_alunos = na;
    cont_alunos = 0;
    pElAlunoPrim = nullptr;
    pElAlunoAtual = nullptr;
    strcpy_s(nome, n);
}

ListaAlunos::~ListaAlunos()
{
    ElAluno* paux1;
    ElAluno* paux2;

    paux1 = pElAlunoPrim;

    while (paux1 != nullptr)
    {
        paux2 = paux1->pProx;
        delete paux1; // libera o "no" (ElAluno), NAO o Aluno em si
        paux1 = paux2;
    }

    pElAlunoPrim = nullptr;
    pElAlunoAtual = nullptr;
}

void ListaAlunos::setNome(char* n)
{
    strcpy_s(nome, n);
}

void ListaAlunos::incluaAluno(Aluno* pa)
{
    if (pa == nullptr)
    {
        cout << "Ponteiro do aluno esta nulo!" << endl;
        return;
    }

    if (cont_alunos >= numero_alunos)
    {
        cout << "Aluno nao incluido. Turma ja lotada em " << numero_alunos << " alunos." << endl;
        return;
    }

    ElAluno* paux = new ElAluno(); // alocacao dinamica: um "no" novo a cada matricula
    paux->setAluno(pa);

    if (pElAlunoPrim == nullptr)
    {
        pElAlunoPrim = paux;
        pElAlunoAtual = paux;
    }
    else
    {
        pElAlunoAtual->pProx = paux;
        paux->pAnte = pElAlunoAtual;
        pElAlunoAtual = paux;
    }

    cont_alunos++;
}

void ListaAlunos::listeAlunos()
{
    ElAluno* paux = pElAlunoPrim;
    while (paux != nullptr)
    {
        cout << "  Aluno " << paux->getNome() << " matriculado em " << nome << endl;
        paux = paux->pProx;
    }
}

void ListaAlunos::listeAlunos2()
{
    ElAluno* paux = pElAlunoAtual;
    while (paux != nullptr)
    {
        cout << "  Aluno " << paux->getNome() << " matriculado em " << nome << endl;
        paux = paux->pAnte;
    }
}