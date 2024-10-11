#include <cstdio>
#include <windows.h>
#include <iostream>
#include <fstream>
#pragma execution_character_set( "utf-8" )
#include <time.h>
#include "player.h"

void wypisywanie(std::string tekst)
{
    for(int i = 0; i<tekst.length();i++)
    {
        Sleep(30);
        std::cout<<tekst[i];
    }
}

void odczyt(std::ifstream& plik)
{
    std::string tekst;
    while(!plik.eof())
    {
        getline(plik,tekst);
        wypisywanie(tekst);
        std::cout<<std::endl;
    }
    plik.close();
}

bool rzut(int umiejetnosc)
{
    srand(time(NULL));
    for(int i = 0; i<3; i++)
    {
        wypisywanie("(Naciśnij enter, by kontynuować)");
        std::cin;
        std::cin.ignore();
        int liczba = rand()%100+1;
        if(liczba>=98)
            return false;
        else if(liczba>umiejetnosc)
        {
            if(i<2)
            {
            wypisywanie("Nie udało się, spróbuj jeszcze raz.");
            }
            std::cout<<std::endl;
            continue;
        }
        else if(liczba<=umiejetnosc)
            return true;
        }
    return false;
}

void opuszczanie_statku(player& bohater, bool& wypuszczenie, bool& otworzenie_celi)
{
    int x;
    std::ifstream poklad("Epizod_1/poklad.txt");
    odczyt(poklad);
    std::cin>>x;
    std::cin.ignore();
    while(x<1||x>2)
    {
        wypisywanie("Wybierz 1 albo 2!");
        std::cout<<std::endl;
        std::cin>>x;
        std::cin.ignore();
    }
    if(x==1)
    {
        bohater.karma--;
        wypisywanie("Zrzucasz lampę. Ogień zaczyna się dość szybko rozprzestrzeniać, więc czym prędzej udajesz się w stronę łodzi. ");
            if(wypuszczenie)
            {
                std::ifstream odplyniencie("Epizod_1/Opuszczenie_statku/opuszczenie_statku1.txt");
                odczyt(odplyniencie);
            }
            else
            {
                std::ifstream odplyniencie("Epizod_1/Opuszczenie_statku/opuszczenie_statku2.txt");
                odczyt(odplyniencie);
            }
        }
        else
        {
            bohater.karma++;
            wypisywanie("Odrzucasz myśl o spaleniu statku i idziesz w stronę łodzi. ");
            if(wypuszczenie)
            {
                std::ifstream odplyniencie("Epizod_1/Opuszczenie_statku/opuszczenie_statku3.txt");
                odczyt(odplyniencie);
            }
            else
            {
                std::ifstream odplyniencie("Epizod_1/Opuszczenie_statku/opuszczenie_statku4.txt");
                odczyt(odplyniencie);
            }
        }
}

void opuszczenie_kajuty(player& bohater, bool& wypuszczenie, bool& otworzenie_celi)
{
    int x;
    if(otworzenie_celi)
    {
        opuszczanie_statku(bohater,wypuszczenie,otworzenie_celi);
    }
    else
    {
        if(wypuszczenie)
        {
            std::ifstream poklad("Epizod_1/poklad2.txt");
            odczyt(poklad);
            std::cin>>x;
            std::cin.ignore();
            while(x<1||x>2)
            {
                wypisywanie("Wybierz 1 albo 2!");
                std::cout<<std::endl;
                std::cin>>x;
                std::cin.ignore();
            }
            if(x==1)
            {
                wypisywanie("Mówisz strażnikowi, że chcesz, by ten wypuścił Starego Wilka Morskiego.");
                std::cout<<std::endl;
                wypisywanie("On mówi, że musisz się postarać, by go przekonać.");
                std::cout<<std::endl;
                wypisywanie("1. Przekonaj go siłą.");
                std::cout<<std::endl;
                wypisywanie("2. Namów go, by dał ci klucze.");
                std::cin>>x;
                std::cin.ignore();
                while(x<1||x>2)
                {
                    wypisywanie("Wybierz 1 albo 2!");
                    std::cout<<std::endl;
                    std::cin>>x;
                    std::cin.ignore();
                }
                if(x==1)
                {
                    if(rzut(bohater.sila))
                    {
                        wypisywanie("Powalasz strażnika i odbierasz mu klucze. Otwierasz celę Wilkowi i mówisz, by udał się w stronę łodzi,");
                        std::cout<<std::endl;
                        wypisywanie("ponieważ ty musisz coś zrobić. Starszy mężczyzna wychodzi, a ty zamykasz strażnika w celi i udajesz się w strone pokładu.");
                        opuszczanie_statku(bohater,wypuszczenie,otworzenie_celi);
                    }
                    else
                    {
                        wypisywanie("Strażnik powala cię i mówi, żebyś uciekał póki możesz, inaczej cię zabije.");
                        std::cout<<std::endl;
                        wypisywanie("Musisz skorzystać z jego propozycji i udajesz się w stronę wyjścia.");
                        wypuszczenie=false;
                        opuszczanie_statku(bohater,wypuszczenie,otworzenie_celi);
                    }
                }
                else
                    if(rzut(bohater.charyzma))
                    {
                        wypisywanie("Przekonujesz strażnika, wykorzystując do tego swoje umiejętności preswazyjne. Łowca daje ci klucz i wypuszczasz Wilka.");
                        std::cout<<std::endl;
                        wypisywanie("Każesz udać mu się w stronę łodzi. Gdy wyszedł, wpychasz strażnika do celi i go zamykasz,");
                        wypisywanie(" po czym udajesz się w stronę pokładu.");
                        opuszczanie_statku(bohater,wypuszczenie,otworzenie_celi);
                    }
                    else
                    {
                        wypisywanie("Jedyne co ci się udaje, to wkurzyć strażnika. Mówi, że jeżeli nie znikniesz mu zaraz z oczu, to cię zabije.");
                        std::cout<<std::endl;
                        wypisywanie("Musisz skorzystać z jego propozycji i udajesz się w stronę wyjścia.");
                        wypuszczenie=false;
                        opuszczanie_statku(bohater,wypuszczenie,otworzenie_celi);
                    }
            }
            else
            {
                wypisywanie("Oddajesz dokumenty strażnikowi, i udajesz się w stronę wyjścia.");
                std::cout<<std::endl;
                opuszczanie_statku(bohater,wypuszczenie,otworzenie_celi);
            }

        }
        else
        {

            wypisywanie("Oddajesz dokumenty strażnikowi, i udajesz się w stronę wyjścia.");
            std::cout<<std::endl;
            opuszczanie_statku(bohater,wypuszczenie,otworzenie_celi);
        }
    }
}

void odzyskanie(player& bohater, bool& wypuszczenie, bool& otworzenie_celi)
{
    std::ifstream Kajuta("Epizod_1/Kajuta.txt");
    odczyt(Kajuta);
    int x;
    std::cin>>x;
    std::cin.ignore();
    while(x<1||x>2)
    {
        wypisywanie("Wybierz 1 albo 2!");
        std::cout<<std::endl;
        std::cin>>x;
        std::cin.ignore();
    }
    if(x==1)
    {
        bohater.karma++;
        wypisywanie("Dochodzisz do wniosku, że nie ma sensu się mścić, bo ci to w żaden sposób nie pomoże.");
        std::cout<<std::endl;
    }
    else
    {
        bohater.karma--;
        wypisywanie("Po głębszym zastanowieniu, bierzesz szablę kapitana i z całej siły wbijasz miecz w plecy przywódcy łowców.");
        std::cout<<std::endl;
    }
    opuszczenie_kajuty(bohater,wypuszczenie,otworzenie_celi);
}

void otwarcie_celi(player& bohater, bool& wypuszczenie,int umiejetnosc,bool& otworzenie_celi)
{
    wypisywanie("Udaje Ci się otworzyć celę. Współwięzień prosi, żebyś pomógł mu się wydostać. Co robisz? ");
    std::cout<<std::endl;
    wypisywanie("1. Zgadzasz się.");
    std::cout<<std::endl;
    wypisywanie("2. Odmawiasz.");
    int x;
    std::cin>>x;
    std::cin.ignore();
    while(x<1||x>2)
    {
        wypisywanie("Wybierz 1 albo 2!");
        std::cout<<std::endl;
        std::cin>>x;
        std::cin.ignore();
    }
    if(x==1)
    {
        bohater.karma++;
        std::ifstream zgoda("Epizod_1/Otworzenie_celi/Zgoda.txt");
        odczyt(zgoda);
        if(rzut(umiejetnosc))
        {
            std::ifstream klucze("Epizod_1/Otworzenie_celi/Ukradniecie_kluczy.txt");
            odczyt(klucze);
            wypuszczenie=true;
            otworzenie_celi=true;
            odzyskanie(bohater,wypuszczenie,otworzenie_celi);
        }
        else
        {
            std::ifstream klucze("Epizod_1/Otworzenie_celi/Przylapanie.txt");
            odczyt(klucze);
        }
    }
    else
    {
        wypuszczenie=false;
        bohater.karma--;
        std::ifstream odmowienie("Epizod_1/Otworzenie_celi/Odmowienie.txt");
        odczyt(odmowienie);
        odzyskanie(bohater,wypuszczenie,otworzenie_celi);
    }
}

int main()
{
    SetConsoleOutputCP( 65001 );
    int x;
    bool wypuszczenie=true,otworzenie_celi;
    std::ifstream Prolog ("Prolog/Sen.txt");
    odczyt(Prolog);
    std::cin>>x;
    std::cin.ignore();
    while(x>3|| x<1)
    {
        wypisywanie("Podaj liczby z zakresu 1 do 3!");
        std::cin>>x;
        std::cin.ignore();
    }
    switch(x)
    {
    case 1:
        {
            std::ifstream Prolog ("Prolog/Poddanie.txt");
            odczyt(Prolog);
            break;
        }
    case 2:
        {
           std::ifstream Prolog ("Prolog/Walka.txt");
            odczyt(Prolog);
            break;
        }
    case 3:
        {
           std::ifstream Prolog ("Prolog/Ucieczka.txt");
            odczyt(Prolog);
            break;
        }
    }
    std::ifstream Kreator("Kreator_postaci/Imie.txt");
    odczyt(Kreator);
    player bohater;
    bohater.nadanie_imienia();
    std::ifstream Sila("Kreator_postaci/Sila/main.txt");
    odczyt(Sila);
    MessageBoxW(nullptr, (LPCWSTR)L"Teraz wchodzisz do kreatora postaci. Masz 5 punktów do wydania ogółem. Będziesz musiał je wydać na siłę, zręczność i charyzmę. Wydaj je mądrze. Możesz maksymalnie wydać 3 punkty na jedną cechę. ", (LPCWSTR)L"Kreator postaci", MB_OK);
    bohater.sila_kreator();
    bohater.zrecznosc_kreator();
    bohater.charyzma_kreator();
    std::ifstream dzien("Epizod_1/dzien_jak_codzien.txt");
    odczyt(dzien);
    std::cin>>x;
    std::cin.ignore();
    while(x>3|| x<1)
    {
        wypisywanie("Podaj liczby z zakresu 1 do 3!");
        std::cin>>x;
        std::cin.ignore();
    }
    switch(x)
    {
    case 1:
        {
            if(rzut(bohater.zrecznosc))
            {
                bohater.karma++;
                otwarcie_celi(bohater,wypuszczenie,bohater.zrecznosc,otworzenie_celi);
            }
            else
            {
                otworzenie_celi=false;
                std::ifstream zlamanie("Epizod_1/Otworzenie_celi/Zlamanie_wytrychu.txt");
                odczyt(zlamanie);
                std::ifstream kolejny("Epizod_1/kolejny_dzien/Nastepny_dzien_bez.txt");
                odczyt(kolejny);
                odzyskanie(bohater,wypuszczenie,otworzenie_celi);
            }
            break;
        }
    case 2:
        {
            otworzenie_celi=false;
            std::ifstream pasywka("Epizod_1/Otworzenie_celi/Pasywka.txt");
            odczyt(pasywka);
            std::ifstream kolejny("Epizod_1/kolejny_dzien/Nastepny_dzien_bez.txt");
            odczyt(kolejny);
            odzyskanie(bohater,wypuszczenie,otworzenie_celi);
            break;
        }

    case 3:
        {
            otworzenie_celi=false;
            wypuszczenie=false;
            std::ifstream sprzedanie("Epizod_1/Otworzenie_celi/sprzedanie.txt");
            odczyt(sprzedanie);
            odzyskanie(bohater,wypuszczenie,otworzenie_celi);
            break;
        }
    }
    system("pause");
}
