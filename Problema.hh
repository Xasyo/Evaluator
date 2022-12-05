#ifndef PROBLEMA_HH
#define PROBLEMA_HH

#ifndef NO_DIAGRAM
#include <string>
#include <iostream>
#endif

using namespace std;




/** @class Problema
    @brief Representa un problema de la plataforma Evaluator
*/
class Problema {
    
    //Tipus de modul: dades
    //Descripció del tipus: conté l'identificador del problema, el nombre d'enviaments 
    //totals t, el nombre d'enviaments correctes e i el ratio (t+1)/(e+1)
    
private:
    string identificador;
    int t;
    int e;
    double ratio;
    
    /* t >= 0, e >= 0, ratio >= 1 */
    
    
public:
    //Constructores
    
    /** @brief Creadora per defecte
        
        \pre cert
        \post crea un problema buit
    */
    Problema();
    
    
    /** @brief Creadora amb identifcador
        
        \pre cert
        \post crea un problema amb identificador s
    */
    Problema(string s);
    
    
    //Destructora
    
    /** @brief Destructora per defecte
        
        
    */
    ~Problema();
    
    //Modificadores;
    
    /** @brief Afegeix l'identificador s al problema
        
        \pre  el parametre implicit no té identificador
        \post  l'identificador del parametre implicit passa a ser s
    */
    void afegir_identificador(string s);
    
    
    /** @brief Es fa un enviament incorrecte al problema
        
        \pre cert
        \post  s'incrementen els enviaments correctes i totals del problema i es recalcula el ratio
    */
    void enviament_incorrecte();
    
    
    /** @brief Es fa un enviament correcte al problema
        
        \pre cert
        \post s'incrementen els enviaments del problema i es recalcula ratio
    */
    void enviament_correcte();
    
    
    //Consultores
    
    /** @brief Consulta l'identificador del problema
        
        \pre cert
        \post  retorna l'identificador del problema
    */
    string consultar_identificador()const;
    
    
    /** @brief Consulta els enviaments totals fets al problema
        
        \pre cert
        \post retorna el nombre d'enviaments totals
    */
    int consultar_enviaments_totals()const;
    
    
    /** @brief Consulta els enviaments correcte fets al problema
        
        \pre cert
        \post retorna el nombre d'enviaments correctes
    */
    int consultar_enviaments_correctes()const;
    
    
    /** @brief Consulta el ratio de correctesa dels enviaments
        
        \pre cert
        \post retorna el ratio de correctesa del problema
    */
    double consultar_ratio()const;
    
    
    //Escriptura 
    
    /** @brief Escriu el problema al canal de sortida
        
        \pre cert
        \post s'escriuren perl canal de sortida els atributs del parametre implicit
    */
    void escriure()const;
    
    
};
#endif
