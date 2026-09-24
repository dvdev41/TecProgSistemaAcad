// Universidade.h
#pragma once
#include <string.h>
#include "ListaDepartamentos.h"

class Departamento; // declaracao adiantada

class Universidade
{
private:
    char nome[130];
    ListaDepartamentos ObjLDepartamentos; // composicao

public:
    Universidade();
    ~Universidade();

    void setNome(char* n);
    char* getNome();

    void incluaDepartamento(Departamento* pd);
    void listeDepartamentos();
    void listeDepartamentos2();
};