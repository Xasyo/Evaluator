#include "Cjt_problemes.hh"
using namespace std;

Cjt_problemes::Cjt_problemes(){
    map<string, Problema> aux; 
    problemes = aux;
}

Cjt_problemes::~Cjt_problemes(){}

Problema Cjt_problemes::consultar_problema(string s){
    map<string, Problema>::iterator it = problemes.find(s);
    return it->second;
}

bool Cjt_problemes::esta(string s) const{
    map<string, Problema>::const_iterator it = problemes.find(s);
    if (it == problemes.end()){
        return false;
    }
    else return true;
}

int Cjt_problemes::nombre_problemes() const{
    return problemes.size();
}

void Cjt_problemes::insertar_problema(Problema p){
    pair<string, Problema> aux;
    aux.first = p.consultar_identificador();
    aux.second = p;
    problemes.insert(aux);
    
}

void Cjt_problemes::modificar_problema(Problema p){
    map<string, Problema>::iterator it = problemes.find(p.consultar_identificador());
    it->second = p;
}

void Cjt_problemes::llistar_problemes()const{
    vector<Problema> prob;
    map<string, Problema>::const_iterator it = problemes.begin();
    while (it != problemes.end()){
        prob.push_back(it->second);
        ++it;
    }
    sort(prob.begin(), prob.end(), comparacio_problemes);
    int a = prob.size();
    for (int i = 0; i < a; ++i){
        prob[i].escriure();
    }
    
}

bool Cjt_problemes::comparacio_problemes(Problema p1, Problema p2){
    if (p1.consultar_ratio() == p2.consultar_ratio()){
        return p1.consultar_identificador() < p2.consultar_identificador();
    }
    else return p1.consultar_ratio() < p2.consultar_ratio();
}

string Cjt_problemes::consultar_identificador(string p)const{
    map<string, Problema>::const_iterator it = problemes.find(p);
    return it->second.consultar_identificador();
}
    

int Cjt_problemes::consultar_enviaments_totals(string p)const{
    map<string, Problema>::const_iterator it = problemes.find(p);
    return it->second.consultar_enviaments_totals();
}


int Cjt_problemes::consultar_enviments_correctes(string p)const{
    map<string, Problema>::const_iterator it = problemes.find(p);
    return it->second.consultar_enviaments_correctes();
}

double Cjt_problemes::consultar_ratio(string p)const{
    map<string, Problema>::const_iterator it = problemes.find(p);
    return it->second.consultar_ratio();
}

void Cjt_problemes::enviament_incorrecte(string p){
    map<string, Problema>::iterator it = problemes.find(p);
    it->second.enviament_incorrecte();
}

void Cjt_problemes::enviament_correcte(string p){
    map<string, Problema>::iterator it = problemes.find(p);
    it->second.enviament_correcte();
}

void Cjt_problemes::escriure_problema(string p)const{
    map<string, Problema>::const_iterator it = problemes.find(p);
    it->second.escriure();
}




















