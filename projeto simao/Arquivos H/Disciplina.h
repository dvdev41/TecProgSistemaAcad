// Disciplina.h
#pragma once
#include <string.h>
#include "ListaAlunos.h"

class Departamento; // declaracao adiantada
class Aluno;

class Disciplina
{
private:
    int id;
    char nome[150];
    char area_conhecimento[150];
    Departamento* pDeptoAssociado;
    ListaAlunos ObjLAlunos; // composicao: cada disciplina TEM sua lista de alunos

public:
    Disciplina(int i = -1, int na = 45, char* ac = "");
    ~Disciplina();

    void setId(int i);
    int getId();
    void setNome(char* n);
    char* getNome();

    void setDepartamento(Departamento* pd);
    Departamento* getDepartamento();

    void incluaAluno(Aluno* pa);
    void listeAlunos();
    void listeAlunos2();
};