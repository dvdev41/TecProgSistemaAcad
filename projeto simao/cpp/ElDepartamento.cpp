#include "ElDepartamento.h"
#include "Departamento.h"

ElDepartamento::ElDepartamento()
{
    pDepartamento = nullptr;
    pProx = nullptr;
    pAnte = nullptr;
}

ElDepartamento::~ElDepartamento()
{
    pDepartamento = nullptr;
    pProx = nullptr;
    pAnte = nullptr;
}

void ElDepartamento::setDepartamento(Departamento* pd)
{
    pDepartamento = pd;
}

Departamento* ElDepartamento::getDepartamento()
{
    return pDepartamento;
}

char* ElDepartamento::getNome()
{
    return pDepartamento->getNome();
}