#include "Curs.hh"
using namespace std;

Curs::Curs(){
    vector<string> s;
    sessions = s;
    usuaris_actuals = 0;
    completats = 0;
}

Curs::Curs(int n){
    vector<string> s;
    sessions = s;
    usuaris_actuals = 0;
    completats = 0;
    identificador = n;
}

Curs::~Curs(){}

int Curs::consultar_identificador() const {
    return identificador;
}

int Curs::nombre_de_sessions() const {
    return sessions.size();
}

string Curs::sessio_numero(int n) const{
    return sessions[n];
}


int Curs::consultar_usuaris_actuals() const{
    return usuaris_actuals;
}

int Curs::consultar_completats() const{
    return completats;
}

void Curs::incrementar_usuaris_actuals(){
    ++usuaris_actuals;
}

void Curs::decrementar_usuaris_actuals(){
    --usuaris_actuals;
}

void Curs::incrementar_completats(){
    ++completats;
}

void Curs::afegir_sessio(string s){
    sessions.push_back(s);
}

void Curs::escriure_curs() const{
    cout << identificador << " " << completats << " " << usuaris_actuals << " " << sessions.size() << " (";
    int a = sessions.size();
    for (int i = 0; i < a; ++i){
        cout << sessions[i];
        if (i != a-1){
            cout << " ";
        }
        else cout << ")";
    }
    cout << endl;
}

string Curs::sessio_problema(string p)const{
    map<string, string>::const_iterator it = ps.find(p);
    return it->second;
}

bool Curs::esta_problema(string p)const{
    map<string, string>::const_iterator it = ps.find(p);
    if (it == ps.end()){
        return false;
    }
    else return true;
}

void Curs::afegir_problemes_sessio(string s, const set<string>& p){
    set<string>::const_iterator it = p.begin();
    while (it != p.end()){
        ps.insert(make_pair(*it, s));
        ++it;
    }
}

void Curs::afegir_problema_sessio(string s, string p){
    ps.insert(make_pair(p, s));
}
    
    
    
    
    
    
    
    
    
