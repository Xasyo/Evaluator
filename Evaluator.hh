#ifndef EVALUATOR_HH
#define EVALUATOR_HH
#include "Usuari.hh"
#include "Cjt_usuaris.hh"
#include "Problema.hh"
#include "Cjt_problemes.hh"
#include "Sessio.hh"
#include "Cjt_sessions.hh"
#include "Curs.hh"
#include "Cjt_cursos.hh"

using namespace std;


/** @class Evaluator
    @brief Representa la palataforama de problemes i cursos de probramacio Evaluator
*/
class Evaluator{
    
    //Tipus de modul: dades
    //Descripció del tipus: representa una plataforma de gestió de problemes i cursos de programació 
    
private:
    
    Cjt_usuaris usuaris;
    Cjt_cursos cursos;
    Cjt_sessions sessions;
    Cjt_problemes problemes;
    
public:
    
    //Constructora
    
    /** @brief Creadora per defecte
        
        \pre cert
        \post crea un evaluator buit
    */
    Evaluator();
    
    
    //Destructora
    
    /** @brief Destructora per defecte
        
        
    */
    ~Evaluator();
    
    //Modificadores
    
    /** @brief Es realitza una lectura inicial dels problemes de la plataforma
        
        \pre es troba al canal d'entrada el nombre p de problemes a llegir i p identificadors de problemes
        \post s'afegeixen al conjunt de problemes p problemes amb els identificadors introduits
    */
    void lectura_inicial_problemes();
    
    
    /** @brief Es realitza una lectura inicial de les sessions de la plataforma
        
        \pre  es troba al canal d'entrada el nombre de sessions s a llegir i s sessions amb el seu identificador i els identificadors dels problemes que la formen en preordre
        \post  s'afegeixen al conjunt de sessions les s sessions llegides del canal d'entrada
    */
    void lectura_inicial_sessions();
    
    
    /** @brief Es realitza una lectura inicial dels cursos de la plataforma
        
        \pre  es troba al canal d'entrada el nombre de cursos a llegir i per cada curs un nombre s de sessions que el formen i s identificadors de sessions
        \post s'afegeixen al conjunt de cursos els c cursos llegits del canal d'entrada
    */
    void lectura_inicial_cursos();
    
    
    /** @brief Es realitza una lectura inicial dels usuaris de la plataforma
        
        \pre es troba al canal d'entrada un nombre m d'usuaris a llegir i m identificadors d'usuaris
        \post s'afegeixen al conjunt d'usuaris els m usuaris llegits del canal d'entrada
    */
    void lectura_inicial_usuaris();
    
    
    /** @brief S'afegeix un nou problema p a la plataforma
        
        \pre cert
        \post afegeix un nou problema amb identificador p al conjunt de problemes i imprimeix el nombre de problemes, si ja hi ha un problema amb identificador p s'imprimeix un missatge d'error
    */
    void nou_problema(string p);
    
    
    /** @brief S'afegeix un nou curs a la plataforma
        
        \pre es troba al canal d'entrada un enter S que indica el nombre de sessions que conte el curs i S identificadors de sessions
        \post afegeix un nou curs amb identificador N+1 i amb les sessions dels identificadors introduits, si hi ha interseccio de problemes no es fa el curs i s'imprimeix un missatge d'error
    */
    void nou_curs();
    
    
    /** @brief S'afegeix una nova sessio s a la plataforma
        
        \pre cert
        \post afegeix una nova sessio amb identificador s al conjunt de sessions si imprimeix el nombre de sessions, si ja hi ha una sessio amb identificador s s'imprimeix un missatge d'error
    */
    void nova_sessio(string s);
    
    
    /** @brief S'afegeix un nou usuari u a la plataforma
        
        \pre cert
        \post afegeix un usuari amb identificador u al conjunt d'usuaris i s'imprimeix el nombre d'usuaris, si ja hi ha un usuari amb s'imprimeix amb un missatge d'error
    */
    void alta_usuari(string u);
    
    
    /** @brief S'elimina l'usuari u de la plataforma
        
        \pre cert
        \post treu l'usuari amb identificador u del conjunt d'usuaris i s'imprimeix el nombre d'usuaris, si no hi ha cap usuari amb l'identificador u s'imprimeix un misstge d'error
    */
    void baixa_usuari(string u);
    
    
    /** @brief S'inscriu a l'usuari u al curs c
        
        \pre cert
        \post inscriu a l'usuari amb identificador u al curs amb identificador c i s'imprimeix el nombre d'usuaris inscrits al curs c, si no existeixen o si l'usuari ja esta inscrit en un altre curs no acabat s'imprimeix un missatge d'error
    */
    void inscriure_curs(string u, int c);
    
    /** @brief Funcio d'inmersio per inscriure curs
        
        \pre cert
        \post actualitza els problemes disponibles de u
    */
    void i_inscriure(Usuari& u, const BinTree<string>& a);
    
    
    /** @brief Es consulta el curs en el que esta inscrit l'usuari u
        
        \pre cert
        \post s'imprimeix el curs de l'usuari amb identificador u o un 0 si no esta inscrit en cap curs, si no existeix l'usuari s'imprimeix un misstge d'error
    */
    void curs_usuari(string u) const;
    
    
    /** @brief Es consulta la sessio en la que es troba el problema p al curs c
        
        \pre cert
        \post imprimeix la sessio en la que es troba el problema amb identificador p en el curs amb identificador c, si no existeixen s'imprimeix un missatge d'error
    */
    void sessio_problema(int c, string p)const;
    
    
    /** @brief S'escriuen al canal de sortida els problemes resolts per l'usuari u
        
        \pre cert
        \post es llisten per ordre creixent d'identificador els problemes resolts per l'usuari amb l'identificador u els enviaments, si no hi ha cap usuari amb identificador u s'imprimeix un missatge d'error
    */
    void problemes_resolts(string u) const;
    
    
    /** @brief S'escriuen al canal de sortida els problemes enviables per l'usuari u
        
        \pre cert
        \post es llisten els identificadors dels problemes disponibles per l'usuari amb identificador u en el curs en el que esta inscrit, a mes s'imprimeixen el nombre d'enviaments a cada problema, si no hi ha cap usuari amb identificador u al conjunt d'usuaris s'imprimeix un missatge d'error
    */
    void problemes_enviables(string u) const;
    
    
    /** @brief Es realitza un enviament de l'usuari u al problema p amb resultat r
        
        \pre cert
        \post s'actualitza tota la informacio referent a l'enviament d'un usuari amb identificador u a un problema amb identificador p amb resultat r
    */
    //void enviament(string u, string p, int r);
    
    
    /** @brief Es llisten els problemes de la plataforma al canal de sortida
        
        \pre cert
        \post es llisten pel canal de sortida els atributs dels problemes del conjunt de problemes de manera ordenada pel seu ratio i identificador
    */
    void llistar_problemes() const;
    
    
    /** @brief Es llisten les sessions de la plataforma al canal de sortida
        
        \pre cert
        \post es llisten pel canal de sortida els atributs de les sessions del conjunt de sessions de manera ordenada i amb els problemes de cada sessio en estructura de postordre
    */
    void llistar_sessions()const;
    
    
    /** @brief Es llisten els cursos de la plataforma al canal de sortida
        
        \pre cert
        \post s llisten pel canal de sortida els atributs dels cursos del conjunt de cursos de manera ordenada per l'identificador
    */
    void llistar_cursos() const;
    
    
    /** @brief Es llisten els usuaris de la plataforma al canal de sortida
        
        \pre cert
        \post es llisten pel canal de sortida els atributs del usuaris del conjunt d'usuaris de manera ordenada pe l'identificador
    */
    void llistar_usuaris() const;
    

    /** @brief Es consulta si l'usuari u ha completat el curs c
        
        \pre cert
        \post retorna cert si l'usuari u ha completat el curs c o fals si no
    */
    bool completat_curs(const Curs& c, const Usuari& u);
    
    
    /** @brief Es consulta si l'usuari u ha completat la sessio s
        
        \pre cert
        \post retorna cert si l'usuari u ha completat la sessio s o fals si no
    */
    bool completada_sessio(const Sessio& s, const Usuari& u);
    
    
    /** @brief S'escriu al canal de sortida el problema p
        
        \pre cert
        \post escriu els atributs del problema amb identificador p del conjunt de problemes, si no esta s'imprimeix un missatge d'error
    */
    void escriure_problema(string p);
    
    
    /** @brief S'escriu al canal de sortida el curs c
        
        \pre cert
        \post escriu els atributs del curs amb identificador c del conjunt de cursos, si no esta s'imprimeix un missatge d'error
    */
    void escriure_curs(int c);
    
    
    /** @brief S'escriu al canal de sortida l'usuari u
        
        \pre cert
        \post escriu els atributs de l'usuari amb identificador u del conjunt d'usuaris, si no esta s'imprimeix un missatge d'error
    */
    void escriure_usuari(string u);
    
    
    /** @brief S'escriu al canal de sortida la sessio s
        
        \pre cert
        \post escriu els atributs de la sessio amb identificador s del conjunt de sessions, si no esta s'imprimeix un missatge d'error
    */
    void escriure_sessio(string s)const;
    
    /** @brief Es realitza un enviament de l'usuari amb identificador u, al problema p amb resultat r
        
        \pre u i p existeixen r = 1 si ha resolt el problema o r = 0 si no l'ha resolt
        \post actualitza tota la informacio relacionada amb l'enviament
    */
    void enviament(string u, string p, int r);
    
    /** @brief Es posen disponibles els problemes del BinTree per l'usuari tenint en compte que ha fet un enviament correcte al problema de l'arrel
        
        \pre cert
        \post la informacio de l'usuari ha quedat actualitzada
    */
    void disponibilitzar(Usuari& usuari, const BinTree<string>& a);
    
};
#endif
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
