#ifndef MAQUINA_H_INCLUDED
#define MAQUINA_H_INCLUDED
#include <vector>
#include <string>
#include "transicao.hpp"
using namespace std;

class Turing
{
private:
    int T;
    int N;
    int estadoAtual;
    int deterministica;
    vector<Transicao*> estadoFinal;
    vector<Transicao*>lista_transicao;
public:
    Turing(int estados, int transicao,vector<Transicao*>&Tra,int e,vector<Transicao*>&f,int D) : T(transicao), N(estados),lista_transicao(Tra),estadoAtual(e),estadoFinal(f),deterministica(D){}
    int test(vector<char> &ent, int tamanho,char*ponteiro);
    int test2(vector<char> &ent, int tamanho,char*ponteiro);
    int aceitar(int transicao);
    int getEstado();
    void setEstado(int a);
    void Imprimir(vector<char>&entrada);
};

#endif // MAQUINA_H_INCLUDED
