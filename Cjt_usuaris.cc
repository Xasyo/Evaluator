#include "Cjt_usuaris.hh"
using namespace std;

Cjt_usuaris::Cjt_usuaris(){
    map<string, Usuari> a;
    conjunt = a;
}

Cjt_usuaris::~Cjt_usuaris(){}

void Cjt_usuaris::afegir_usuari(Usuari aux){
    pair<string, Usuari> aux2;
    aux2.first = aux.consultar_identificador();
    aux2.second = aux;
    conjunt.insert(aux2);
}

void Cjt_usuaris::esborrar_usuari(string s){
    map<string, Usuari>::iterator it = conjunt.find(s);
    conjunt.erase(it);
}

void Cjt_usuaris::modificar_usuari(Usuari aux){
    map<string,Usuari>::iterator it = conjunt.find(aux.consultar_identificador());
    it->second = aux;
}

bool Cjt_usuaris::esta(string s) const{
    map<string, Usuari>::const_iterator it = conjunt.find(s);
    if (it == conjunt.end()) return false;
    else return true;
}

Usuari Cjt_usuaris::consultar_identificador(string s) const{
    map<string, Usuari>::const_iterator it = conjunt.find(s);
    return it->second;
}

int Cjt_usuaris::nombre_usuaris()const{
    return conjunt.size();
}

void Cjt_usuaris::llistar_usuaris() const{
    map<string, Usuari>::const_iterator it = conjunt.begin();
    while (it != conjunt.end()){
        it->second.escriure();
        ++it;
    }
}

void Cjt_usuaris::enviament(string u, string s, int r){
    map<string, Usuari>::iterator it = conjunt.find(u);
    it->second.enviament(s, r);
}

void Cjt_usuaris::inscriure(string u, int n){
    map<string, Usuari>::iterator it = conjunt.find(u);
    it->second.inscriure(n);
}

void Cjt_usuaris::afegir_problema(string u, string s){
    map<string, Usuari>::iterator it = conjunt.find(u);
    it->second.afegir_problema(s);
}

void Cjt_usuaris::fer_disponible(string u, string s){
    map<string, Usuari>::iterator it = conjunt.find(u);
    it->second.fer_disponible(s);
}

void Cjt_usuaris::incrementar_vegades_intentat(string u, string s){
    map<string, Usuari>::iterator it = conjunt.find(u);
    it->second.incrementar_vegades_intentat(s);
}

bool Cjt_usuaris::inscrit(string u)const{
    map<string, Usuari>::const_iterator it = conjunt.find(u);
    return it->second.inscrit();
}

int Cjt_usuaris::cursant(string u)const{
    map<string, Usuari>::const_iterator it = conjunt.find(u);
    return it->second.cursant();
}

bool Cjt_usuaris::disponible(string u, string s)const{
    map<string, Usuari>::const_iterator it = conjunt.find(u);
    return it->second.disponible(s);
}

bool Cjt_usuaris::resolt(string u, string s)const{
    map<string, Usuari>::const_iterator it = conjunt.find(u);
    return it->second.resolt(s);
}

bool Cjt_usuaris::intentat(string u, string s)const{
    map<string, Usuari>::const_iterator it = conjunt.find(u);
    return it->second.intentat(s);
}

bool Cjt_usuaris::esta_problema(string u, string s)const{
    map<string, Usuari>::const_iterator it = conjunt.find(u);
    return it->second.esta(s);
}

int Cjt_usuaris::enviaments(string u)const{
    map<string, Usuari>::const_iterator it = conjunt.find(u);
    return it->second.enviaments();
}

int Cjt_usuaris::disponibles(string u)const{
    map<string, Usuari>::const_iterator it = conjunt.find(u);
    return it->second.disponibles();
}

int Cjt_usuaris::resolts(string u)const{
    map<string, Usuari>::const_iterator it = conjunt.find(u);
    return it->second.resolts();
}

void Cjt_usuaris::escriure(string u)const{
    map<string, Usuari>::const_iterator it = conjunt.find(u);
    it->second.escriure();
}

void Cjt_usuaris::escriure_disponibles(string u)const{
    map<string, Usuari>::const_iterator it = conjunt.find(u);
    it->second.escriure_disponibles();
}

void Cjt_usuaris::escriure_resolts(string u)const{
    map<string, Usuari>::const_iterator it = conjunt.find(u);
    it->second.escriure_resolts();
}

void Cjt_usuaris::disponibilitzar(string u, const BinTree<string>& a){
    map<string, Usuari>::iterator it = conjunt.find(u);
    it->second.disponibilitzar(a);
}
