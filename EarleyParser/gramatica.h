#ifndef GRAMATICA_H
#define GRAMATICA_H

#include <set>
#include <vector>
#include "produccion.h"

using namespace std;

class Gramatica {
public:

    Gramatica(){}

    Gramatica(const vector<Produccion>& producciones_p);

    Gramatica(const string& file);

    const set<char>* getTerminales() const {
        return &terminales;
    }

    const set<char>* getVariables() const {
        return &variables;
    }

    vector<Produccion> getProducciones() const {
        return producciones;
    }

    bool isVar(char carac) {
        return variables.count(carac);
    }

    bool isTer(char carac) {
        return terminales.count(carac);
    }

    void add(string prod);

    void remove(string prod);
private:
    vector<Produccion> producciones;
    set<char> terminales; //conjunto de terminales
    set<char> variables; //conjunto de variables

    bool is_upper(char caracter) {
        return caracter >= 65 && caracter <= 90;
    }

    void obtain_ter_var();
};

#endif /* GRAMATICA_H */

