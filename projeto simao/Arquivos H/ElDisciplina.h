#pragma once

class Disciplina; // declaracao adiantada

class ElDisciplina
{
private:
    Disciplina* pDisciplina;

public:
    ElDisciplina();
    ~ElDisciplina();

    ElDisciplina* pProx;
    ElDisciplina* pAnte;

    void setDisciplina(Disciplina* pd);
    Disciplina* getDisciplina();
    char* getNome();
};