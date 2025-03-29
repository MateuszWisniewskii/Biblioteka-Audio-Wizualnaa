/**
@file Nosnikaudio.cpp
@brief Plik zawieraj¹cy definicje klasy Nosnikaudio.
*/
#include "Nosnikaudio.h"

Nosnikaudio::Nosnikaudio(int a_nr, std::string a_nazwa, std::string a_autor, std::string a_zawartosc, std::string a_data_premiery, float a_dlugosc_nagrania, std::string a_gatunek)
    :Nosnik::Nosnik(a_nr, a_nazwa, a_autor, a_zawartosc, a_data_premiery, a_gatunek)
{
    dlugosc_nagrania = a_dlugosc_nagrania;
}

Nosnikaudio::~Nosnikaudio()
{
    std::cout << "Destruktor Klasy Nosnikaudio" << std::endl;
}

void Nosnikaudio::draw()
{
    Nosnik::draw();
    std::cout << ", dlugosc nagrania: " << dlugosc_nagrania
        << ", gatunek muzyczny: " << gatunek
        << std::endl;
}

void Nosnikaudio::zapisz(std::ofstream& os)
{
   Nosnik::zapisz(os);
   os << std::fixed << std::setprecision(2) << dlugosc_nagrania << ", " 
       << gatunek << std::endl;
}

float Nosnikaudio::get_dlugosc_nagrania()
{
    return dlugosc_nagrania;
}