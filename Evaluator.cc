#include "Evaluator.hh"
using namespace std;

Evaluator::Evaluator(){
    Cjt_usuaris aux1;
    usuaris = aux1;
    Cjt_cursos aux2;
    cursos = aux2;
    Cjt_sessions aux4;
    sessions = aux4;
    Cjt_problemes aux3;
    problemes = aux3;
}

Evaluator::~Evaluator(){}

void Evaluator::lectura_inicial_problemes(){
    int aux;
    cin >> aux;
    for (int i = 0; i < aux; ++i){
        string aux2;
        cin >> aux2;
        Problema aux3(aux2);
        problemes.insertar_problema(aux3);
    }
}

void Evaluator::lectura_inicial_sessions(){
    int aux;
    cin >> aux;
    for (int i = 0; i < aux; ++i){
        string aux2;
        cin >> aux2;
        Sessio aux3(aux2);
        aux3.llegir_sessio();
        sessions.insertar_sessio(aux3);
    }
}

void Evaluator::lectura_inicial_cursos(){
    int aux;
    cin >> aux;
    for (int i = 1; i <= aux; ++i){
        Curs aux2(i);
        cursos.afegir_curs(aux2);
        int aux3;
        cin >> aux3;
        for (int j = 0; j < aux3; ++j){
            string aux4; 
            cin >> aux4;
            cursos.afegir_sessio(i,aux4);
            cursos.afegir_problemes_sessio(i, aux4, sessions.consultar_sessio(aux4).conjunt_problemes());
        }
    }
}

void Evaluator::lectura_inicial_usuaris(){
    int aux;
    cin >> aux;
    for (int i = 0; i < aux; ++i){
        string aux2;
        cin >> aux2;
        Usuari aux3(aux2) ;
        usuaris.afegir_usuari(aux3);
    }
}

void Evaluator::nou_problema(string p){
    bool aux = problemes.esta(p);
    if (aux){
        cout << "error: el problema ya existe" << endl;
    }
    else {
        Problema aux2(p);
        problemes.insertar_problema(aux2);
        cout << problemes.nombre_problemes() << endl;
    }
}

void Evaluator::nova_sessio(string s){
    bool aux = sessions.esta(s);
    if (aux){
        cout << "error: la sesion ya existe" << endl;
    }
    else {
        Sessio aux2(s);
        aux2.llegir_sessio();
        sessions.insertar_sessio(aux2);
        cout << sessions.nombre_sessions() << endl;
    }
}

void Evaluator::alta_usuari(string u){
    bool aux = usuaris.esta(u);
    if (aux){
        cout << "error: el usuario ya existe" << endl;
    }
    else {
        Usuari aux2(u);
        usuaris.afegir_usuari(aux2);
        cout << usuaris.nombre_usuaris() << endl;
    }
}

void Evaluator::baixa_usuari(string u){
    bool aux = usuaris.esta(u);
    if (not aux){
        cout << "error: el usuario no existe" << endl;
    }
    else {
        if (usuaris.inscrit(u)){
            cursos.decrementar_usuaris_actuals(usuaris.cursant(u));
        }
        usuaris.esborrar_usuari(u);
        cout << usuaris.nombre_usuaris() << endl;
    }
}


void Evaluator::inscriure_curs(string u, int c){
    bool aux = usuaris.esta(u);
    if (not aux){
        cout << "error: el usuario no existe" << endl;
    }
    else{
        bool aux2 = cursos.esta(c);
        if (not aux2){
            cout << "error: el curso no existe" << endl;
        }
        else {
            Usuari aux3 = usuaris.consultar_identificador(u);
            if (aux3.inscrit()){
                cout << "error: usuario inscrito en otro curso" << endl;
            }
            else{
                aux3.inscriure(c);
                cursos.incrementar_usuaris_actuals(c);
                int y = cursos.nombre_de_sessions(c);
                for (int i = 0; i < y; ++i){
                    i_inscriure(aux3, sessions.arbre_problemes(cursos.sessio_numero(c, i)));
                }
                usuaris.modificar_usuari(aux3);
                cout << cursos.consultar_usuaris_actuals(c) << endl;
            }
        }
    }
}


void Evaluator::i_inscriure(Usuari& u, const BinTree<string>& a){
    if (not a.empty()){
        if (u.esta(a.value())){
             i_inscriure(u, a.right());
             i_inscriure(u, a.left());
        }
        else {
            u.afegir_problema(a.value());
            u.fer_disponible(a.value());
        }
    }
}

    
    
void Evaluator::curs_usuari(string u) const{
    bool aux = usuaris.esta(u);
    if (not aux){
        cout << "error: el usuario no existe" << endl;
    }
    else{
        if (usuaris.inscrit(u)){
            cout << usuaris.cursant(u) << endl;
        }
        else {
            cout << "0" << endl;
        }
    }
}


void Evaluator::sessio_problema(int c, string p)const{
    bool aux = cursos.esta(c);
    if (not aux){
        cout << "error: el curso no existe" << endl;
    }
    else {
        bool aux2 = problemes.esta(p);
        if (not aux2){
            cout << "error: el problema no existe" << endl;
        }
        else {
            if (not cursos.esta_problema(c, p)){
                cout << "error: el problema no pertenece al curso" << endl;
            }
            else{
                cout << cursos.sessio_problema(c, p) << endl;
            }
        }
    }
}

void Evaluator::problemes_resolts(string u) const{
    bool aux = usuaris.esta(u);
    if (not aux){
        cout << "error: el usuario no existe" << endl;
    }
    else{
        usuaris.escriure_resolts(u);
    }
}

void Evaluator::problemes_enviables(string u) const{
    bool aux = usuaris.esta(u);
    if (not aux){
        cout << "error: el usuario no existe" << endl;
    }
    else{
        if (not usuaris.inscrit(u)){
            cout << "error: usuario no inscrito en ningun curso" << endl;
        }
        else {
        usuaris.escriure_disponibles(u);
        }
    }
}

void Evaluator::llistar_problemes() const{
    problemes.llistar_problemes();
}

void Evaluator::llistar_sessions()const{
    sessions.escriure_sessions();
}
    
void Evaluator::llistar_cursos() const{
    cursos.llistar_cursos();
}

void Evaluator::llistar_usuaris() const{
    usuaris.llistar_usuaris();
}
    

void Evaluator::escriure_problema(string p){
    bool aux = problemes.esta(p);
    if (not aux){
        cout << "error: el problema no existe" << endl;
    }
    else {
        problemes.escriure_problema(p);
    }
}

void Evaluator::escriure_curs(int c){
    bool aux = cursos.esta(c);
    if (not aux){
        cout << "error: el curso no existe" << endl;
    }
    else {
        cursos.escriure_curs(c); 
    }
}

void Evaluator::escriure_usuari(string u){
    if (not usuaris.esta(u)){
        cout << "error: el usuario no existe" << endl;
    } 
    else {
        usuaris.escriure(u);
    }
}

void Evaluator::escriure_sessio(string s)const{
    bool aux = sessions.esta(s);
    if (not aux){
        cout << "error: la sesion no existe" << endl;
    }
    else {
        sessions.escriure_sessio(s);
    }
}

    
void Evaluator::enviament(string u, string p, int r){
    usuaris.enviament(u, p, r);
    if (r == 0) {
        problemes.enviament_incorrecte(p);
    }
    else if (r == 1){
        problemes.enviament_correcte(p);
        usuaris.disponibilitzar(u, sessions.arbre_problema(cursos.sessio_problema(usuaris.cursant(u), p), p));
        if (usuaris.disponibles(u) == 0){
            cursos.decrementar_usuaris_actuals(usuaris.cursant(u));
            cursos.incrementar_completats(usuaris.cursant(u));
            usuaris.inscriure(u, -1);
        }
    }
}

void Evaluator::disponibilitzar(Usuari& usuari, const BinTree<string>& a){
    if (not a.left().empty()){
        string e = a.left().value();
        if (not usuari.esta(e)){
            usuari.afegir_problema(e);
            usuari.fer_disponible(e);
        }
        else{
            disponibilitzar(usuari, a.left());
        }
    }
    if (not a.right().empty()){
        string d = a.right().value();
        if (not usuari.esta(d)){
            usuari.afegir_problema(d);
            usuari.fer_disponible(d);
        }
        else{
            disponibilitzar(usuari, a.right());
        }
    }
}
    
void Evaluator::nou_curs(){
    int u = cursos.nombre_de_cursos() + 1;
    Curs caux(u);
    int n;
    cin >> n;
    int i = 0;
    bool interseccio = false;
    while (i < n and not interseccio){
        string s;
        cin >> s;
        caux.afegir_sessio(s);
        set<string> aux = sessions.consultar_sessio(s).conjunt_problemes();
        set<string>::const_iterator it = aux.begin();
        while (it != aux.end() and not interseccio){
            if (not caux.esta_problema(*it)){
                caux.afegir_problema_sessio(s, *it);
            }
            else{
                interseccio = true;
            }
            ++it;
        }
        ++i;
    }
    if (not interseccio){
        cursos.afegir_curs(caux);
        cout << cursos.nombre_de_cursos() << endl;
    }
    else {
        cout << "error: curso mal formado" << endl;
    }
}
    
        
        
                
    
        
      
        
        
        
