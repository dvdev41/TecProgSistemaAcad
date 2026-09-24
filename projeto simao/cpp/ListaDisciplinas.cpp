#include "ListaDisciplinas.h"
#include <iostream>

using namespace std;


class Aluno;
class ElAluno;
ListaDisciplinas::ListaDisciplinas(int nd, char* n)
{
    numero_disc = nd; // -1 = sem limite (usado pelo Departamento)
    cont_disc = 0;
    pElDisciplinaPrim = nullptr;
    pElDisciplinaAtual = nullptr;
    strcpy_s(nome, n);
}

ListaDisciplinas::~ListaDisciplinas()
{
    ElDisciplina* paux1;
    ElDisciplina* paux2;

    paux1 = pElDisciplinaPrim;

    while (paux1 != nullptr)
    {
        paux2 = paux1->pProx;
        delete paux1;
        paux1 = paux2;
    }

    pElDisciplinaPrim = nullptr;
    pElDisciplinaAtual = nullptr;
}

void ListaDisciplinas::setNome(char* n)
{
    strcpy_s(nome, n);
}

void ListaDisciplinas::incluaDisciplina(Disciplina* pdi)
{
    if (pdi == nullptr)
    {
        cout << "Ponteiro da disciplina esta nulo!" << endl;
        return;
    }

    if (numero_disc != -1 && cont_disc >= numero_disc)
    {
        cout << "Disciplina nao incluida. Quantidade ja lotada em " << numero_disc << " disciplinas." << endl;
        return;
    }

    ElDisciplina* paux = new ElDisciplina();
    paux->setDisciplina(pdi);

    if (pElDisciplinaPrim == nullptr)
    {
        pElDisciplinaPrim = paux;
        pElDisciplinaAtual = paux;
    }
    else
    {
        pElDisciplinaAtual->pProx = paux;
        paux->pAnte = pElDisciplinaAtual;
        pElDisciplinaAtual = paux;
    }

    cont_disc++;
}

void ListaDisciplinas::listeDisciplinas()
{
    ElDisciplina* paux = pElDisciplinaPrim;
    while (paux != nullptr)
    {
        cout << "  Disciplina " << paux->getNome() << " pertence ao Departamento " << nome << endl;
        paux = paux->pProx;
    }
}

void ListaDisciplinas::listeDisciplinas2()
{
    ElDisciplina* paux = pElDisciplinaAtual;
    while (paux != nullptr)
    {
        cout << "  Disciplina " << paux->getNome() << " pertence ao Departamento " << nome << endl;
        paux = paux->pAnte;
    }
}
void ListaAlunos::graveAlunosBinario()
{
    ofstream arquivo("alunos.bin", ios::binary | ios::out);

    if (!arquivo)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    ElAluno* paux = pElAlunoPrim;
    while (paux != nullptr)
    {
        Aluno* pa = paux->getAluno();

        int id = pa->getId();
        int ra = pa->getRA();
        char nomeBuf[30];
        strcpy_s(nomeBuf, pa->getNome());

        arquivo.write((char*)&id, sizeof(id));
        arquivo.write((char*)&ra, sizeof(ra));
        arquivo.write((char*)nomeBuf, sizeof(nomeBuf));

        paux = paux->pProx;
    }

    arquivo.close();
}

void ListaAlunos::recupereAlunosBinario()
{
    ifstream arquivo("alunos.bin", ios::binary | ios::in);

    if (!arquivo)
    {
        cerr << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    limpaLista();

    int id, ra;
    char nomeBuf[30];

    while (arquivo.read((char*)&id, sizeof(id)))
    {
        arquivo.read((char*)&ra, sizeof(ra));
        arquivo.read((char*)nomeBuf, sizeof(nomeBuf));

        Aluno* pa = new Aluno(id);
        pa->setRA(ra);
        pa->setNome(nomeBuf);
        incluaAluno(pa);
    }

    arquivo.close();
}
