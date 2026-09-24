// Disciplina.cpp
#include "Disciplina.h"
#include "Departamento.h"

// Disciplina.cpp
Disciplina::Disciplina(int i, int na, char* ac) : ObjLAlunos(na, "")
{
    id = i;
    pDeptoAssociado = nullptr;
    strcpy_s(area_conhecimento, ac);
}


Disciplina::~Disciplina()
{
    pDeptoAssociado = nullptr;
}

void Disciplina::setId(int i)
{
    id = i;
}

int Disciplina::getId()
{
    return id;
}

void Disciplina::setNome(char* n)
{
    strcpy_s(nome, n);
    ObjLAlunos.setNome(n); // mantem sincronizado o nome usado nas mensagens da lista
}

char* Disciplina::getNome()
{
    return nome;
}

void Disciplina::setDepartamento(Departamento* pd)
{
    pDeptoAssociado = pd;
    pd->incluaDisciplina(this); // this: a disciplina se registra sozinha no departamento
}

Departamento* Disciplina::getDepartamento()
{
    return pDeptoAssociado;
}

void Disciplina::incluaAluno(Aluno* pa)
{
    ObjLAlunos.incluaAluno(pa);
}

void Disciplina::listeAlunos()
{
    ObjLAlunos.listeAlunos();
}

void Disciplina::listeAlunos2()
{
    ObjLAlunos.listeAlunos2();
}