#pragma once

class Departamento; // declaracao adiantada

class ElDepartamento
{
private:
    Departamento* pDepartamento;

public:
    ElDepartamento();
    ~ElDepartamento();

    ElDepartamento* pProx;
    ElDepartamento* pAnte;

    void setDepartamento(Departamento* pd);
    Departamento* getDepartamento();
    char* getNome();
};