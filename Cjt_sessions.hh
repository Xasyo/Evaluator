#ifndef CJT_SESSIONS_HH
#define CJT_SESSIONS_HH

#include "Sessio.hh"
#include "BinTree.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <set>
#include <string>
#endif

using namespace std;

/** @class Cjt_sessions
    @brief Representa un conjunt de sessions
*/
class Cjt_sessions{
    
    //Tipus de modul: dades
    //Descripció del tipus: representa un conjunt ordenat de sessions 
    
private: 
    
    map<string, Sessio> sessions;
    
    
     
    
    
public:
    
    //Constructores 
    
    /** @brief Creadora per defecte
        
        \pre cert
        \post crea un conjunt de sessions buit
    */
    Cjt_sessions();
    
    
    //Destrucotra
    
    /** @brief Destrucotra per defecte
        
        
    */
    ~Cjt_sessions();
    
    //Consultores
    
    /** @brief Consulta el nombre de sessions de conjunt
        
        \pre cert
        \post retorna el nombre de sessions del conjunt
    */
    int nombre_sessions() const;
    
    
    /** @brief Consulta si la sessio s esta al conjunt
        
        \pre cert
        \post retorna cert si hi ha una sessio amb identificador s al conjunt o fals si no
    */
    bool esta(string s) const;
    
    
    /** @brief Consulta la sessio amb identificador s
        
        \pre hi ha una sessio amb identificador s al conjunt
        \post retorna la sessio amb identificador s del conjunt
    */
    Sessio consultar_sessio(string s)const;
    
    /** @brief Retorna un conjunt amb tots els identificadors dels problemes de la sessio s
        
        \pre hi ha una sessio s al conjunt
        \post retorna un conjunt amb els identificadors dels problemes de la sessio s
    */
    set<string> conjunt_problemes(string s)const;
    
    /** @brief Retorna l'arbre de problemes de la sessio s
        
        \pre hi ha una sessio s al conjunt
        \post retorna l'arbre de la sessio s
    */
    BinTree<string> arbre_problemes(string s);
    
    /** @brief Consulta si el problema p esta a la sessio s
        
        \pre hi ha una sessio s al conjunt
        \post retorna cert si hi ha un element p a la sessio s o fals si no
    */
    bool esta(string s, string p)const;
    
    /** @brief Consulta el subarbre de a amb arrel p a la sessio s
        
        \pre  p es troba a l'arbre de la sessio s
        \post  retorna el subarbre de a amb arrel p de la sessio s
    */
    BinTree<string> arbre_problema(string s, string p);
    
    
    //Modificadores
    
    /** @brief Afegeix la sessio s al conjunt
        
        \pre no hi ha una sessio amb l'identificador de s al conjunt
        \post s'inserta la sessio s de manera ordenada per identificador al conjunt
    */
    void insertar_sessio(Sessio s);
    
    
    /** @brief Canvia la sessio amb el mateix identificador que s per la sessio s
        
        \pre hi ha una sessio amb al mateix identificador que s al conjunt
        \post es substitueix la sessio del conjunt amb el mateix identificador que s per s
    */
    void modificar_sessio(Sessio s);
    
    /** @brief Incrementa el nombre de problemes de la sessio s
        
        \pre hi ha una sessio s al conjunt
        \post incrementa el nombre de problemes de la sessio s
    */
    void incrementar_problemes(string s);
    
    /** @brief Omple c amb els elements de a de s
        
        \pre hi ha una sessio s al conjunt
        \post es troben a c els elements de a a s
    */
    void crear_conjunt(string s, const BinTree<string>& a, set<string>& c);
    
    //Lectura i escriptura
    
    /** @brief Llegeix n sessions del canal d'entrada
        
        \pre cert
        \post es llegeixen i s'introdueixen ordenadament n sessions del canal d'entrada
    */
    void llegir_sessions(int n);
    
    
    /** @brief Escriu les sessions del conjunt al canal de sortida
        
        \pre cert
        \post s'escriuen pel canal de sortida els atributs de totes les sessions del conjunt
    */
    void escriure_sessions()const;
    
    /** @brief Escriu una sessio s al canal de sortida
        
        \pre hi ha una sessio s al conjunt
        \post al canal de sortida s'escriuren  l'identificador, el nombre de problemes i els identificadors dels problemes en postordre
    */
    void escriure_sessio(string s)const;
   
    
};
#endif
    
    
