#include "Cjt_sessions.hh"
using namespace std;

Cjt_sessions::Cjt_sessions(){
    map<string, Sessio> aux;
    sessions = aux;
}

Cjt_sessions::~Cjt_sessions(){}

int Cjt_sessions::nombre_sessions() const{
    return sessions.size();
}

bool Cjt_sessions::esta(string s) const{
    map<string, Sessio>::const_iterator it = sessions.find(s);
    if (it == sessions.end()){
        return false;
    }
    else return true;
}

Sessio Cjt_sessions::consultar_sessio(string s) const{
    map<string, Sessio>::const_iterator it = sessions.find(s);
    return it->second;
}

void Cjt_sessions::insertar_sessio(Sessio s){
    pair<string, Sessio> aux;
    aux.first = s.consultar_identificador();
    aux.second = s;
    sessions.insert(aux);
}

void Cjt_sessions::modificar_sessio(Sessio s){
    map<string, Sessio>::iterator it = sessions.find(s.consultar_identificador());
    it->second = s;
}

void Cjt_sessions::llegir_sessions(int n){
    for (int i = 0; i < n; ++i){
        Sessio aux;
        aux.llegir_sessio();
        pair<string, Sessio> s;
        s.first = aux.consultar_identificador();
        s.second = aux;
        sessions.insert(s);
    }
}

void Cjt_sessions::escriure_sessions()const{
    map<string, Sessio>::const_iterator it = sessions.begin();
    while(it != sessions.end()){
        it->second.escriure_sessio();
        ++it;
    }
}
    
set<string> Cjt_sessions::conjunt_problemes(string s)const{
    map<string, Sessio>::const_iterator it = sessions.find(s);
    return it->second.conjunt_problemes();
}
    
    
BinTree<string> Cjt_sessions::arbre_problemes(string s){
    map<string, Sessio>::iterator it = sessions.find(s);
    return it->second.arbre_problemes();
}    
    
bool Cjt_sessions::esta(string s, string p)const{
    map<string, Sessio>::const_iterator it = sessions.find(s);
    return it->second.esta(p);
}    
    
BinTree<string> Cjt_sessions::arbre_problema(string s, string p){
    map<string, Sessio>::iterator it = sessions.find(s);
    return it->second.arbre_problema(p);
}
    
void Cjt_sessions::incrementar_problemes(string s){
    map<string, Sessio>::iterator it = sessions.find(s);
    it->second.incrementar_problemes();
}
void Cjt_sessions::crear_conjunt(string s, const BinTree<string>& a, set<string>& c){
    map<string, Sessio>::iterator it = sessions.find(s);
    it->second.crear_conjunt(a, c);
}
    
void Cjt_sessions::escriure_sessio(string s)const{
    map<string, Sessio>::const_iterator it = sessions.find(s);
    it->second.escriure_sessio();
}
    
    
    
    

    
