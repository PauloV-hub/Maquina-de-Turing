#include <iostream>
#include "Maquina.hpp"
#include <vector>
#include <string>
using namespace std;

// Defini��o da classe Turing
void Turing::setEstado(int a)
{
    estadoAtual = a;
}

int Turing::getEstado()
{
    return estadoAtual;
}

// Fun��o para imprimir a fita excluindo o caractere 'b'
void Turing::Imprimir(vector<char>& entrada)
{
    for (int i = 0; i < entrada.size(); i++)
    {
        if (entrada[i] != 'b')
        {
            cout << entrada[i];
        }
    }
    cout << endl;
}

// Fun��o principal para processar a entrada na m�quina de Turing
int Turing::test(vector<char>& entrada, int tamanho, char *ponteiro)
{
    // Itera sobre as transi��es da m�quina
    for (int i = 0; i < lista_transicao.size(); i++)
    {
        // Verifica se a transi��o � aplic�vel ao estado atual e s�mbolo na fita
        if (lista_transicao[i]->getLocal() == estadoAtual && lista_transicao[i]->getEntrada() == *ponteiro)
        {
            // Calcula o deslocamento na fita
            std::vector<char>::size_type deslocamento = ponteiro - &entrada[0];

            // Atualiza o s�mbolo na fita com o s�mbolo de substitui��o
            entrada[deslocamento] = lista_transicao[i]->getSubstituir();

            // Move o ponteiro para a direita ou esquerda conforme especificado na transi��o
            if (lista_transicao[i]->getDirecao() == 'R')
            {
                ponteiro++;
            }
            else
            {
                ponteiro--;
            }

            // Atualiza o estado atual com o destino da transi��o
            estadoAtual = lista_transicao[i]->getDestino();

            // Realiza uma chamada recursiva para processar o pr�ximo passo na m�quina
            test(entrada, tamanho,  ponteiro);

            // Verifica se a m�quina � determin�stica
            if (deterministica == 0)
            {
                // Se n�o for determin�stica, retorna o resultado da aceita��o
                return aceitar(estadoAtual);
            }
        }
    }

    // Se a m�quina for determin�stica, retorna o resultado da aceita��o
    if (deterministica == 1)
        return aceitar(estadoAtual);

    // Se n�o for aceito em nenhum estado, retorna 0
    return 0;
}

// Fun��o para verificar se um estado � final
int Turing::aceitar(int est)
{
    for (int i = 0; i < estadoFinal.size(); i++)
    {
        if (estadoFinal[i]->getDestino() == est)
        {
            return 1; // Retorna 1 se o estado � final
        }
    }
    return 0; // Retorna 0 se o estado n�o � final
}
