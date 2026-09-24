// Departamento.cpp
#include "Departamento.h"
#include "Universidade.h"
#include "ListaDisciplinas.h"
//asdasdasdasd
Departamento::Departamento(int i)
{
    id = i;
    strcpy_s(nome, "");
    pUniv = nullptr;
    pObjLDisciplinas = new ListaDisciplinas(-1, ""); // -1 = sem limite de disciplinas
}

Departamento::~Departamento()
{
    if (pObjLDisciplinas != nullptr)
    {
        delete pObjLDisciplinas;
        pObjLDisciplinas = nullptr;
    }
    pUniv = nullptr;
}

int Departamento::getId()
{
    return id;
}

void Departamento::setId(int i)
{
    id = i;
}

void Departamento::setNome(char* n)
{
    strcpy_s(nome, n);
    pObjLDisciplinas->setNome(n);
}

char* Departamento::getNome()
{
    return nome;
}

void Departamento::setUniversidade(Universidade* pu)
{
    pUniv = pu;
    pu->incluaDepartamento(this); // this: o departamento se registra sozinho na universidade
}

Universidade* Departamento::getUniversidade()
{
    return pUniv;
}

void Departamento::incluaDisciplina(Disciplina* pdi)
{
    pObjLDisciplinas->incluaDisciplina(pdi);
}

void Departamento::listeDisciplinas()
{
    pObjLDisciplinas->listeDisciplinas();
}

void Departamento::listeDisciplinas2()
{
    pObjLDisciplinas->listeDisciplinas2();
}