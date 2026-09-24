#pragma once
#include <string.h>

class Pessoa
{
protected:
    int diaP;
    int mesP;
    int anoP;
    int idadeP;
    char nomeP[30];
    int id;

public:
    Pessoa(int diaNa, int mesNa, int anoNa, char* nome = "");
    Pessoa();
    Pessoa(int i = -1);
    ~Pessoa() {}

    void Inicializa(int diaNa, int mesNa, int anoNa, char* nome = "");
    void Calc_Idade(int diaAT, int mesAT, int anoAT);
    int informaIdade();

    void setId(int i) { id = i; }
    int getId() { return id; }
    void setNome(char* n) { strcpy_s(nomeP, n); }
    char* getNome() { return nomeP; }
};