// Departamento.h
#pragma once
#include <string.h>

class Universidade;      // declaracao adiantada
class ListaDisciplinas;  // declaracao adiantada
class Disciplina;

class Departamento
{
private:
    int id;
    char nome[100];
    Universidade* pUniv;
    ListaDisciplinas* pObjLDisciplinas; // alocado dinamicamente (new) no construtor

public:
    Departamento(int i = -1);
    ~Departamento();

    int getId();
    void setId(int i);
    void setNome(char* n);
    char* getNome();

    void setUniversidade(Universidade* pu);
    Universidade* getUniversidade();

    void incluaDisciplina(Disciplina* pdi);
    void listeDisciplinas();
    void listeDisciplinas2();
};