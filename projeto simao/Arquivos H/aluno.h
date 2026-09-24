// Aluno.h
#pragma once
#include "Pessoa.h"

class Aluno : public Pessoa
{
private:
    int RA;

public:
    Aluno(int i = -1);
    ~Aluno();

    void setRA(int ra);
    int getRA();
};