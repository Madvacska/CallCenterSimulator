#ifndef KORZET_H
#define KORZET_H
#include <iostream>
#include <fstream>
#include <stdexcept>

#include "memtrace.h"
#include "csomopont.h"
#include "kozpont.h"
#include "elofizeto.h"

using std::string;
///A csomopontokat egysegbe fogo osztaly. A teljes rendszer ezekbol epul fel.
class Korzet{
private:
    string korzetID;
    Kozpont mainKozpont;
    unsigned int max_kapcs_KP;
    std::list<Csomopont*> alap;
    std::list<Csomopont*> szabad;
public:
    //Konstruktorok
    Korzet(){}
    Korzet(string id, Kozpont mainn,int maxKp):korzetID(id),mainKozpont(mainn),max_kapcs_KP(maxKp){}
    //Egyenloseg operator
    Korzet& operator=(const Korzet& rhs){
        if(this!=&rhs)
        {
            korzetID=rhs.korzetID;
            mainKozpont= rhs.mainKozpont;
            max_kapcs_KP=rhs.max_kapcs_KP;
            alap=rhs.alap;
            szabad=rhs.szabad;
        }
        return *this;
    }
    //Masolo konstruktor
    Korzet(const Korzet& elem){ *this=elem; }
    //Destruktor
    ~Korzet(){}
    //Inline tagfuggvenyek
    string getID(){return korzetID;}
    int getMaxKapcsKp(){return max_kapcs_KP;}
    Kozpont* getMainKp() {return &mainKozpont;}
    //Tegfüggvenyek: deffinicio a cppben
    void listCspWhereElofiz( std::ostream& os);
    void listCspWhereElofiz(std::ofstream& of);
    void listCspWhereKp( std::ostream& os);
    void listCspWhereKp(std::ofstream& of);
    Csomopont* findElofizetoByID(string ID);
    bool vonalFogalalas(string celCspId);
    bool vonalFelszabadit(string celCspId);
    void addKapcs(Csomopont* elem);
    void removeKapcs(string keresettID);
};
#endif // KORZET_H

