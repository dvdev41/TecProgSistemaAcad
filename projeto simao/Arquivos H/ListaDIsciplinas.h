#pragma once
#include <string.h>
#include "ElDisciplina.h"

class Disciplina; // declaracao adiantada - EVITA O INCLUDE RECURSIVO do slide original

class ListaDisciplinas
{
private:
    int cont_disc;
    int numero_disc;
    char nome[150];

    ElDisciplina* pElDisciplinaPrim;
    ElDisciplina* pElDisciplinaAtual;

public:
    ListaDisciplinas(int nd = 1000, char* n = "");
    ~ListaDisciplinas();

    void setNome(char* n);
    void incluaDisciplina(Disciplina* pdi);
    void listeDisciplinas();
    void listeDisciplinas2();
};