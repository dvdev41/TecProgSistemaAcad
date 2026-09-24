#include "ElDisciplina.h"
#include "Disciplina.h"

ElDisciplina::ElDisciplina()
{
    pDisciplina = nullptr;
    pProx = nullptr;
    pAnte = nullptr;
}

ElDisciplina::~ElDisciplina()
{
    pDisciplina = nullptr;
    pProx = nullptr;
    pAnte = nullptr;
}

void ElDisciplina::setDisciplina(Disciplina* pd)
{
    pDisciplina = pd;
}

Disciplina* ElDisciplina::getDisciplina()
{
    return pDisciplina;
}

char* ElDisciplina::getNome()
{
    return pDisciplina->getNome();
}