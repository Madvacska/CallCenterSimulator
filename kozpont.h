#ifndef KOZPONT_H
#define KOZPONT_H

#include <list>
#include <stdexcept>
#include <iostream>

#include "memtrace.h"
#include "csomopont.h"
using std::string;
///Heterogen kollekcio elem. Egyfajta csomopont.
class Kozpont: public Csomopont{
private:
    unsigned int kapcs_max;
    std::list<Kapcsolas> kapcs_tab;
public:
    //Konstruktorok
    Kozpont(){}
    Kozpont(string azon,string tipus, int kmax):Csomopont(azon,tipus),kapcs_max(kmax){}
    //Destruktor
    ~Kozpont(){}
    ///Inline tagfuggvenyek
    int getMaxKapcs(){return kapcs_max;}
    ///Tagfuggvenyek: cpp-ben deffinialva
    bool vaneHely();
    void addKapcs(Kapcsolas elem);
    Kapcsolas getKapcsByID(const string ID);
    void removeKapcs(const string ID);
    void kiirKapcsTab(std::ostream& os);


};
#endif // KOZPONT_H

