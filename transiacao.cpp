#include "transicao.hpp"
using namespace std;
int Transicao::getDestino()
{
    return destino;
}
int Transicao::getLocal()
{
    return local;
}
char Transicao::getEntrada()
{
    return transition[0];

}
char Transicao::getSubstituir()
{
    return transition[2];
}
char Transicao::getDirecao()
{
    return transition[4];
}
string Transicao::getTransicao()
{
    return transition;
}
