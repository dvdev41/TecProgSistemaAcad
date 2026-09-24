#include "ElAluno.h"
#include "Aluno.h"

ElAluno::ElAluno()
{
    pAluno = nullptr;
    pProx = nullptr;
    pAnte = nullptr;
}

ElAluno::~ElAluno()
{
    // Nao apagamos o Aluno aqui: o "no" nao e dono do aluno, so aponta para ele.
    pAluno = nullptr;
    pProx = nullptr;
    pAnte = nullptr;
}

void ElAluno::setAluno(Aluno* pa)
{
    pAluno = pa;
}

Aluno* ElAluno::getAluno()
{
    return pAluno;
}

char* ElAluno::getNome()
{
    return pAluno->getNome();
}