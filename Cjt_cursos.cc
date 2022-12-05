#include "Cjt_cursos.hh"
using namespace std;



Cjt_cursos::Cjt_cursos(){
    vector<Curs> aux;
    cursos = aux;
}

Cjt_cursos::~Cjt_cursos(){}

bool Cjt_cursos::esta(int n) const{
    if ( n > cursos.size() or n <= 0) return false;
    else return true;
}

Curs Cjt_cursos::consultar_curs(int n)const {
    int a = n-1;
    return cursos[a];
}

int Cjt_cursos::nombre_de_cursos() const{
    return cursos.size();
}

void Cjt_cursos::afegir_curs(Curs c){
    cursos.push_back(c);
}

void Cjt_cursos::modificar_curs(Curs c){
    cursos[c.consultar_identificador() - 1] = c;
}

void Cjt_cursos::llistar_cursos()const{
    int n = cursos.size();
    for (int i = 0; i < n; ++i){
        cursos[i].escriure_curs();
    }
}

void Cjt_cursos::afegir_problemes_sessio(int c, string s, const set<string>& p){
    cursos[c-1].afegir_problemes_sessio(s, p);
}

void Cjt_cursos::afegir_problema_sessio(int c, string s, string p){
    cursos[c-1].afegir_problema_sessio(s, p);
}

void Cjt_cursos::incrementar_usuaris_actuals(int c){
    cursos[c-1].incrementar_usuaris_actuals();
}

void Cjt_cursos::decrementar_usuaris_actuals(int c){
    cursos[c-1].decrementar_usuaris_actuals();
}

void Cjt_cursos::incrementar_completats(int c){
    cursos[c-1].incrementar_completats();
}
    
void Cjt_cursos::afegir_sessio(int c, string s){
    cursos[c-1].afegir_sessio(s);
}


int Cjt_cursos::consultar_identificador(int c)const{
    return cursos[c-1].consultar_identificador();
}

int Cjt_cursos::nombre_de_sessions(int c)const{
    return cursos[c-1].nombre_de_sessions();
}

string Cjt_cursos::sessio_numero(int c, int n)const{
    return cursos[c-1].sessio_numero(n);
}

int Cjt_cursos::consultar_usuaris_actuals(int c)const{
    return cursos[c-1].consultar_usuaris_actuals();
}

int Cjt_cursos::consultar_completats(int c)const{
    return cursos[c-1].consultar_completats();
}

string Cjt_cursos::sessio_problema(int c, string p)const{
    return cursos[c-1].sessio_problema(p);
}

bool Cjt_cursos::esta_problema(int c, string p)const{
    return cursos[c-1].esta_problema(p);
}

void Cjt_cursos::escriure_curs(int c)const{
    cursos[c-1].escriure_curs();
}





        
