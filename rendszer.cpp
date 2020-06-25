#include "memtrace.h"
#include "rendszer.h"

///Kiirja a korzeteket es minden lenyeges tualajdonsagukat
void Rendszer::listKorzetek(std::ostream& os){
    os<<"A korzetek: ";
    typename std::list<Korzet>::iterator it= korzetek.begin();
    while(it!=korzetek.end())
    {
        os<<"\n---------------------------------------------------------\n"
          <<"KORZET azonosito: " <<it->getID()<<"\n"
          <<"A maximalisan kiepitheto vonalak szama: "<< it->getMaxKapcsKp()<<"\n"
          <<"---------------------------------------------------------\n"
          <<"A korzet SAJAT kozpontjanak adatai: \n";
        Kozpont* mk= it->getMainKp();
        os<<"Azonosito: "<<mk->getAzonosito()<<"\n"
          <<"Kapcsolotabla maximalis merete: "<<mk->getMaxKapcs()<<"\n"
          <<"Tartalma:\n"; mk->kiirKapcsTab(os);
        os<<"---------------------------------------------------------\n";
        os<<"\nKapcsolodo CSOMOPONTOK:\n";
        it->listCspWhereKp(os);
        it->listCspWhereElofiz(os);
        it++;
    }
}
///Ha nem ertuk el a maximalis meretet akkor hozzaadunk egy uj korzetet
void Rendszer::addKorzet(Korzet elem) {
     if(korzetek.size()<=max_db)
            korzetek.push_back(elem);
}
///Id alapjan toroljuk a korzetet a listabol
void Rendszer::removeKorzet(string korzetID) {
    typename std::list<Korzet>::iterator it= korzetek.begin();
    while((it!=korzetek.end())&&(it->getID().compare(korzetID)!=0))
        it++;
    korzetek.erase(it);
}
///Listazza a kapcsolt elofizetoket
void Rendszer::listElofizeto(std::ostream& os){
    os<<"A elofizetok: \n";
    typename std::list<Korzet>::iterator it= korzetek.begin();
    while(it!=korzetek.end())
    {
        os<<"Korzetazonosito: " <<it->getID()<<"\n"
          <<"Ebben a korzetben az alabbi elofizetok vannak: \n";
        it->listCspWhereElofiz(os);
        it++;
    }
}
void Rendszer::addElofizeto(Elofizeto* elem) {
    string elofizKorzId= elem->getAzonosito().substr(0,1);
    typename std::list<Korzet>::iterator it= korzetek.begin();
    while(it!=korzetek.end()&&(it->getID().compare(elofizKorzId)!=0))
        it++;
    it->addKapcs(dynamic_cast<Csomopont*>(elem));
}
void Rendszer::removeElofizeto(string ID) {
    typename std::list<Korzet>::iterator it= korzetek.begin();
    while(it!=korzetek.end())
    {
        it->removeKapcs(ID);
        it++;
    }
}
///Kitorli a korzetek minden elemet
void Rendszer::clearKorzetek(){
    typename std::list<Korzet>::iterator it= korzetek.begin();
    while(it!=korzetek.end())
    {
        korzetek.erase(it);
        it++;
    }
}
void Rendszer::hivasTorlese(string hivo, string hivott) {}
void Rendszer::uzen(string hivo, string hivott, string uzenet) {}
bool Rendszer::findPath(Kozpont * from, Kozpont* to){
    return false;
}

string Rendszer::hivasIndit(string hivo, string hivott){
    return "kesz";
}
///A harom parameterben kapott fileba kiirja azokat az adatokat, amiket be is tudunk olvasni
void Rendszer::writeData(const char* rendszer,const char* kapcsolatok,const char* elofizetok){
    std::ofstream f;
    f.open(rendszer);
    if(f.fail()){
        throw std::invalid_argument("Nincs ilyen file, vagy nem lehet megnyitni.\n");
    }
    else{
         typename std::list<Korzet>::iterator it= korzetek.begin();
         while(it!=korzetek.end())
            {
                f<<it->getID()<<" "
                  <<it->getMaxKapcsKp()<<" ";
                Kozpont* mk= it->getMainKp();
                f<<mk->getMaxKapcs()<<"\n";
                it++;
            }
    }
    f.close();

    f.open(kapcsolatok);
    if(f.fail()){
        throw std::invalid_argument("Nincs ilyen file, vagy nem lehet megnyitni.\n");
    }
    else{
         typename std::list<Korzet>::iterator it= korzetek.begin();
         while(it!=korzetek.end())
            {
                f<<it->getID()<<" ";
                it->listCspWhereKp(f);
                f<<"\n";
                it++;
            }
    }
    f.close();
    f.open(elofizetok);
    if(f.fail()){
        throw std::invalid_argument("Nincs ilyen file, vagy nem lehet megnyitni.\n");
    }
    else{
         typename std::list<Korzet>::iterator it= korzetek.begin();
         while(it!=korzetek.end())
            {
                it->listCspWhereElofiz(f);
                it++;
            }

    }
    f.close();
}
///Korzetek es kozpontokat tartalmazo filetokat olvas es alakitja ki belole amit kell elofizetok hozzaadasa nem itt tortenik
///Elso parameter: maga a rendszer; Masodik: a koztuk levo kapcsolatok
void Rendszer::readData(const char* rendszer,const char* kapcsolatok){
    std::ifstream f;
    f.open(rendszer);
    if(f.fail()){
        throw std::invalid_argument("Nincs ilyen file, vagy nem lehet megnyitni.\n");
    }
    else{
        while(f.peek()!=EOF){
            string id,kapcs_str; unsigned int maxkapcs, kapcstabmax;
            f>>id; f>>maxkapcs; f>>kapcstabmax;
            Kozpont mainn(id,"kozpont",kapcstabmax);
            addKorzet(Korzet(id,mainn,maxkapcs));
        }

    }
    f.close();
    f.open(kapcsolatok);
    if(f.fail()){
        throw std::invalid_argument("Nincs ilyen file, vagy nem lehet megnyitni.\n");
    }
    else{
       while(f.peek()!=EOF){
            string id,str;
            f>>id; f>>str;
            typename std::list<Korzet>::iterator it= korzetek.begin();
            typename std::list<Korzet>::iterator it2;
            while(it!=korzetek.end()&& (it->getID().compare(id)!=0))
                it++;
            int hatar= (it->getMaxKapcsKp())*2;
            Kozpont* elem;
            for(int i =0;(i<(int)str.size()&&i<hatar);i=i+2)
            {
                it2= korzetek.begin();
                string cmp_str(1,str.at(i));
                while(it2!=korzetek.end()&&(it2->getID().compare(cmp_str))!=0)
                    it2++;
                elem=it2->getMainKp();
                try{it->addKapcs(elem);}
                catch(std::out_of_range& e){std::cout<< e.what();}

            }
        }

    }
    f.close();
}
///Beolvassa es a megfelelo helyre menti az elofizetoket a parameterben megadott filebol
void Rendszer::readElofiz(const char* filename){
    std::ifstream f;
    f.open(filename);
    if(f.fail()){
        throw std::invalid_argument("Nincs ilyen file, vagy nem lehet megnyitni.\n");
    }
    else{
        while(f.peek()!=EOF){
            string id;
            f>>id;
            //Elofizeto* elem = new Elofizeto(id,"elofizeto");
            //addElofizeto(elem);

        }
    }
    f.close();
}
