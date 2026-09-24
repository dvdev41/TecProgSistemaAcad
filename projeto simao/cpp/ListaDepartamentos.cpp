#include "ListaDepartamentos.h"
#include <iostream>
using namespace std;

ListaDepartamentos::ListaDepartamentos(int nd, char* n)
{
    numero_dep = nd;
    cont_dep = 0;
    pElDepartamentoPrim = nullptr;
    pElDepartamentoAtual = nullptr;
    strcpy_s(nome, n);
}

ListaDepartamentos::~ListaDepartamentos()
{
    ElDepartamento* paux1;
    ElDepartamento* paux2;

    paux1 = pElDepartamentoPrim;

    while (paux1 != nullptr)
    {
        paux2 = paux1->pProx;
        delete paux1;
        paux1 = paux2;
    }

    pElDepartamentoPrim = nullptr;
    pElDepartamentoAtual = nullptr;
}

void ListaDepartamentos::setNome(char* n)
{
    strcpy_s(nome, n);
}

void ListaDepartamentos::incluaDepartamento(Departamento* pd)
{
    if (pd == nullptr)
    {
        cout << "Ponteiro do departamento esta nulo!" << endl;
        return;
    }

    if (cont_dep >= numero_dep)
    {
        cout << "Departamento nao incluido. Quantidade ja lotada em " << numero_dep << " departamentos." << endl;
        return;
    }

    ElDepartamento* paux = new ElDepartamento();
    paux->setDepartamento(pd);

    if (pElDepartamentoPrim == nullptr)
    {
        pElDepartamentoPrim = paux;
        pElDepartamentoAtual = paux;
    }
    else
    {
        pElDepartamentoAtual->pProx = paux;
        paux->pAnte = pElDepartamentoAtual;
        pElDepartamentoAtual = paux;
    }

    cont_dep++;
}

void ListaDepartamentos::listeDepartamentos()
{
    ElDepartamento* paux = pElDepartamentoPrim;
    while (paux != nullptr)
    {
        cout << "  Departamento " << paux->getNome() << " pertence a Universidade " << nome << endl;
        paux = paux->pProx;
    }
}

void ListaDepartamentos::listeDepartamentos2()
{
    ElDepartamento* paux = pElDepartamentoAtual;
    while (paux != nullptr)
    {
        cout << "  Departamento " << paux->getNome() << " pertence a Universidade " << nome << endl;
        paux = paux->pAnte;
    }
}