#ifndef CSOMOPONT_H
#define CSOMOPONT_H
#include <string>

#include "memtrace.h"
#include "kapcsolas.h"

using std::string;
///Heterogen kollekcio alaposztalya
class Csomopont{
protected:
    string azonosito;
    string tipus;
public:
    //Konstruktorok
    Csomopont(){}
    Csomopont(string azon, string tip):azonosito(azon),tipus(tip){}
    //Egyenloseg operator
    Csomopont& operator=(const Csomopont& rhs){
        if(this!=&rhs){
            azonosito=rhs.azonosito;
            tipus= rhs.tipus;
        }
        return *this;
    }
    //Masolo konstruktor
    Csomopont(const Csomopont& elem){*this=elem;}
    //virtual Destruktor
    virtual ~Csomopont(){}
    //Inline tagfuggvenyek: get-set
    string getAzonosito(){return azonosito;}
    string getTipus(){return tipus;}

};
#endif // CSOMOPONT_H

