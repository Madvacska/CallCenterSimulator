#include <iostream>
#include <stdexcept>
#include <string>
#include <stdlib.h>

#include "memtrace.h"
#include "gtest_lite.h"
#include "rendszer.h"

void test_1()
{
    //INPUT TEST
    //Kezdeti adatok beolvasása


}
void test_2()
{
    //OUTPUT TEST
    //Adatok módosítása után megfelelõ-e a filekimenet
}
void test_3()
{
    //KÖRZETEK TEST
    //Létrehoz egy új körzetet -ha még nem érük el a maxot
    //Kitöröl egyet random
    //Kiírjuk az aktuális listát
}
void test_4()
{
    //ELÕFIZETÕK TEST
    //Létrehoz egy új elõfizetõt
    //Kitöröl egyet random
    //Kiírjuk az aktuális listát
}
void test_5()
{
    //HÍVÁS TEST
    //megpróbál hívásokat indítani
    //sikeres a test ha a hívások adnak visszajelzést azaz nem veszik el az algoritmus az útkeresésben
}
void test_6()
{
    //ÜZENET TEST
    //megpróbál üzenetet küldeni egy felépített hívásban
}
void test_7()
{
    //HIVÁS BEFEJEZÉSE TEST
    //megpróbálja lerakni a meglévõ hívások valamelyikét
}

///INNEN ki kell majd szedni a menüvezérlést - ez csak az elkészítést segíti
int main()
{
    //A testek nem teljesen autómatikusak, a felhasználótól várja mit szeretne tesztelni
    //A menüt próbáltam úgy megcsinálni, hogy minden funkciót fedjen

    Rendszer a;
    a.readData("korzetek_be.txt","kapcsolatok_be.txt");
    //a.readElofiz("elofizetok_be.txt");
    Elofizeto* e= new Elofizeto("2ALI","elofizeto");
    a.addElofizeto(e);
    a.writeData("korzetek_ki.txt","kapcsolatok_ki.txt","elofozetok_ki.txt");
    Elofizeto* e2= new Elofizeto("2ALI","elofizeto");
    Elofizeto* e3= new Elofizeto("1LLI","elofizeto");
    a.addElofizeto(e2);
    a.addElofizeto(e3);
    //delete e;
   // delete e; delete e2; delete e3;
    //a->listElofizeto(std::cout);
    //try{a->readData("korzetek_be.txt","kapcsolatok_be.txt");}
    //catch(std::out_of_range e){ std::cout<< e.what();}
    //a->listKorzetek(std::cout);


    int mPnt;
    do
    {
        std::cout << "Kerem adja meg melyik tesztet szeretne futtatni!\n"
                  << "0:KILEPES\n1:INPUT TEST\n2:OUTPUT TEST\n3:KORZETEK TEST\n4:ELOFIZETOK TEST\n5:HIVAS TEST\n6:UZENET TEST\n7:HIVAS BEFEJEZESE TEST"
                  <<std::endl;
        std::cin >> mPnt;
        system("cls");
        try
        {
            switch (mPnt)
            {
            case 1:
                test_1();
                break;
            case 2:
                test_2();
                break;
            case 3:
                test_3();
                break;
            case 4:
                test_3();
                break;
            case 5:
                test_3();
                break;
            case 6:
                test_3();
                break;
            case 7:
                test_3();
                break;
            default:
                if(mPnt!=0)std::cout <<"\nNincs ilyen szamu teszt!\n"<<std::endl;
                break;
            }

        }
        catch (std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
        catch(...)
        {
            std::cerr << "\nA test sikeretelen volt!\n" <<std::endl;
        }
        if(mPnt<=7&&mPnt>0)
            std::cout << "\nA test sikeres volt!\n"<< std::endl;
    }
    while(mPnt!=0);
    return 0;
}

