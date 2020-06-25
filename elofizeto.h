#ifndef ELOFIZETO_H
#define ELOFIZETO_H

#include <iostream>

#include "memtrace.h"
#include "csomopont.h"

using std::string;
///Heterogen kollekcio elem. Egyfajta csomopont.
class Elofizeto : public Csomopont{
private:
    Kapcsolas aktivhivas;
    bool foglalt;
public:
    //Konstruktorok
    Elofizeto():foglalt(false){}
    Elofizeto(string azon, string tipus):Csomopont(azon,tipus),foglalt(false){}
    //Destruktor
    ~Elofizeto(){ }
    ///Inline tagfüggvenyek: get-set
     void setAktivhivas(Kapcsolas& elem){ aktivhivas=elem;}
     Kapcsolas getAktivhivas(){return aktivhivas;}
     bool foglalt_e(){return foglalt;}

};
#endif // ELOFIZETO_H
