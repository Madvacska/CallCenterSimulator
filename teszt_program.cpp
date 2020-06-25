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
    //Kezdeti adatok beolvas�sa


}
void test_2()
{
    //OUTPUT TEST
    //Adatok m�dos�t�sa ut�n megfelel�-e a filekimenet
}
void test_3()
{
    //K�RZETEK TEST
    //L�trehoz egy �j k�rzetet -ha m�g nem �r�k el a maxot
    //Kit�r�l egyet random
    //Ki�rjuk az aktu�lis list�t
}
void test_4()
{
    //EL�FIZET�K TEST
    //L�trehoz egy �j el�fizet�t
    //Kit�r�l egyet random
    //Ki�rjuk az aktu�lis list�t
}
void test_5()
{
    //H�V�S TEST
    //megpr�b�l h�v�sokat ind�tani
    //sikeres a test ha a h�v�sok adnak visszajelz�st azaz nem veszik el az algoritmus az �tkeres�sben
}
void test_6()
{
    //�ZENET TEST
    //megpr�b�l �zenetet k�ldeni egy fel�p�tett h�v�sban
}
void test_7()
{
    //HIV�S BEFEJEZ�SE TEST
    //megpr�b�lja lerakni a megl�v� h�v�sok valamelyik�t
}

///INNEN ki kell majd szedni a men�vez�rl�st - ez csak az elk�sz�t�st seg�ti
int main()
{
    //A testek nem teljesen aut�matikusak, a felhaszn�l�t�l v�rja mit szeretne tesztelni
    //A men�t pr�b�ltam �gy megcsin�lni, hogy minden funkci�t fedjen

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

