#pragma once

class Aluno; // declaracao adiantada

// ElAluno NAO e o aluno; e um "no" de lista que aponta para o aluno.
// Isso permite que o MESMO Aluno esteja em varias listas (disciplinas)
// ao mesmo tempo, porque cada disciplina usa um ElAluno diferente.
class ElAluno
{
private:
    Aluno* pAluno;

public:
    ElAluno();
    ~ElAluno();

    ElAluno* pProx;
    ElAluno* pAnte;

    void setAluno(Aluno* pa);
    Aluno* getAluno();
    char* getNome();
};