#ifndef SESSIO_HH
#define SESSIO_HH

#include "BinTree.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <set>
#include <string>
#include <queue>
#endif

using namespace std;





/** @class Sessio
    @brief Representa una sessio de la plataforma Evaluator
 */
class Sessio {
    
    //Tipus de modul: dades
    //Descripció del tipus: cada sessió esta formada per un string identificador, un
    //arbre binari de strings on cada element representa un problema i estan
    //distribuïts per relació de prerequisits i un enter problemes que representa el
    //nombre de problemes que conté la sessió

private:
    
    string identificador;
    BinTree<string> arbre;
    set<string> probs;
    int problemes;
    
     /** @brief funcio d'inmersio per esta
        
        \pre cert
        \post retorna cert si hi ha un element s a la sessio o fals si no
    */
    bool i_esta(string s, const BinTree<string>& arbre) const;
    
    
    /** @brief Calcula el nombre de problemes
        \pre cert
        \post retorna el nombre de problemes de la sessio
    */
    int calcular_problemes(const BinTree<string>& a);
    
    
    /** @brief funcio d'inmersio per llegir_sessio
        
        \pre  es troben al canal d'entrada un recull d'identificadors de problemes en preordre
        \post  s'introdueixen a la sessio els strings identificadors dels problemes
    */
    void i_llegir(BinTree<string>& a);
    
    /** @brief funcio d'inmersio per escriure_sessio
        
        \pre  cert
        \post  s'escriu al canal de sortida els identificadors dels problemes de la sessio en postrodre
    */
    void i_escriure(const BinTree<string>& a)const;
    
    /** @brief funcio d'inmersio per fill_esquerre
        
        \pre  s es troba a l'arbre a
        \post  retorna l'arrel del fill esquerre de l'arbre amb arrel s
    */
    string i_fill_esquerre(const BinTree<string>& a, string s)const;
    
    /** @brief funcio d'inmersio per fill_esquerre
        
        \pre  s es troba a l'arbre a
        \post  retorna l'arrel del fill dret de l'arbre amb arrel s
    */
    string i_fill_dret(const BinTree<string>& a, string s) const;
    
    
public: 
    //Constructores
    
    /** @brief Constructora per defecte 
        
        \pre cert
        \post el resultat es una sessio buida
    */
    Sessio();
    
    
    /** @brief Constructora amb identificador
        
        \pre cert
        \post el resultat es una sessio amb identificador s
    */
    Sessio(string s);
    
    //Destructora 
    
    /** @brief Destructora per defecte
        
       
    */
    ~Sessio();
    
    //Modificadores
    
    /** @brief Incrementa el nombre de problemes de la sessio
        
        \pre cert
        \post incrementa el nombre de problemes
    */
    void incrementar_problemes();
    
    /** @brief Omple c amb els elements de a
        
        \pre cert
        \post es troben a c els elements de a
    */
    void crear_conjunt(const BinTree<string>& a, set<string>& c);
    
    //Consultores
    
    /** @brief Retorna un conjunt amb tots els identificadors dels problemes de la sessio
        
        \pre cert
        \post retorna un conjunt amb els identificadors dels problemes de la sessio
    */
    set<string> conjunt_problemes()const;
    
    /** @brief Retorna l'arbre de problemes de la sessio
        
        \pre cert
        \post retorna l'arbre de la sessio
    */
    BinTree<string> arbre_problemes();
    
    /** @brief Consulta si el problema s esta a la sessio
        
        \pre cert
        \post retorna cert si hi ha un element s a la sessio o fals si no
    */
    bool esta(string s) const;
    
    
    /** @brief Consulta l'identificador
        
        \pre cert
        \post retorna l'identificador
    */
    string consultar_identificador()const;
    
    /** @brief Consulta el primer problema de la sessio
        
        \pre cert
        \post el primer problema de la sessio
    */
    string arrel();
    
    /** @brief Consulta el l'arrel del fill esquerre de l'arbre amb arrel s
        
        \pre  s es troba a l'arbre a
        \post  retorna l'arrel del fill esquerre de l'arbre amb arrel s
    */
    string fill_esquerre(string s)const;
    
    /** @brief Consulta el l'arrel del fill dret de l'arbre amb arrel s
        
        \pre  s es troba a l'arbre a
        \post  retorna l'arrel del fill dret de l'arbre amb arrel s
    */
    string fill_dret(string s)const;
    
    /** @brief Consulta el subarbre de a amb arrel p
        
        \pre  p es troba a l'arbre de la sessio
        \post  retorna el subarbre de a amb arrel p
    */
    BinTree<string> arbre_problema(string p);
    
    /** @brief Funcio d'inmersio per arbre_problema
        
        \pre  p es troba a l'arbre a
        \post  retorna el subarbre de a amb arrel p
    */
    BinTree<string> i_arbre_problema(string p, const BinTree<string>& a);
    
    //Lectura i escriptura
    
    /** @brief Llegeix una sessio del canal d'entrada
        
        \pre  es troben al canal d'entrada un recull d'identificadors de problemes en preordre
        \post  s'introdueixen a la sessio els strings identificadors dels problemes
    */
    void llegir_sessio();
    
    /** @brief Escriu una sessio al canal de sortida
        
        \pre cert
        \post al canal de sortida s'escriuren  l'identificador, el nombre de problemes i els identificadors dels problemes en postordre
    */
    void escriure_sessio()const;
    
    
};
#endif
    
