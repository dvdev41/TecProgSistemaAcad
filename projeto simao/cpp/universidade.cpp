// Universidade.cpp
#include "Universidade.h"

Universidade::Universidade() : ObjLDepartamentos(50, "")
{
    strcpy_s(nome, "");
}

Universidade::~Universidade()
{
}

void Universidade::setNome(char* n)
{
    strcpy_s(nome, n);
    ObjLDepartamentos.setNome(n);
}

char* Universidade::getNome()
{
    return nome;
}

void Universidade::incluaDepartamento(Departamento* pd)
{
    ObjLDepartamentos.incluaDepartamento(pd);
}

void Universidade::listeDepartamentos()
{
    ObjLDepartamentos.listeDepartamentos();
}

void Universidade::listeDepartamentos2()
{
    ObjLDepartamentos.listeDepartamentos2();
}
