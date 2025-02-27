#ifndef TRANSICAO_H_INCLUDED
#define TRANSICAO_H_INCLUDED
#include <string>
using namespace std;
class Transicao{
protected:
    int local;
    string transition;
    int destino;
public:
    Transicao(int l,string s, int d):local(l),transition(s),destino(d){}
    int getLocal();
    int getDestino();
    char getEntrada();
    char getSubstituir();
    char getDirecao();
    string getTransicao();


};


#endif // TRANSICAO_H_INCLUDED
