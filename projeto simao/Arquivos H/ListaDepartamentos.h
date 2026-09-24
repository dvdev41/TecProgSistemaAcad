#pragma once
#include <string.h>
#include "ElDepartamento.h"

class Departamento; // declaracao adiantada

class ListaDepartamentos
{
private:
    int cont_dep;
    int numero_dep;
    char nome[150];

    ElDepartamento* pElDepartamentoPrim;
    ElDepartamento* pElDepartamentoAtual;

public:
    ListaDepartamentos(int nd = 50, char* n = "");
    ~ListaDepartamentos();

    void setNome(char* n);
    void incluaDepartamento(Departamento* pd);
    void listeDepartamentos();
    void listeDepartamentos2();
};