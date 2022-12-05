#include "Problema.hh"
using namespace std;

Problema::Problema(){
    string a;
    identificador = a;
    t = 0;
    e = 0;
    ratio = 1;
}

Problema::Problema(string s){
    identificador = s;
    t = 0;
    e = 0;
    ratio = 1;
}

Problema::~Problema(){}

void Problema::afegir_identificador(string s){
    identificador = s;
}

void Problema::enviament_incorrecte(){
    ++t;
    ratio = (double(t)+1)/(double(e)+1);
}

void Problema::enviament_correcte(){
    ++t;
    ++e;
    ratio = (double(t)+1)/(double(e)+1);
}

string Problema::consultar_identificador()const{
    return identificador;
}

int Problema::consultar_enviaments_totals() const{
    return t;
}

int Problema::consultar_enviaments_correctes() const{
    return e;
}

double Problema::consultar_ratio() const{
    return ratio;
}

void Problema::escriure() const{
    cout << identificador << "(" << t << "," << e << "," << ratio << ")"<< endl;
}



