#include "Pessoa.h"

Pessoa::Pessoa(int diaNa, int mesNa, int anoNa, char* nome)
{
    Inicializa(diaNa, mesNa, anoNa, nome);
}
Pessoa::Pessoa(int i)
{
    id = i;
    diaP = 0; mesP = 0; anoP = 0; idadeP = 0;
    strcpy_s(nomeP, "");
}
Pessoa::Pessoa()
{
    Inicializa(0, 0, 0);
}

void Pessoa::Inicializa(int diaNa, int mesNa, int anoNa, char* nome)
{
    diaP = diaNa;
    mesP = mesNa;
    anoP = anoNa;
    idadeP = 0;
    id = -1;
    strcpy_s(nomeP, nome);
}

void Pessoa::Calc_Idade(int diaAT, int mesAT, int anoAT)
{
    idadeP = anoAT - anoP;

    if (mesP > mesAT)
    {
        idadeP = idadeP - 1;
    }
    else
    {
        if (mesP == mesAT)
        {
            if (diaP > diaAT)
            {
                idadeP = idadeP - 1;
            }
        }
    }
}

int Pessoa::informaIdade()
{
    return idadeP;
}