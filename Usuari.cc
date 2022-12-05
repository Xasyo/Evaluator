#include "Usuari.hh"
using namespace std;

Usuari::Usuari(){
    string a;
    identificador = a;
    problemes_intentats = 0;
    problemes_resolts = 0;
    problemes_disponibles = 0;
    nombre_enviaments = 0;
    curs = -1;
}

Usuari::Usuari(string s){
    identificador = s;
    problemes_intentats = 0;
    problemes_resolts = 0;
    problemes_disponibles = 0;
    nombre_enviaments = 0;
    curs = -1;
}

Usuari::~Usuari() {}

void Usuari::afegir_identificador(string s){
    identificador = s;
}

void Usuari::enviament(string s, int r){
    map<string,info_problema>::iterator it = problemes.find(s);
    if (it != problemes.end()){
        if (not it->second.intentat){
        it->second.intentat = true;
        ++problemes_intentats;
        }
        ++nombre_enviaments;
        int aux = it->second.vegades_intentat;
        it->second.vegades_intentat = aux+1;
        if (r == 1){
        --problemes_disponibles;
        it->second.resolt = true;
        it->second.disponible = false;
        ++problemes_resolts;
        }
    }
}

void Usuari::inscriure(int n){
    curs = n;
}

void Usuari::afegir_problema(string s){
    info_problema info;
    info.resolt = false;
    info.disponible = false;
    info.intentat = false;
    info.vegades_intentat = 0;
    problemes.insert(make_pair(s,info));
}

void Usuari::fer_disponible(string s){
    problemes[s].disponible = true;
    ++problemes_disponibles;
}

bool Usuari::inscrit() const {
    if (curs == -1) {return false;}
    else return true;
}

bool Usuari::disponible(string s) const {
    map<string,info_problema>::const_iterator it = problemes.find(s);
    if (it->second.disponible) return true;
    else return false;
}

bool Usuari::resolt(string s) const {
    map<string,info_problema>::const_iterator it = problemes.find(s);
    if (it->second.resolt) return true;
    else return false;
}

bool Usuari::intentat(string s) const {
    map<string,info_problema>::const_iterator it = problemes.find(s);
    if (it->second.intentat) return true;
    else return false;
}

bool Usuari::esta(string s) const {
    map<string,info_problema>::const_iterator it = problemes.find(s);
    
    if (it == problemes.end()){ return false;}
    else return true;
}
   
int Usuari::intentats() const{
    return problemes_intentats;
}

int Usuari::enviaments() const{
    return nombre_enviaments;
}

int Usuari::resolts() const{
    return problemes_resolts;
}

int Usuari::disponibles()const{
    return problemes_disponibles;
}

string Usuari::consultar_identificador() const {
    return identificador;
}

void Usuari::escriure() const{
    cout << identificador << "(" << nombre_enviaments << "," << problemes_resolts << "," << problemes_intentats << ",";
    if (curs == -1) cout << 0;
    else cout << curs;
    cout << ")";
    cout << endl;
}

void Usuari::escriure_disponibles() const{
    map<string,info_problema>::const_iterator it = problemes.begin();
    
    while (it != problemes.end()){
        if (it->second.disponible) cout << it->first << "(" << it->second.vegades_intentat << ")" <<  endl;
        ++it;
    }
}


int Usuari::cursant() const{
    return curs;
}

void Usuari::incrementar_vegades_intentat(string s){
    map<string, info_problema>::iterator it = problemes.find(s);
    if (it != problemes.end()){
        it->second.vegades_intentat += 1;
    }
}
    
void Usuari::escriure_resolts() const{
    
    map<string,info_problema>::const_iterator it = problemes.begin();
    
    while (it != problemes.end()){
        if (it->second.resolt) cout << it->first << "(" << it->second.vegades_intentat << ")" << endl;
        ++it;
    }
}

void Usuari::disponibilitzar(const BinTree<string>& a){
    if (not a.left().empty()){
        string e = a.left().value();
        if (not esta(e)){
            afegir_problema(e);
            fer_disponible(e);
        }
        else{
            disponibilitzar(a.left());
        }
    }
    if (not a.right().empty()){
        string d = a.right().value();
        if (not esta(d)){
            afegir_problema(d);
            fer_disponible(d);
        }
        else{
            disponibilitzar(a.right());
        }
    }
}
