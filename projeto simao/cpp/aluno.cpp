// Aluno.cpp
#include "Aluno.h"

Aluno::Aluno(int i) : Pessoa(i)
{
    RA = 0;
}

Aluno::~Aluno()
{
}

void Aluno::setRA(int ra)
{
    RA = ra;
}

int Aluno::getRA()
{
    return RA;
}