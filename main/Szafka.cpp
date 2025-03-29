/**
@file Szafka.cpp
@brief Plik zawieraj¹cy definicje klasy Szafka.
*/
#include "Szafka.h"

Szafka::Szafka()
{
    std::cout << "Utworzono pusta szafke!!!" << std::endl;
}

Szafka::Szafka(std::string a_nazwa_pliku): nazwa_pliku(a_nazwa_pliku)
{
   odczytaj_dane_z_pliku(nazwa_pliku, polka);
   std::cout << "Konstruktor Safki" << std::endl;
}

Szafka::~Szafka()
{
    std::cout << "Destruktor Szafki" << std::endl;
}

void Szafka::odczytaj_dane_z_pliku(const std::string& nazwa_pliku, std::vector<Nosnik*>& dane)
{
    std::ifstream plik(nazwa_pliku);
    if (!plik) {
        std::cout << "B³¹d podczas otwierania pliku." << std::endl;
    }
    std::string linia;
    while (std::getline(plik, linia)) 
    {
        size_t pozycja = 0;
        std::vector<std::string> pola;
        while ((pozycja = linia.find(". ")) != std::string::npos)
        {
            std::string pole = linia.substr(0, pozycja);
            pola.push_back(pole);
            linia.erase(0, pozycja + 2);
        }
        while ((pozycja = linia.find(", ")) != std::string::npos)
        {
            std::string pole = linia.substr(0, pozycja);
            pola.push_back(pole);
            linia.erase(0, pozycja + 2);
        }
        pola.push_back(linia);
        if (pola.size() != 7 && pola.size() != 8)
        {
            std::cout << "B³¹d w formacie danych." << std::endl;
            continue;
        }

        if (pola[3] == "album")
        {
            int a = std::stoi(pola[0]);
            float b = std::stof(pola[5]);
            Nosnik* p = new Nosnikaudio(a, pola[1], pola[2], pola[3], pola[4], b, pola[6]);

            dane.push_back(p);
        }
        else if (pola[3] == "film")
        {
            int a = std::stoi(pola[0]);
            float b = std::stof(pola[5]);
            Nosnik* p = new  Nosnikwideo(a, pola[1], pola[2], pola[3], pola[4], b, pola[6], pola[7]);

           dane.push_back(p);
        }
        else if (pola[3] == "ksiazka")
        {
            int a = std::stoi(pola[0]);
            int b = std::stoi(pola[5]);
            Nosnik* p = new Nosnikpapierowy(a, pola[1], pola[2], pola[3], pola[4], b, pola[6]);

            dane.push_back(p);
        }
        else
        {
            std::cout << "Sorki ale nie wiemy co to :(" << std::endl;
        }
    }
    plik.close();
}