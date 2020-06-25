#ifndef KAPCSOLAS_H
#define KAPCSOLAS_H
#include <string>
#include <iostream>

#include "memtrace.h"

using std::string;
///Kulonallo osztaly. Sikeres hivas eseten tipuskent hasznaljuk.
class Kapcsolas{
private:
    string feladoID;
    string forras;
    string cel;
public:
    //Konstruktorok
    Kapcsolas(){}
    Kapcsolas(string ID,string from, string to):feladoID(ID),forras(from),cel(to){}
    //Egyenloseg operator
    Kapcsolas& operator=(const Kapcsolas& rhs){
        if(this != &rhs){
            feladoID=rhs.feladoID;
            forras=rhs.forras;
            cel=rhs.cel;
        }
        return *this;
    }
    //Masolo konstruktor
    Kapcsolas(const Kapcsolas& elem){
        *this= elem;
    }
    //Destruktor
    ~Kapcsolas(){}
    //Inline tagfuggvenyek: csak get az adattagok nem modosithatok egyesevel
    string getCel(){return cel;}
    string getForras(){return forras;}
    string getID(){return feladoID;}
};
#endif // KAPCSOLAS_H
