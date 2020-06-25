#ifndef RENDSZER_H
#define RENDSZER_H
#include <string>
#include <fstream>

#include "memtrace.h"
#include "korzet.h"

using std::string;
///Legfelsõ osztály, ez fogja össze a teljes hálózatozt leíró elemeket. Valójában egy gráf. Függvényei végzik az elérhetõ funkciók megvalósítását.
class Rendszer{
private:
    unsigned int max_db; //feladatban meghatározott, fix érték: 9
    std::list<Korzet>korzetek;
public:
    //Konstruktor
    Rendszer():max_db(9){};
    //Destruktor
    ~Rendszer(){};
    //Tagfuggvenyek cpp-ben deffinialva
    void listKorzetek(std::ostream& os);
    void addKorzet(Korzet elem);
    void removeKorzet(string korzetID);
    string hivasIndit(string hivo, string hivott);
    void hivasTorlese(string hivo, string hivott);
    void uzen(string hivo, string hivott, string uzenet);
    void listElofizeto(std::ostream& os);
    void addElofizeto(Elofizeto* elem);
    void clearKorzetek();
    void removeElofizeto(string ID);
    void readData(const char* rendszer,const char* kapcsolatok);
    void readElofiz(const char* filename);
    void writeData(const char* rendszer,const char* kapcsolatok,const char* elofizetok);
    bool findPath(Kozpont * from, Kozpont* to);
};
#endif // RENDSZER_H
