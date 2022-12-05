#ifndef CJT_CURSOS_HH
#define CJT_CURSOS_HH

#include "Curs.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <string>
#endif

using namespace std;

/** @class Cjt_cursos
    @brief Representa un conjunt de cursos
*/
class Cjt_cursos{
    
    //Tipus de modul: dades
    //Descripció del tipus: representa un conjunt ordenat de cursos */
    
private:
    
    vector<Curs> cursos;
    
    /** @brief Cerca el curs n al conjunt
        
        \pre cert
        \post retorna la posició del curs amb identificador n al conjunt o -1 si no esta
    */
    
    
public:
    
    //Constructora
    
    /** @brief Constructora per defecte
        
        \pre cert
        \post crea un conjunt de cursos buit
    */
    Cjt_cursos();
    
    
    //Destructora
    
    /** @brief Destructora per defecte
        
        
    */
    ~Cjt_cursos();
    
    //Consultores
    
    /** @brief Consulta si el curs n esta al conjunt
        
        \pre cert
        \post retorna cert si hi ha un curs amb identificador n al conjunt o fals si no
    */
    bool esta(int n) const;
    
    
    /** @brief Consulta el curs amb identifcador n
        
        \pre hi ha un curs n al conjunt
        \post retorna el curs amb identificador n del conjunt
    */
    Curs consultar_curs(int n)const;
    
    
    /** @brief Consulta el nombre de cursos del conjunt
        
        \pre cert
        \post retorna el nombre de cursos del conjunt
    */
    int nombre_de_cursos() const;
    
    /** @brief Consulta l'identificador del curs c
        
        \pre hi ha un curs c al conjunt
        \post retorna l'identificador del curs c
    */
    int consultar_identificador(int c)const;
    
    /** @brief Consulta el nombre de sessions del curs c
        
        \pre hi ha un curs c al conjunt
        \post retorna el nombre de sessions que formen el curs c
    */
    int nombre_de_sessions(int c)const;
    
    /** @brief Consulta la sessio en la posicio n del curs c
        
        \pre hi ha un curs c al conjunt
        \post retorna el string en la posició n del curs c
    */
    string sessio_numero(int c, int n)const;
    
    /** @brief Consulta el nombre d'usuaris inscrits actualment al curs c
        
        \pre hi ha un curs c al conjunt
        \post retorna els usuaris actuals del curs c
    */
    int consultar_usuaris_actuals(int c)const;
    
    /** @brief Consulta el nombre d'usuaris que han completat el curs c
        
        \pre hi ha un curs c al conjunt
        \post retorna els usuaris que han completat el curs c
    */
    int consultar_completats(int c)const;
    
    /** @brief Consulta en quina sessio del curs c es troba el problema p
        
        \pre p pertany al curs c
        \post retorna la sessio del curs c on es troba el problema p
    */
    string sessio_problema(int c, string p)const;
    
    /** @brief Consulta si el problema p es troba al curs c
        
        \pre hi ha un curs c al conjunt
        \post retorna cert si p es troba al curs c o fals si no
    */
    bool esta_problema(int c, string p)const;
    
    
    //Modificadores
    
    /** @brief Afegeix el curs c al conjunt
        
        \pre no hi ha cap curs amb el mateix identificador que c al conjunt
        \post s'inserta de manera ordenada el curs c
    */
    void afegir_curs(Curs c);
    
    
    /** @brief Canvia el curs amb el mateix identifcador que c pel curs c
        
        \pre hi ha un curs al conjunt amb el mateix identifcador que c
        \post es substitueix el curs amb el mateix identificador que c per c
    */
    void modificar_curs(Curs c);
    
    /** @brief Afegeix els problemes p de la sessio s al curs c
        
        \pre cap problema de p es troba al curs c
        \post els problemes de p de la sessio s es troben al curs c
    */
    void afegir_problemes_sessio(int c, string s, const set<string>& p);
    
    /** @brief Afegeix el problema p de la sessio s al curs c
        
        \pre p no es troba al curs c
        \post el problema de p de la sessio s es troba al curs c
    */
    void afegir_problema_sessio(int c, string s, string p);
    
    /** @brief S'incrementa el nombre d'usuaris actuals del curs c
        
        \pre hi ha un curs c al conjunt
        \post s'incrementen els usuaris actuals del curs c
    */
    void incrementar_usuaris_actuals(int c);
    
    /** @brief Es decrementa el nombre d'usuaris actuals del curs c
        
        \pre hi ha un curs c al conjunt
        \post es decrementen els usuaris actuals del curs c
    */
    void decrementar_usuaris_actuals(int c);
    
    /** @brief S'incrementa el nombre d'usuaris que han completat el curs c
        
        \pre hi ha un curs c al conjunt
        \post s'incrementen els usuaris que han completat c
    */
    void incrementar_completats(int c);
    
    /** @brief Afegeix la sessio s al curs c
        
        \pre no hi ha cap sessio s al curs c
        \post s'inserta la sessio s al curs c 
    */
    void afegir_sessio(int c, string s);
    
    //Escriptura
    
    /** @brief Escriu pel canal de sortida els cursos del conjunt
        
        \pre cert
        \post surten pel canal de sortida els atributs de tots els cursos del conjunt de manera ordenada
    */
    void llistar_cursos()const;
    
    /** @brief Escriu pel canal de sortida el curs c
        
        \pre hi ha un curs c al conjunt
        \post s'ha escrit el curs c al canal de sortida
    */
    void escriure_curs(int c) const;
    
};
#endif
    
    
    
    
