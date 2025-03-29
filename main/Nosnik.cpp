/**
@file Nosnik.cpp
@brief Plik zawieraj¹cy definicje klasy Nosnik.
*/
#include "Nosnik.h"

Nosnik::Nosnik(int a_nr, std::string a_nazwa, std::string a_autor, std::string a_zawartosc, std::string a_data_premiery, std::string a_gatunek)
{
	nr = a_nr;
	nazwa = a_nazwa;
	autor = a_autor;
	zawartosc = a_zawartosc;
	data_premiery = a_data_premiery;
	gatunek = a_gatunek;
}

Nosnik::~Nosnik()
{
	std::cout << "Destruktor Klasy Nosnik" << std::endl;
}

void Nosnik::draw()
{
	std::cout << "Numer miejsca w bibliotece: " << nr
		<< ", Nazwa: " << nazwa
		<< ", autor: " << autor
		<< ", data premiery: " << data_premiery;
}

void Nosnik::zapisz(std::ofstream& os)
{
	os << nr << ". "
		<< nazwa << ", "
		<< autor << ", "
		<< zawartosc << ", "
		<< data_premiery << ", ";
}

int Nosnik::get_numer()
{
	return nr;
}

std::string Nosnik::get_autor()
{
	return autor;
}

std::string Nosnik::get_zawartosc()
{
	return zawartosc;
}

std::string Nosnik::get_data_premiery()
{
	return data_premiery;
}

std::string Nosnik::get_gatunek()
{
	return gatunek;
}

std::string Nosnik::get_nazwa()
{
	return nazwa;
}

void Nosnik::set_numer(int &a_numer)
{
	nr = a_numer;
}