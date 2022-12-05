#ifndef USUARI_HH
#define USUARI_HH


#include "BinTree.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <vector>
#include <string>
#endif

using namespace std;



/** @class Usuari
    @brief Representa un usuari de la plataforma Evaluator
 */
class Usuari {
    
   
    
private:
    string identificador;
    int problemes_intentats;
    int problemes_resolts;
    int nombre_enviaments;
    int problemes_disponibles;
    int curs;
    struct info_problema{
        bool disponible;
        bool intentat;
        bool resolt;
        int vegades_intentat;
    };
    map<string, info_problema> problemes;
    
    //problemes[string].disponible indica si el problema amb indicador string esta
    //disponible o no, problemes[string].resolt indica si el problema amb indicador 
    //esta resolt o no i problemes[string].intentat indica si el problema amb 
    //identificador string ha estat intentat
    
    /* problemes_intentats >= 0, problemes_resolts >= 0, nombre_enviaments >= 0, if problemes[string].resolt == true --> problemes[string].disponible == false */
    
    
public:
    //Constructores
    
    /** @brief Constructora per defecte
        
        \pre cert
        \post crea un usuari buit
        
    */
    Usuari();
    
    /** @brief Constructora amb identificador
        
        \pre cert
        \post crea un usuari amb identificador = s
    
    */
    Usuari(string s);
    
    //Destructora
    
    /** @brief Destructora per defecte 
        
    */
    ~Usuari();
    
    //Modificadores
    
    /** @brief Actualitza els problemes de l'usuari tenint en compte que ha resolt l'arrel de l'arbre
        
        \pre cert
        \post s'ha actualitzat la informacio de l'usuari
    */
    void disponibilitzar(const BinTree<string>& a);
    
    /** @brief Afegeix un identificador a l'usuari
        
        \pre el parametre implícit no té identificador
        \post l'identificador del parametre implicit passa a ser s
    */
    void afegir_identificador(string s);
    
    
    /** @brief Realitza un enviament al problema s amb resultat r
        
        \pre el problema amb identificador s esta disponible pero no resolt
        \post si r = 1 l'enviament es correcte i el problema amb identificador s passa a estar resolt i no disponible, a més si no havia estat intentat s'incrementa problemes_intentats i el problema passa a estar intentat, s'incrementa problemes_reslots i nombre_enviaments, si r = 0 l'enviament no és correcte el problema romandrà disponible i no resolt, si havia no havia estat intentat, s'incrementa problemes_intentats i el problema passa a estar intentat, s'incrementa també el nombre d'enviaments
    */
    void enviament(string s, int r);
    
    /** @brief Inscriu a l'usuari al curs n
        
        \pre el parametre implicit no esta inscrit en cap curs
        \post el parametre implicit esta inscrit en el curs n
    */
    void inscriure(int n);
    
    
    /** @brief Afegeix el problema s a l'usuari
        
        \pre no hi ha cap problema amb identificador s
        \post al parametre implicit es troba el problema amb identificador s, no intentat, no resolt i no disponible
    */
    void afegir_problema(string s);
    
    
    /** @brief Fa que el problema s estigui disponible per l'usuari
        
        \pre el problema amb identificador s no esta disponible per l'usuari
        \post el problema amb identificador s esta disponible per l'usuari
    */
    void fer_disponible(string s);
    
    /** @brief incrementa les vegades que ha estat intentat el problema s per l'usuari
        
        \pre cert
        \post incrementa les vegades que ha estat intentat el problema s per l'usuari
    */
    void incrementar_vegades_intentat(string s);
    
    //Consultores 
    
    
    /** @brief Consulta si l'usuari esta inscrit en un curs
        
        \pre cert
        \post retorna cert si l'usuari esta inscrit en un curs o fals si no ho esta
    */
    bool inscrit() const;
    
    
    /** @brief Consulta el curs en el que esta inscrit l'usuari
        
        \pre l'usuari esta inscrit en un curs
        \post retorna el curs on esta inscrit l'usuari
    */
    int cursant() const;
    
    
    /** @brief Consulta si un problema s esta disponible per l'usuari
        
        \pre  el problema amb identificador s es troba a l'usuari
        \post retorna cert si el problema esta disponible o fals si no ho esta
    */
    bool disponible(string s) const;
    
    /** @brief Consulta si un problema s esta resolt per l'usuari
        
        \pre  el problema amb identificador s es troba a l'usuari
        \post retorna cert si el problema esta resolt o fals si no ho esta
    */
    bool resolt(string s) const;
    
    /** @brief Consulta si un problema s esta intentat per l'usuari
        
        \pre  el problema amb identificador s es troba a l'usuari
        \post retorna cert si el problema esta intentat o fals si no ho esta
    */
    bool intentat(string s) const;
    
    /** @brief Consulta si un problema s esta a l'usuari
        
        \pre cert 
        \post retorna cert si el problema esta a l'usuari o fals si no ho esta
    */
    bool esta(string s) const;
    
    
    /** @brief Consulta el nombre de problemes que ha intentat l'usuari
        
        \pre cert 
        \post retorna el nombre de problemes intentats
    */
    int intentats() const;
    
    
    /** @brief Consulta el nombre d'enviaments que ha fet l'usuari
        
        \pre cert 
        \post retorna el nombre d'enviaments
    */
    int enviaments() const; 
    
    /** @brief Consulta el nombre de problemes disponibles per l'usuari
        
        \pre cert 
        \post retorna el nombre de problemes disponibles
    */
    int disponibles()const;
    
    /** @brief Consulta el nombre de problemes que ha resolt l'usuari
        
        \pre cert
        \post retorna el nombre de problemes resolts
    */
    int resolts() const;
    
    
    /** @brief Consulta l'identificador de l'usuari
        
        \pre cert 
        \post retorna l'identificador de l'usuari
    */
    string consultar_identificador() const;
    
    
    // Escriputura
    
    /** @brief Escriu al canal de sortida un usuari
        
        \pre cert 
        \post s'han escrit al canal de sortida els atributs del parametre implicit
    */
    void escriure() const;
    
    
    /** @brief Escriu al canal de sortida els problemes disponibles per l'usuari
        
        \pre cert
        \post s'han llistat al canal de sortida els problemes disponibles per l'usuari
    */
    void escriure_disponibles() const;
    
    
    /** @brief Escriu al canal de sortida els problemes resolts per l'usuari
        
        \pre cert
        \post s'han llistat al canal de sortida els problemes resolts per l'usuari
    */
    void escriure_resolts() const;
    
    
};
#endif
    
