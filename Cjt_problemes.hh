#ifndef CJT_PROBLEMES_HH
#define CJT_PROBLEMES_HH

#include "Problema.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#endif

using namespace std;

/** @class Cjt_problemes
    @brief Representa un conjunt de problemes
*/
class Cjt_problemes {
    
private:
    //Tipus de modul: dades
    //Descripció del tipus: representa un cojunt de problemes
    
    map<string, Problema> problemes;
    
    /** @brief Compara dos problemes
        
        \pre cert
        \post un problema va abans que un altre si te un ratio menor o per ordre d'identificador
    */
    static bool comparacio_problemes(Problema p1, Problema p2);
    
    
public:
    //Constructores
    
    /** @brief Creadora per defecte
        
        \pre cert
        \post crea un conjunt de problemes buit
    */
    Cjt_problemes();
    
    
    //Destructora
    
    /** @brief Destructora per defecte
        
        
    */
    ~Cjt_problemes();
    
    //Consultores
    
    /** @brief Consulta el problema amb identificador s
        
        \pre el problema amb identificador s es troba al conjunt
        \post retorna el problema amb identificador s que es troba al conjunt
    */
    Problema consultar_problema(string s);
    
    /** @brief Consulta el nombre de problemes
        
        \pre cert
        \post retorna el nombre de problemes del conjunt
    */
    int nombre_problemes()const;
    
    
    
    /** @brief Consulta si hi ha un problema amb identificador s al conjunt 
        
        \pre cert
        \post retorna cert si hi ha un problema amb identificador s al conjunt o fals si no
    */
    bool esta(string s) const;
    
    /** @brief Consulta l'identificador del problema p
        
        \pre cert
        \post  retorna l'identificador del problema p
    */
    string consultar_identificador(string p)const;
    
    /** @brief Consulta els enviaments totals fets al problema p
        
        \pre hi ha un problema p al conjunt
        \post retorna el nombre d'enviaments totals al problema p
    */
    int consultar_enviaments_totals(string p)const;
    
    /** @brief Consulta els enviaments correcte fets al problema p
        
        \pre hi ha un problema p al conjunt
        \post retorna el nombre d'enviaments correctes al problema p
    */
    int consultar_enviments_correctes(string p)const;
    
    /** @brief Consulta el ratio de correctesa dels enviaments del problema p
        
        \pre hi ha un problema p al conjunt
        \post retorna el ratio de correctesa del problema p
    */
    double consultar_ratio(string p)const;
    
    //Modificadores 
    
    /** @brief Es fa un enviament incorrecte al problema p
        
        \pre hi ha un problema p al conjunt
        \post  s'incrementen els enviaments correctes i totals del problema p i es recalcula el ratio
    */
    void enviament_incorrecte(string p);
    
    
    /** @brief Es fa un enviament correcte al problema p
        
        \pre hi ha un problema p al conjunt
        \post s'incrementen els enviaments del problema p i es recalcula ratio
    */
    void enviament_correcte(string p);
    
    /** @brief Inserta el problema p al conjunt
        
        \pre el problema p no es troba al conjunt
        \post s'inserta ordenadament el problema p
    */
    void insertar_problema(Problema p);
    
    
    /** @brief Canvia el problema amb el mateix identificador que p per el problema p
        
        \pre el problema p es troba al conjunt
        \post el problema amb l'identificador de p s'ha substituït per p
    */
    void modificar_problema(Problema p);
    
    
    //Escriptura 
    
    /** @brief Llista al canal de sortida els problemes de conjunt
        
        \pre cert
        \post surten pel canal de sortida els atributs de cada element del conjunt de manera ordenada
    */
    void llistar_problemes()const;
    
    /** @brief Escriu el problema p al canal de sortida
        
        \pre hi ha un problema p al conjunt
        \post s'escriuren pel canal de sortida els atributs del problema p
    */
    void escriure_problema(string p)const;

};
#endif
    
    

