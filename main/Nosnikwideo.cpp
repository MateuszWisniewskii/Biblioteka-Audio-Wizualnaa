/**
@file Nosniwideo.cpp
@brief Plik zawieraj¹cy definicje klasy Nosnikwideo.
*/
#include "Nosnikwideo.h"

Nosnikwideo::Nosnikwideo(int a_nr, std::string a_nazwa, std::string a_autor, std::string a_zawartosc, std::string a_data_premiery, float a_dlugosc_nagrania, std::string a_gatunek, std::string a_obsada)
    :Nosnik::Nosnik(a_nr, a_nazwa, a_autor, a_zawartosc, a_data_premiery, a_gatunek)
{
    dlugosc_nagrania = a_dlugosc_nagrania;
    if (a_obsada.length() > 0)
    {
        wpisz_obsade(obsada, a_obsada);
    }
    else
    {
        obsada[0] = "Nie podano obsady";
    }
}

Nosnikwideo::~Nosnikwideo()
{
    std::cout << "Destruktor Klasy Nosnikwideo" << std::endl;
}

void Nosnikwideo::draw()
{
    Nosnik::draw();
    std::cout << ", dlugosc nagrania: " << dlugosc_nagrania
        << ", gatunek filmowy: " << gatunek
        << ", obsada: ";
    if (!obsada.empty())
    {
        for (int i = 0; i < obsada.size(); ++i) {
            std::cout << obsada[i];

            if (i != obsada.size() - 1) {
                std::cout << ", ";
            }
        }
    }
    else
    {
        std::cout << "Nie podano obsady";
    }
        std::cout << std::endl;
}

void Nosnikwideo::zapisz(std::ofstream& os)
{
    Nosnik::zapisz(os);
       os << std::fixed << std::setprecision(2) << dlugosc_nagrania << ", "
         << gatunek << ", "
        << get_obsada() << std::endl;
}

float Nosnikwideo::get_dlugosc_nagrania()
{
    return dlugosc_nagrania;
}

std::string Nosnikwideo::get_obsada()
{
    std::string s_obsada;
    for (size_t i = 0; i < obsada.size(); ++i)
    {
        s_obsada += obsada[i];

        if (i != obsada.size() - 1)
        {
            s_obsada += "/ ";
        }
    }
    return s_obsada;
}

void Nosnikwideo::wpisz_obsade(std::vector<std::string>& vector_obsada, std::string a_obsada)
{
    size_t pozycja = 0;
    size_t end = a_obsada.find("/ ");

    while ((pozycja = a_obsada.find("/ ")) != std::string::npos)
    {
        std::string aktor = a_obsada.substr(0, pozycja);
        vector_obsada.push_back(aktor);
        
        a_obsada.erase(0, pozycja + 2);
    }

    vector_obsada.push_back(a_obsada);
}

