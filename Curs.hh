#ifndef CURS_HH
#define CURS_HH

#ifndef NO_DIAGRAM
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#endif

using namespace std;





/** @class Curs
    @brief Representa un curs de la plataforma Evaluator
*/
class Curs {
    
    //Tipus de modul: dades
    //Descripció del tipus: representa un curs amb el seu numero que l'identifica, i amb un vector de strings d'identificadors de les sessions que el formen
    
private:
    
    vector<string> sessions;
    map<string, string> ps;
    int identificador;
    int usuaris_actuals;
    int completats;
    
    /* identificador > 0 */
    

    
public:
    
    //Constructora
    
    /** @brief Constructora per defecte
        
        \pre cert 
        \post crea un curs buit
    */
    Curs();
    
    
    /** @brief Constructora amb identificador
        
        \pre cert
        \post crea un curs amb identificador n
    */
    Curs(int n);
    
    
    //Destructora
    
    /** @brief Destructora per defecte
        
       
    */
    ~Curs();
    
    //Consultores 
    
    /** @brief Consulta l'identificador del curs
        
        \pre cert
        \post retorna l'identificador del curs
    */
    int consultar_identificador() const;
    
    
    /** @brief Consulta el nombre de sessions del curs
        
        \pre cert
        \post retorna el nombre de sessions que formen el curs
    */
    int nombre_de_sessions() const;
    
    
    /** @brief Consulta la sessio en la posicio n
        
        \pre cert
        \post retorna el string en la posició n
    */
    string sessio_numero(int n) const;
    
    
    /** @brief Consulta el nombre d'usuaris inscrits actualment al curs
        
        \pre cert
        \post retorna els usuaris actuals
    */
    int consultar_usuaris_actuals() const;
    
    
    /** @brief Consulta el nombre d'usuaris que han completat el curs
        
        \pre cert
        \post  retorna els usuaris que han completat el curs
    */
    int consultar_completats() const;
    
    /** @brief Consulta en quina sessio del curs es troba el problema p
        
        \pre p pertany al curs
        \post retorna la sessio del curs on es troba el problema p
    */
    string sessio_problema(string p)const;
    
    /** @brief Consulta si el problema p es troba al curs
        
        \pre cert
        \post retorna cert si p es troba al curs o fals si no
    */
    bool esta_problema(string p)const;
    
    //Modificadores 
    
    /** @brief Afegeix els problemes p de la sessio s al curs
        
        \pre cap problema de p es troba al curs
        \post els problemes de p de la sessio s es troben al curs
    */
    void afegir_problemes_sessio(string s, const set<string>& p);
    
    /** @brief Afegeix el problema p de la sessio s al curs
        
        \pre p no es troba al curs
        \post el problema de p de la sessio s es troba al curs
    */
    void afegir_problema_sessio(string s, string p);

     
    /** @brief S'incrementa el nombre d'usuaris actuals del curs
        
        \pre cert
        \post s'incrementen els usuaris actuals
    */
    void incrementar_usuaris_actuals();
    
    
    /** @brief Es decrementa el nombre d'usuaris actuals del curs
        
        \pre cert
        \post es decrementen els usuaris actuals
    */
    void decrementar_usuaris_actuals();
    
    
    /** @brief S'incrementa el nombre d'usuaris que han completat el curs
        
        \pre cert
        \post s'incrementen els usuaris que l'han completat
    */
    void incrementar_completats();
    
    
    /** @brief Afegeix la sessio s al curs
        
        \pre no hi ha cap sessio s al curs
        \post s'inserta la sessio s al curs 
    */
    void afegir_sessio(string s);
    
    //Escriptura
    
    /** @brief Escriu els atribults del curs
        
        \pre cert
        \post s'han escrit al canal de sortida els atributs del parametre implicit
    */
    void escriure_curs() const;
    
};
#endif
