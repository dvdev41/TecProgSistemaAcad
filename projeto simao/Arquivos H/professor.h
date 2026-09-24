// Professor.h
#pragma once
#include "Pessoa.h"
#include "Universidade.h"
#include "Departamento.h"

class Professor : public Pessoa
{
private:
    Universidade* pUnivFiliado;
    Departamento* pDptoFiliado;

public:
    Professor(int i = -1);
    
    ~Professor();

    void setUnivFiliado(Universidade* pu);
    void setDepartamento(Departamento* pdpto);
    void OndeTrabalho();
    void QualDepartamentoTrabalho();
};