/**
@file Nosnikpapierowy.cpp
@brief Plik zawieraj¹cy definicje klasy Nosnikpapierowy.
*/
#include "Nosnikpapierowy.h"

Nosnikpapierowy::Nosnikpapierowy(int a_nr, std::string a_nazwa, std::string a_autor, std::string a_zawartosc, std::string a_data_premiery, int a_liczba_stron, std::string a_gatunek)
    :Nosnik::Nosnik(a_nr, a_nazwa, a_autor, a_zawartosc, a_data_premiery, a_gatunek)
{
    liczba_stron = a_liczba_stron;
}

Nosnikpapierowy::~Nosnikpapierowy()
{
    std::cout << "Destruktor Klasy Nosnikpapierowy" << std::endl;
}

void Nosnikpapierowy::draw()
{
    Nosnik::draw();
    std::cout << ", liczba stron: " << liczba_stron
        << ", gatunek lektury: " << gatunek
        << std::endl;
}

void Nosnikpapierowy::zapisz(std::ofstream& os)
{
    Nosnik::zapisz(os);
    os << std::fixed << std::setprecision(2) << liczba_stron << ", " 
        << gatunek << std::endl;
}

int Nosnikpapierowy::get_liczba_stron()
{
    return liczba_stron;
}