// Professor.cpp
#include "Professor.h"
#include <iostream>
using namespace std;

Professor::Professor(int diaNa, int mesNa, int anoNa, char* nome) : Pessoa(diaNa, mesNa, anoNa, nome)
{
    pUnivFiliado = nullptr;
    pDptoFiliado = nullptr;
}
Professor::Professor(int i) : Pessoa(i)
{
    pUnivFiliado = nullptr;
    pDptoFiliado = nullptr;
}

Professor::~Professor()
{
    pUnivFiliado = nullptr;
    pDptoFiliado = nullptr;
}

void Professor::setUnivFiliado(Universidade* pu)
{
    pUnivFiliado = pu;
}

void Professor::setDepartamento(Departamento* pdpto)
{
    pDptoFiliado = pdpto;
}

void Professor::OndeTrabalho()
{
    if (pUnivFiliado != nullptr)
    {
        cout << nomeP << " trabalha para a " << pUnivFiliado->getNome() << endl;
    }
}

void Professor::QualDepartamentoTrabalho()
{
    if (pUnivFiliado != nullptr && pDptoFiliado != nullptr)
    {
        cout << nomeP << " trabalha para a " << pUnivFiliado->getNome()
             << ", no departamento de " << pDptoFiliado->getNome() << endl;
    }
}