#include "Sessio.hh"
using namespace std;

Sessio::Sessio(){
    BinTree<string> a;
    arbre = a;
    problemes = 0;
}

Sessio::Sessio(string s){
    BinTree<string> a;
    arbre = a;
    problemes = 0;
    identificador = s;
}

Sessio::~Sessio(){}

void Sessio::incrementar_problemes(){
    ++problemes;
}

string Sessio::arrel(){
    return arbre.value();
}

bool Sessio::esta(string s)const{
    return i_esta(s, arbre);
}

bool Sessio::i_esta(string s, const BinTree<string>& arbre) const {
    if (arbre.empty()) return false;
    else return (arbre.value() == s)
        or i_esta(s, arbre.left())
        or i_esta(s, arbre.right());
}

string Sessio::consultar_identificador() const{
    return identificador;
}

int Sessio::calcular_problemes(const BinTree<string>& a){
    int aux;
    if (a.empty()) aux = 0;
    else {
        aux = calcular_problemes(a.left()) + calcular_problemes(a.right()) ;
        ++aux;
    }
    return aux;
}

void Sessio::llegir_sessio(){
    BinTree<string> aux;
    i_llegir(aux);
    arbre = aux;
    problemes = calcular_problemes(arbre);
    crear_conjunt(arbre, probs);
}


void Sessio::escriure_sessio()const{
    cout << identificador << " " << problemes << " ";
    i_escriure(arbre);
    cout << endl;
}
    
void Sessio::i_escriure(const BinTree<string>& a)const{
    if (not a.empty()){
        cout << "(";
        i_escriure(a.left());
        i_escriure(a.right());
        cout << a.value() << ")";
    }
}

void Sessio::i_llegir(BinTree<string>& a){
    string s;
    cin >> s;
    if (s != "0"){
        BinTree<string> e;
        i_llegir(e);
        BinTree<string> d;
        i_llegir(d);
        
        a = BinTree<string>(s,e,d);
    }
}
    
string Sessio::i_fill_esquerre(const BinTree<string>& a, string s)const{
    if (a.value() == s){
        if (a.left().empty()){
            return "0";
        }
        else return a.left().value();
    }
    else{
        if (i_esta(s, a.left())){
            return i_fill_esquerre(a.left(), s);
        }
        else return i_fill_esquerre(a.right(), s);
    }
}

string Sessio::i_fill_dret(const BinTree<string>& a, string s)const{
    if (a.value() == s){
        if (a.right().empty()){
            return "0";
        }
        else return a.right().value();
    }
    else{
        if (i_esta(s, a.left())){
            return i_fill_dret(a.left(), s);
        }
        else return i_fill_dret(a.right(), s);
    }
}
    
string Sessio::fill_dret(string s)const{
    return i_fill_dret(arbre, s);
}

string Sessio::fill_esquerre(string s)const{
    return i_fill_esquerre(arbre, s);
}

void Sessio::crear_conjunt(const BinTree<string>& a, set<string>& c){
    if (not a.empty()){
        if (a.value() != "0"){
            c.insert(a.value());
        }
        crear_conjunt(a.left(), c);
        crear_conjunt(a.right(), c);
    }
}

BinTree<string> Sessio::arbre_problemes(){
    return arbre;
}

set<string> Sessio::conjunt_problemes()const{
    return probs;
}

BinTree<string> Sessio::i_arbre_problema(string p, const BinTree<string>& a){
    if (a.empty()) return BinTree<string> ();
    queue<BinTree<string>> cua;
    cua.push(a);
    
    while (not a.empty()){
        BinTree<string> aux = cua.front();
        if (aux.value() == p) return aux;
        if (not aux.left().empty()) cua.push(aux.left());
        if (not aux.right().empty()) cua.push(aux.right());
        cua.pop();
    }
    return BinTree<string> ();
}

BinTree<string> Sessio::arbre_problema(string p){
    return i_arbre_problema(p, arbre);
}
    
    
    
