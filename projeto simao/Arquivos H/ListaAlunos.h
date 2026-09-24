#pragma once
#include <string.h>
#include "ElAluno.h"

class Aluno; // declaracao adiantada

// Classe reaproveitavel: qualquer coisa que precise manter uma lista
// duplamente encadeada de Alunos pode ter um objeto ListaAlunos dentro de si.
class ListaAlunos
{
private:
    int cont_alunos;
    int numero_alunos;
    char nome[150];

    ElAluno* pElAlunoPrim;
    ElAluno* pElAlunoAtual;

public:
    ListaAlunos(int na = 45, char* n = "");
    ~ListaAlunos();

    void setNome(char* n);
    void incluaAluno(Aluno* pa);
    void listeAlunos();
    void listeAlunos2();
    void limpaLista();
    void graveAlunos();
    void recupereAlunos();
    void graveAlunosBinario();
    void recupereAlunosBinario();
};