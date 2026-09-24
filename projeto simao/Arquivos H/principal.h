// Principal.h
#pragma once
#include "Professor.h"
#include "Aluno.h"
#include "Universidade.h"
#include "Departamento.h"
#include "Disciplina.h"

class Principal
{
private:
    Universidade UTFPR;
    Universidade Princeton;
    Universidade Cambridge;

    Departamento DAELN;
    Departamento FisicaPrinceton;
    Departamento MatematicaCambridge;

    Professor Simao;
    Professor Einstein;
    Professor Newton;

    Disciplina Computacao1;
    Disciplina IntroAlgoritmos;
    Disciplina Metodos2;

    int diaAtual;
    int mesAtual;
    int anoAtual;
     int cont_idAluno;
    int cont_idDisc;
    int cont_idDepart;

    Aluno AAA, BBB, CCC, DDD, EEE;
    ListaAlunos LAlunos;

public:
    Principal();
    void Executar();
    void CadAluno();
    void GravarAlunos();
    void RecuperarAlunos();
    void Menu();
    void MenuCad();
    void MenuExe();
    void MenuGravar();
    void MenuRecuperar();
};