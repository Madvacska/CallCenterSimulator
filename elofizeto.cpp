#include "elofizeto.h"
//Kiiro operator
std::ostream& operator<<(std::ostream& os, Elofizeto& val){
    os << "Azonosito: " <<val.getAzonosito()<<"\n"
       <<"Fogalatsag: " <<val.foglalt_e()<<"\n";
    if(val.foglalt_e()){
        os<<"A hivo: "<<val.getAktivhivas().getForras()
          <<"A hivott: "<<val.getAktivhivas().getCel();
    }
    return os;
}
