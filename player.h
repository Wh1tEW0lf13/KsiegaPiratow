#ifndef PLAYER_H
#define PLAYER_H
#pragma execution_character_set( "utf-8" )

class player
{
    public:
    int sila;
    int karma=0;
    int zrecznosc;
    int charyzma;
    int punkty_do_wydania=5;
    std::string imie;
    void nadanie_imienia()
    {
        std::cout<<"- ";
        getline(std::cin, imie);
    }
    void sila_kreator()
    {
        int punkty;
        std::cout<<"Podaj ile punktów chcesz wydać na siłę: "<<std::endl;
        std::cin>>punkty;
        while(punkty>3||punkty<0)
        {
            std::cout<<"Czytaj ze zrozumieniem. Maksymalnie 3 punkty na cechę! "<<std::endl;
            std::cin>>punkty;
        }
        sila=punkty;
        punkty_do_wydania-=punkty;
        switch(sila)
        {
        case 0:
        {
            std::cout<<"Wyglądasz mi na mięczaka. Gdybyś się siłował z patykiem, to na pewno byś przegrał."<<std::endl;
            sila = 20;
            break;
        }
        case 1:
        {
            std::cout<<"Nie wyglądasz mi na siłacza."<<std::endl;
            sila = 40;
            break;
        }
        case 2:
        {
            std::cout<<"Wyglądasz mi na silnego chłopa. Może byś się do czegoś przydał, gdybyś nie szedł na stryczek."<<std::endl;
            sila = 60;
            break;
        }
        case 3:
        {
            std::cout<<"Coś ty chłopie jadł, żeś taki duży? Ogr przy tobie to cielęcina."<<std::endl;
            sila = 80;
            break;
        }
        }
    }
    void zrecznosc_kreator()
    {
        std::cout<<"Podaj ile punktów chcesz wydać na zręczność: "<<std::endl;
        int punkty;
        std::cin>>punkty;
        while(punkty>3||punkty<0||punkty>punkty_do_wydania)
        {
            if(punkty>punkty_do_wydania&&(punkty<=3&&punkty>0))
            {
                std::cout<<"Zostało Ci do wydania tyle punktów: "<<punkty_do_wydania<<std::endl;
            }
            else
            {
                std::cout<<"Czytaj ze zrozumieniem. Maksymalnie 3 punkty na cechę! "<<std::endl;
            }
            std::cin>>punkty;
        }
        punkty_do_wydania-=punkty;
        zrecznosc=punkty;
        switch(zrecznosc)
        {
        case 0:
        {
            std::cout<<"Patrząc na ciebie, widzę osobę, która potyka się o własne nogi."<<std::endl;
            zrecznosc = 20;
            break;
        }
        case 1:
        {
            std::cout<<"Hmm... Wytrychem to ty na pewno nie umiesz się posługiwać."<<std::endl;
            zrecznosc = 40;
            break;
        }
        case 2:
        {
            std::cout<<"Wydaje mi się, że lepkie rączki to ty masz."<<std::endl;
            zrecznosc = 60;
            break;
        }
        case 3:
        {
            std::cout<<"Kurde, wyglądasz jakbyś umiał nawet paznokciem otworzyć zamek."<<std::endl;
            zrecznosc = 80;
            break;
        }
    }
    }
    void charyzma_kreator()
    {
        std::cout<<"Podaj ile punktów chcesz wydać na charyzmę: "<<std::endl;
        int punkty;
        std::cin>>punkty;
        while(punkty>3||punkty<0||punkty>punkty_do_wydania)
        {
            if(punkty>punkty_do_wydania&&(punkty<=3&&punkty>0))
            {
                std::cout<<"Zostało Ci do wydania tyle punktów: "<<punkty_do_wydania<<std::endl;
            }
            else
            {
                std::cout<<"Czytaj ze zrozumieniem. Maksymalnie 3 punkty na cechę! "<<std::endl;
            }
            std::cin>>punkty;
        }
        punkty_do_wydania-=punkty;
        charyzma=punkty;
        switch(charyzma)
        {
        case 0:
        {
            std::cout<<"Mam wrażenie, że jakbyś mówił, to nawet ściana by cię nie słuchała."<<std::endl;
            charyzma = 20;
            break;
        }
        case 1:
        {
            std::cout<<"Czy kiedykolwiek przekonałeś kogoś do swoich racji?"<<std::endl;
            charyzma = 40;
            break;
        }
        case 2:
        {
            std::cout<<"Mam wrażenie, że gadane to ty masz."<<std::endl;
            charyzma = 60;
            break;
        }
        case 3:
        {
            std::cout<<"Mam wrażenie, że byłbyś w stanie przekonać każdego, że czarny to biały."<<std::endl;
            charyzma = 80;
            break;
        }
        }
    }
};

#endif // PLAYER_H
