#ifndef CONJ_USUARIS_HH
#define CONJ_USUARIS_HH

#include "Usuari.hh"
#include "BinTree.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#endif

using namespace std;

/** @class Cjt_usuaris
    @brief Representa un conjunt d'usuaris 
*/
class Cjt_usuaris {
    
private:
    //Tipus de modul: dades
    //Descripció del tipus: representa un diccionari d'usuaris  
    
    map<string, Usuari> conjunt;
    
public:
    
    //Constructores
    
    /** @brief Creadora per defecte
        
        \pre cert
        \post el resultat es un conjunt d'usuaris buit
    */
    Cjt_usuaris();
    
    
    //Destructora
    
    /** @brief Destructora per defecte
        
        
    */
    ~Cjt_usuaris();
    
    //Modificadores
    
    /** @brief Afegeix un usuari aux al conjunt
        
        \pre aux no es troba al conjunt
        \post s'ha afegit l'usuari aux al conjunt
    */
    void afegir_usuari(Usuari aux);
    
    
    /** @brief Elimina l'usuari s del conjunt
        
        \pre l'usuari amb identificador s es troba al conjunt
        \post l'usuari amb identificador s s'ha esborrat del conjunt
    */
    void esborrar_usuari(string s);
    
    
    /** @brief Canvia l'usuari amb identificador s per aux
        
        \pre hi ha un usuari amb identificador s al conjunt
        \post l'usuari amb identificador s s'ha substituit amb aux
    */
    void modificar_usuari(Usuari aux);
    
    /** @brief Realitza un enviament de l'usuari u al problema s amb resultat r 
        
        \pre el problema amb identificador s esta disponible per u pero no resolt
        \post si r = 1 l'enviament es correcte i el problema amb identificador s passa a estar resolt i no disponible, a més si no havia estat intentat s'incrementa problemes_intentats i el problema passa a estar intentat, s'incrementa problemes_reslots i nombre_enviaments, si r = 0 l'enviament no és correcte el problema romandrà disponible i no resolt, si havia no havia estat intentat, s'incrementa problemes_intentats i el problema passa a estar intentat, s'incrementa també el nombre d'enviaments
    */
    void enviament(string u, string s, int r);
    
    /** @brief Actualitza els problemes de l'usuari u tenint en compte que u ha resolt l'arrel de l'arbre
        
        \pre hi ha un usuari u al conjunt
        \post s'ha actualitzat la informacio de l'usuari u
    */
    void disponibilitzar(string u, const BinTree<string>& a);
    
    
    /** @brief Inscriu a l'usuari u al curs n
        
        \pre l'usuari no esta inscrit en cap curs
        \post u esta inscrit en el curs n
    */
    void inscriure(string u, int n);
    
    /** @brief Afegeix el problema s a l'usuari s
        
        \pre no hi ha cap problema amb identificador s a l'usuari u
        \post a l'usuari u es troba el problema amb identificador s, no intentat, no resolt i no disponible
    */
    void afegir_problema(string u, string s);
    
    /** @brief Fa que el problema s estigui disponible per l'usuari u
        
        \pre el problema amb identificador s no esta disponible per l'usuari u
        \post el problema amb identificador s esta disponible per l'usuari u
    */
    void fer_disponible(string u, string s);
    
    /** @brief incrementa les vegades que ha estat intentat el problema s per l'usuari u
        
        \pre cert
        \post incrementa les vegades que ha estat intentat el problema s per l'usuari u
    */
    void incrementar_vegades_intentat(string u, string s);
    
    //Consultores
    
    /** @brief Consulta si l'usuari u esta inscrit en un curs
        
        \pre hi ha un usuari u al conjunt
        \post retorna cert si l'usuari u esta inscrit en un curs o fals si no ho esta
    */
    bool inscrit(string u)const;
    
    /** @brief Consulta el curs en el que esta inscrit l'usuari u
        
        \pre l'usuari u esta inscrit en un curs
        \post retorna el curs on esta inscrit l'usuari u
    */
    int cursant(string u)const;
    
    /** @brief Consulta si un problema s esta disponible per l'usuari u
        
        \pre  el problema amb identificador s es troba a l'usuari u
        \post retorna cert si el problema esta disponible o fals si no ho esta per l'usuari u
    */
    bool disponible(string u, string s)const;
    
    /** @brief Consulta si un problema s esta resolt per l'usuari u
        
        \pre  el problema amb identificador s es troba a l'usuari u
        \post retorna cert si el problema esta resolt o fals si no ho esta per l'usuari u
    */
    bool resolt(string u, string s)const;
    
    /** @brief Consulta si un problema s esta intentat per l'usuari u
        
        \pre  el problema amb identificador s es troba a l'usuari u
        \post retorna cert si el problema esta intentat o fals si no ho esta per l'usuari u
    */
    bool intentat(string u, string s)const;
    
    /** @brief Consulta si un problema s esta a l'usuari u
        
        \pre hi ha un usuari u al conjunt
        \post retorna cert si el problema esta a l'usuari u o fals si no ho esta
    */
    bool esta_problema(string u, string s)const;
    
    /** @brief Consulta el nombre d'enviaments que ha fet l'usuari u
        
        \pre hi ha un usuari u al conjunt
        \post retorna el nombre d'enviaments de u
    */
    int enviaments(string u)const;
    
    /** @brief Consulta el nombre de problemes disponibles per l'usuariu 
        
        \pre hi ha un usuari u al conjunt
        \post retorna el nombre de problemes disponibles per u
    */
    int disponibles(string u)const;
    
    /** @brief Consulta el nombre de problemes que ha resolt l'usuari u
        
        \pre hi ha un usuari u al conjunt
        \post retorna el nombre de problemes resolts per u
    */
    int resolts(string u)const;
    
    
    /** @brief Consulta si l'usuari s esta al conjunt
        
        \pre cert
        \post retorna cert si hi ha un usuari amb identificador s al conjunt o fals si no
    */
    bool esta(string s) const;
    
    /** @brief Consulta el nombre d'usuaris del conjunt
        
        \pre cert
        \post retorna el nombre d'usuaris del conjunt
    */
    int nombre_usuaris()const;
    
    
    /** @brief Consulta l'usuari amb identificador s
        
        \pre hi ha un usuari amb identificador s al conjunt
        \post retrona l'usuari amb identificador s
    */
    Usuari consultar_identificador(string s) const;
    
    
    //Escriptura
    
    /** @brief Escriu els usuaris del conjunt al canal de sortida
        
        \pre cert
        \post s'escriuren al canal de sortida els usuaris del conjunt per ordre creixent d'identificador
    */
    void llistar_usuaris() const;
    
    /** @brief Escriu al canal de sortida l'usuari u
        
        \pre cert 
        \post s'han escrit al canal de sortida els atributs de u
    */
    void escriure(string u)const;
    
    /** @brief Escriu al canal de sortida els problemes disponibles per l'usuari u
        
        \pre cert
        \post s'han llistat al canal de sortida els problemes disponibles per l'usuari u
    */
    void escriure_disponibles(string u)const;
    
    /** @brief Escriu al canal de sortida els problemes resolts per l'usuari u
        
        \pre cert
        \post s'han llistat al canal de sortida els problemes resolts per l'usuari u
    */
    void escriure_resolts(string u)const;
    
    
};
#endif
