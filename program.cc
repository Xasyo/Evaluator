#include "Evaluator.hh"
#include <iostream>
using namespace std;

void processa_comanda(Evaluator& e, string s){
    if (s == "nuevo_problema"){
        string p;
        cin >> p;
        cout << "#nuevo_problema " << p << endl;
        e.nou_problema(p);
    }
    
    else if (s == "np"){
        string p;
        cin >> p;
        cout << "#np " << p << endl;
        e.nou_problema(p);
    }
    
    else if (s == "nueva_sesion"){
        string p;
        cin >> p;
        cout << "#nueva_sesion " << p << endl;
        e.nova_sessio(p);
    }
    
    else if (s == "ns"){
        string p;
        cin >> p;
        cout << "#ns " << p << endl;
        e.nova_sessio(p);
    }
    
    else if (s == "nuevo_curso"){
        cout << "#nuevo_curso" << endl;
        e.nou_curs();
    }
    
    else if (s == "nc"){
        cout << "#nc" << endl;
        e.nou_curs();
    }
    
    else if(s == "a"){
        string u;
        cin >> u;
        cout << "#a " << u << endl;
        e.alta_usuari(u);
        
    }
    
    else if (s == "alta_usuario"){
        string u;
        cin >> u;
        cout << "#alta_usuario " << u << endl;
        e.alta_usuari(u);
        
    }
    
    else if (s == "baja_usuario"){
        string u;
        cin >> u;
        cout << "#baja_usuario " << u << endl;
        e.baixa_usuari(u);
    }
    
    else if (s == "b"){
        string u;
        cin >> u;
        cout << "#b " << u << endl;
        e.baixa_usuari(u);
    }
    
    else if (s == "inscribir_curso"){
        string u;
        cin >> u;
        int c;
        cin >> c;
        cout << "#inscribir_curso " << u << " " << c << endl;
        e.inscriure_curs(u,c);
    }
    
    else if (s == "i"){
        string u;
        cin >> u;
        int c;
        cin >> c;
        cout << "#i " << u << " " << c << endl;
        e.inscriure_curs(u,c);
    }
    
    else if (s == "curso_usuario"){
        string u;
        cin >> u;
        cout << "#curso_usuario " << u << endl;
        e.curs_usuari(u);
    }
    
    else if (s == "cu"){
        string u;
        cin >> u;
        cout << "#cu " << u << endl;
        e.curs_usuari(u);
    }
    
    else if (s == "sesion_problema"){
        int c;
        cin >> c;
        string p;
        cin >> p;
        cout << "#sesion_problema " << c << " " << p << endl;
        e.sessio_problema(c, p);
    }
    
    else if (s == "sp"){
        int c;
        cin >> c;
        string p;
        cin >> p;
        cout << "#sp " << c << " " << p << endl;
        e.sessio_problema(c, p);
    }
    
    else if (s == "problemas_resueltos"){
        string u;
        cin >> u;
        cout << "#problemas_resueltos " << u << endl;
        e.problemes_resolts(u);
    }
    
    else if (s == "pr"){
        string u;
        cin >> u;
        cout << "#pr " << u << endl;
        e.problemes_resolts(u);
    }
    
    else if (s == "problemas_enviables"){
        string u;
        cin >> u;
        cout << "#problemas_enviables " << u << endl;
        e.problemes_enviables(u);
    }
    
    else if (s == "pe"){
        string u;
        cin >> u;
        cout << "#pe " << u << endl;
        e.problemes_enviables(u);
    }
    
    else if (s == "envio"){
        string u;
        cin >> u;
        string p;
        cin >> p;
        int r;
        cin >> r;
        cout << "#envio " << u << " " << p << " " << r << endl;
        e.enviament(u, p, r);
    }
    
    else if (s == "e"){
        string u;
        cin >> u;
        string p;
        cin >> p;
        int r;
        cin >> r;
        cout << "#e " << u << " " << p << " " << r << endl;
        e.enviament(u, p, r);
    }

    else if (s == "listar_problemas"){
        cout << "#listar_problemas" << endl;
        e.llistar_problemes();
    }
    
    else if (s == "lp"){
        cout << "#lp" << endl;
        e.llistar_problemes();
    }
    
    else if (s == "listar_sesiones"){
        cout << "#listar_sesiones" << endl;
        e.llistar_sessions();
    }
    
    else if (s == "ls"){
        cout << "#ls" << endl;
        e.llistar_sessions();
    }
    
    else if (s == "listar_cursos"){
        cout << "#listar_cursos" << endl;
        e.llistar_cursos();
    }
    
    else if (s == "lc"){
        cout << "#lc" << endl;
        e.llistar_cursos();
    }
    
    else if (s == "listar_usuarios"){
        cout << "#listar_usuarios" << endl;
        e.llistar_usuaris();
    }
    
    else if (s == "lu"){
        cout << "#lu" << endl;
        e.llistar_usuaris();
    }
    
    else if (s == "escribir_curso"){
        int c;
        cin >> c;
        cout << "#escribir_curso " << c << endl;
        e.escriure_curs(c);
    }
    
    else if (s == "ec"){
        int c;
        cin >> c;
        cout << "#ec " << c << endl;
        e.escriure_curs(c);
    }
    
    else if (s == "escribir_usuario"){
        string u;
        cin >> u;
        cout << "#escribir_usuario " << u << endl;
        e.escriure_usuari(u);
    }
    
    else if (s == "eu"){
        string u;
        cin >> u;
        cout << "#eu " << u << endl;
        e.escriure_usuari(u);
    }
    
    else if (s == "escribir_sesion"){
        string p;
        cin >> p;
        cout << "#escribir_sesion " << p << endl;
        e.escriure_sessio(p);
    }
    
    else if (s == "es"){
        string p;
        cin >> p;
        cout << "#es " << p << endl;
        e.escriure_sessio(p);
    }
    
    else if (s == "escribir_problema"){
        string p;
        cin >> p;
        cout << "#escribir_problema " << p << endl;
        e.escriure_problema(p);
    }
    
    else if (s == "ep"){
        string p;
        cin >> p;
        cout << "#ep " << p << endl;
        e.escriure_problema(p);
    }
}
    
int main(){
    Evaluator e;
    e.lectura_inicial_problemes();
    e.lectura_inicial_sessions();
    e.lectura_inicial_cursos();
    e.lectura_inicial_usuaris();
    string s;
    cin >> s;
    while (s != "fin"){
        processa_comanda(e,s);
        cin >> s;
    }
}
