#include <iostream>
#include "Maquina.hpp"
#include <vector>
#include <string>
using namespace std;

// Definição da classe Turing
void Turing::setEstado(int a)
{
    estadoAtual = a;
}

int Turing::getEstado()
{
    return estadoAtual;
}

// Função para imprimir a fita excluindo o caractere 'b'
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

// Função principal para processar a entrada na máquina de Turing
int Turing::test(vector<char>& entrada, int tamanho, char *ponteiro)
{
    // Itera sobre as transições da máquina
    for (int i = 0; i < lista_transicao.size(); i++)
    {
        // Verifica se a transição é aplicável ao estado atual e símbolo na fita
        if (lista_transicao[i]->getLocal() == estadoAtual && lista_transicao[i]->getEntrada() == *ponteiro)
        {
            // Calcula o deslocamento na fita
            std::vector<char>::size_type deslocamento = ponteiro - &entrada[0];

            // Atualiza o símbolo na fita com o símbolo de substituição
            entrada[deslocamento] = lista_transicao[i]->getSubstituir();

            // Move o ponteiro para a direita ou esquerda conforme especificado na transição
            if (lista_transicao[i]->getDirecao() == 'R')
            {
                ponteiro++;
            }
            else
            {
                ponteiro--;
            }

            // Atualiza o estado atual com o destino da transição
            estadoAtual = lista_transicao[i]->getDestino();

            // Realiza uma chamada recursiva para processar o próximo passo na máquina
            test(entrada, tamanho,  ponteiro);

            // Verifica se a máquina é determinística
            if (deterministica == 0)
            {
                // Se não for determinística, retorna o resultado da aceitação
                return aceitar(estadoAtual);
            }
        }
    }

    // Se a máquina for determinística, retorna o resultado da aceitação
    if (deterministica == 1)
        return aceitar(estadoAtual);

    // Se não for aceito em nenhum estado, retorna 0
    return 0;
}

// Função para verificar se um estado é final
int Turing::aceitar(int est)
{
    for (int i = 0; i < estadoFinal.size(); i++)
    {
        if (estadoFinal[i]->getDestino() == est)
        {
            return 1; // Retorna 1 se o estado é final
        }
    }
    return 0; // Retorna 0 se o estado não é final
}
