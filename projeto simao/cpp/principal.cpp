// Principal.cpp
#include "Principal.h"
#include <iostream>
#include <time.h>
using namespace std;

Principal::Principal()
{
    // Data atual do sistema
    struct tm local;
    time_t segundos;
    time(&segundos);
    localtime_s(&local, &segundos);

    diaAtual = local.tm_mday;
    mesAtual = local.tm_mon + 1;
    anoAtual = local.tm_year + 1900;

    // Professores
    Simao.Inicializa(3, 10, 1976, "Jean Simao");
    Einstein.Inicializa(14, 3, 1879, "Albert Einstein");
    Newton.Inicializa(4, 1, 1643, "Isaac Newton");

    // Alunos
    AAA.Inicializa(1, 1, 2005, "Ana");
    AAA.setRA(1001);
    BBB.Inicializa(2, 2, 2005, "Bruno");
    BBB.setRA(1002);
    CCC.Inicializa(3, 3, 2005, "Carla");
    CCC.setRA(1003);

    // Universidades
    UTFPR.setNome("UTFPR");
    Princeton.setNome("University of Princeton");
    Cambridge.setNome("University of Cambridge");

    // Departamentos - o "this" implicito ja registra cada um na sua universidade
    DAELN.setNome("Eletronica");
    FisicaPrinceton.setNome("Fisica");
    MatematicaCambridge.setNome("Matematica");

    DAELN.setUniversidade(&UTFPR);
    FisicaPrinceton.setUniversidade(&Princeton);
    MatematicaCambridge.setUniversidade(&Cambridge);

    // Professores: associacao a universidade e departamento
    Simao.setUnivFiliado(&UTFPR);
    Simao.setDepartamento(&DAELN);

    Einstein.setUnivFiliado(&Princeton);
    Einstein.setDepartamento(&FisicaPrinceton);

    Newton.setUnivFiliado(&Cambridge);
    Newton.setDepartamento(&MatematicaCambridge);

    // Disciplinas - o "this" implicito ja registra cada uma no seu departamento
    Computacao1.setNome("Computacao I");
    IntroAlgoritmos.setNome("Introducao a Algoritmos");
    Metodos2.setNome("Metodos II");

    Computacao1.setDepartamento(&DAELN);
    IntroAlgoritmos.setDepartamento(&DAELN);
    Metodos2.setDepartamento(&DAELN);

    // Matriculas: repare que AAA esta em DUAS disciplinas ao mesmo tempo,
    // exatamente o cenario que quebrava a versao com ponteiros embutidos.
    Metodos2.incluaAluno(&AAA);
    Metodos2.incluaAluno(&BBB);
    Computacao1.incluaAluno(&AAA);
    Computacao1.incluaAluno(&CCC);
}

void Principal::Executar()
{
    Simao.Calc_Idade(diaAtual, mesAtual, anoAtual);
    Einstein.Calc_Idade(diaAtual, mesAtual, anoAtual);
    Newton.Calc_Idade(diaAtual, mesAtual, anoAtual);

    cout << "--- Onde cada professor trabalha ---" << endl;
    Simao.OndeTrabalho();
    Einstein.OndeTrabalho();
    Newton.OndeTrabalho();

    cout << endl << "--- Departamentos da UTFPR ---" << endl;
    UTFPR.listeDepartamentos();

    cout << endl << "--- Disciplinas do DAELN ---" << endl;
    DAELN.listeDisciplinas();

    cout << endl << "--- Alunos matriculados em Metodos II ---" << endl;
    Metodos2.listeAlunos();

    cout << endl << "--- Alunos matriculados em Computacao I ---" << endl;
    Computacao1.listeAlunos();
}


void Principal::CadAluno()
{
    char nomeAluno[150];
    int ra;

    cout << "Qual o nome do aluno: ";
    cin >> nomeAluno;

    cout << "Qual o RA do aluno: ";
    cin >> ra;

    Aluno* pal = new Aluno(cont_idAluno++);
    pal->setNome(nomeAluno);
    pal->setRA(ra);

    LAlunos.incluaAluno(pal);
}

void Principal::GravarAlunos()
{
    LAlunos.graveAlunos();
}

void Principal::RecuperarAlunos()
{
    LAlunos.recupereAlunos();
}

void Principal::MenuCad()
{
    int op = -1;
    while (op != 2)
    {
        cout << endl << "1 - Cadastrar Aluno." << endl;
        cout << "2 - Voltar." << endl;
        cin >> op;

        switch (op)
        {
        case 1: CadAluno(); break;
        case 2: break;
        default: cout << "Opcao invalida." << endl;
        }
    }
}

void Principal::MenuExe()
{
    int op = -1;
    while (op != 2)
    {
        cout << endl << "1 - Listar Alunos." << endl;
        cout << "2 - Voltar." << endl;
        cin >> op;

        switch (op)
        {
        case 1: LAlunos.listeAlunos(); break;
        case 2: break;
        default: cout << "Opcao invalida." << endl;
        }
    }
}

void Principal::MenuGravar()
{
    GravarAlunos();
    cout << "Alunos gravados em alunos.dat" << endl;
}

void Principal::MenuRecuperar()
{
    RecuperarAlunos();
    cout << "Alunos recuperados de alunos.dat" << endl;
}

void Principal::Menu()
{
    int op = -1;
    while (op != 5)
    {
        cout << endl << "1 - Cadastrar." << endl;
        cout << "2 - Executar (listar)." << endl;
        cout << "3 - Gravar." << endl;
        cout << "4 - Recuperar." << endl;
        cout << "5 - Sair." << endl;
        cin >> op;

        switch (op)
        {
        case 1: MenuCad(); break;
        case 2: MenuExe(); break;
        case 3: MenuGravar(); break;
        case 4: MenuRecuperar(); break;
        case 5: cout << "FIM" << endl; break;
        default: cout << "Opcao invalida." << endl;
        }
    }
}