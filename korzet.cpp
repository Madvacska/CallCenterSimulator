#include "memtrace.h"
#include "korzet.h"

///Az elofozetok kilistazasara hasznalt fuggveny
void Korzet::listCspWhereElofiz(std::ostream& os){
    typename std::list<Csomopont*>::iterator it;
    string akt_type;
    for(it=alap.begin();it!=alap.end();it++)
    {
        akt_type=(*it)->getTipus();
        if(akt_type.compare("elofizeto")==0)
        {
            os<<"Elofizeto:\n"
              <<"Azonosito:\t"<<(dynamic_cast<Elofizeto*>(*it))->getAzonosito()<<"\n"
              <<"Foglalt?:\t"<<(dynamic_cast<Elofizeto*>(*it))->foglalt_e()<<"\n"
              <<"\n---------------------------------------------------------\n";
            if((dynamic_cast<Elofizeto*>(*it))->foglalt_e())
                os<<"Felado:\t"<<((dynamic_cast<Elofizeto*>(*it))->getAktivhivas()).getCel()<<"\n"
                  <<"Cel:\t"<<((dynamic_cast<Elofizeto*>(*it))->getAktivhivas()).getForras()<<"\n"
                  <<"\n---------------------------------------------------------\n";
        }
    }
}
void Korzet::listCspWhereElofiz(std::ofstream& of){
    typename std::list<Csomopont*>::iterator it;
    string akt_type;
    for(it=alap.begin();it!=alap.end();it++)
    {
        akt_type=(*it)->getTipus();
        if(akt_type.compare("elofizeto")==0)
        {
            of<<(dynamic_cast<Elofizeto*>(*it))->getAzonosito()<<"\n";
        }
    }
}
///Az kozpontok kilistazasara hasznalt fuggveny
void Korzet::listCspWhereKp(std::ostream& os){
    typename std::list<Csomopont*>::iterator it;
    string akt_type;
    for(it=alap.begin();it!=alap.end();it++)
    {
        akt_type=(*it)->getTipus();
        if(akt_type.compare("kozpont")==0)
        {
            os<< "Kozpont:\n"
              <<"Azonosito:\t"<<(dynamic_cast<Kozpont*>(*it))->getAzonosito()<<"\n"
              <<"Kapcsolotabla maximalis merete:\t"<<(dynamic_cast<Kozpont*>(*it))->getMaxKapcs()<<"\n"
              <<"Tartalma:\n"; (dynamic_cast<Kozpont*>(*it))->kiirKapcsTab(os);
            os<<"---------------------------------------------------------\n";
        }
    }
}
void Korzet::listCspWhereKp(std::ofstream& of){
    typename std::list<Csomopont*>::iterator it;
    string akt_type;
    for(it=alap.begin();it!=alap.end();it++)
    {
        akt_type=(*it)->getTipus();
        if(akt_type.compare("kozpont")==0)
        {
            of<<(dynamic_cast<Kozpont*>(*it))->getAzonosito();
            of<<"-";
        }
    }
}
///Visszaad egy csomopont elemet id alapjan
Csomopont* Korzet::findElofizetoByID(string ID){
    typename std::list<Csomopont*>::iterator it;
    string akt_id;
    for(it=alap.begin();it!=alap.end();it++)
    {
        akt_id=(*it)->getAzonosito();
        if(akt_id.compare(ID))
        {
            return *it;
        }
    }
    return NULL;
}
///A megadott helyre vonalat foglal. Azaz ha a szabad vonalak kozott van olyan, aminek az id-ja megegyezik a megadottal, akkor azt kitoroljuk onnan.
///Visszaadjuk, hogy sikerult-e.
bool Korzet::vonalFogalalas(string celCspId){
    typename std::list<Csomopont*>::iterator it;
    string akt_id;
    for(it=szabad.begin();it!=szabad.end();it++)
    {
        akt_id=(*it)->getAzonosito();
        if(akt_id.compare(celCspId))
        {
            szabad.remove(*it);
            return true;
        }
    }
    return false;
}
///A megadott helyre vonalat szabadit fel. Azaz ha az alap vonalak kozott van olyan, aminek az id-ja megegyezik a megadottal, akkor azt hozzaadjuk a szabad vonalakhoz.
///Visszaadjuk, hogy sikerult-e.
bool Korzet::vonalFelszabadit(string celCspId){
    typename std::list<Csomopont*>::iterator it;
    string akt_id;
    for(it=alap.begin();it!=alap.end();it++)
    {
        akt_id=(*it)->getAzonosito();
        if(akt_id.compare(celCspId))
        {
            szabad.push_back(*it);
            return true;
        }
    }
    return false;
}
///A korzethez hozzaad egy uj elofizetot, vagy egy kozpont kapcsolatot (ennel kikotes, hogy ne lepjuk tul a maximalis kapcsolatok szamat)
void Korzet::addKapcs(Csomopont* elem){
    string tipus= elem->getTipus();
    if(tipus.compare("kozpont")==0){
        if(alap.size()<max_kapcs_KP){
            alap.push_back(elem);
            szabad.push_back(elem);
        }
        else{
            delete elem;
            throw std::out_of_range("Elerte a maximalis kapcsolatok szamat");
        }
    }
    else{
        alap.push_back(elem);
        szabad.push_back(elem);
    }
}
 void Korzet::removeKapcs(string keresettID){
    Csomopont* keresett = findElofizetoByID(keresettID);
    if(keresett!=NULL)
    {
        vonalFogalalas(keresettID);
        typename std::list<Csomopont*>::iterator it;
        string akt_id;
        for(it=alap.begin();it!=alap.end();it++)
        {
            akt_id=(*it)->getAzonosito();
            if(akt_id.compare(keresettID))
            {
                alap.remove(*it);
            }
        }

    }
    delete keresett;
 }
