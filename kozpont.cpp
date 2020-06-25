#include "memtrace.h"
#include "kozpont.h"

///Visszaadja, hogy van-e meg hely a kapcsolotablaban
bool Kozpont::vaneHely(){
    return kapcs_tab.size()<kapcs_max;
}
///Ha van hely, hozzaadja a parameterben megadott elemet a kapcsolotablahoz
void Kozpont::addKapcs(Kapcsolas elem){
    if(this->vaneHely())
        kapcs_tab.push_back(elem);
}
///Visszaad egy Kapcsolas elemet a parameterben megadott feladoID szerint. Ha nincs ilyen hibat dob
Kapcsolas Kozpont::getKapcsByID(const string ID){
    typename std::list<Kapcsolas>::iterator it;
    Kapcsolas seged;
    for(it=kapcs_tab.begin();it!=kapcs_tab.end();it++)
    {
        if(it->getID().compare(ID)==0)
            return *it;
    }
    throw std::invalid_argument("Nincs ilyen elem");
}
///A parameterben megadott feladoID alapjan kitorli az elemet a kapcsolotablabol
void Kozpont::removeKapcs(const string ID){
    typename std::list<Kapcsolas>::iterator it= kapcs_tab.begin();
    while((it!=kapcs_tab.end())&&(it->getID().compare(ID)!=0))
        it++;
    kapcs_tab.erase(it);
}
///Kapcsolotabla kiiro fuggveny
void Kozpont::kiirKapcsTab(std::ostream& os){
    typename std::list<Kapcsolas>::iterator it;
    for(it=kapcs_tab.begin();it!=kapcs_tab.end();++it)
        os <<"\tHivo: \t"<< it->getForras()<<"\tHivott: \t"<<it->getCel();
}
