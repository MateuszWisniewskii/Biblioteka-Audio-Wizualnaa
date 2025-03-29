/**
@file Biblioteka.h
@brief Plik nag��wkowy, zawieraj�cy deklaracj� klasy Biblioteka.
*/
#ifndef BIBLIOTEKA_H
#define BIBLIOTEKA_H
#include <iostream>
#include <cstddef>
#include <string>
#include "Szafka.h"
#include <iomanip>

/**
@class Biblioteka
@brief Klasa reprezentuj�ca bibliotek�.
Klasa Biblioteka dziedziczy po klasie Szafka i zawiera
metody umo�liwiaj�ce zarz�dzanie kolekcj� nosnik�w w bibliotece.
*/

class Biblioteka :public Szafka
{
public:
	/**  
	@brief Konstruktor jednoargumentowy Klsay Biblioteka.
	@param a_nazwa_pliku Nazwa pliku tekstowego, z kt�rego program, b�dzie zczytywa� dane przy w��czeniu, 
	oraz do kt�rego b�dzie zapisaywa� zmiany w kolekcji no�nik�w przy wychodzeniu.
	Deleguje prace do Konstruktora Klasy bazowej tutaj, do Klasy Szafka.
	*/
	Biblioteka(std::string a_nazwa_pliku);

	/** Destruktor Klasy Biblioteka */
	~Biblioteka();

	/////////////////////////////////////////////////////////////////////////

	/**
	@brief Metoda wy�wietlaj�ca tekstowe menu biblioteki.
	*/
	void menu();

	/**
	@brief Metoda zapisuj�ca kolekcj� nosnik�w do pliku.
	*/
	void wyjdz_z_biblioteki();

	/**
	@brief Metoda dodaj�ca now� ksi��k� do biblioteki.
	*/
	void dodaj_ksiazke();

	/**
	@brief Metoda dodaj�ca nowy album muzyczny do biblioteki.
	*/
	void dodaj_muzyczke();

	/**
	@brief Metoda dodaj�ca nowy film do biblioteki.
	*/
	void dodaj_film();

	/////////////////////////////////////////////////////////////////////////

	/**
	@brief Metoda dodaj�ca nowy nosnik do biblioteki. Po wyborze, konkretnego no�nika, 
	odsy�a do konkretnej funkcji dodaj�cej obiekt do biblioteki.
	*/
	void virtual dodaj_nosnik();

	/**
	@brief Metoda usuwaj�ca wybrany nosnik z biblioteki.
	*/
	void virtual usun_nosnik();

	/**
	@brief Metoda przenosz�ca konkretny nosnik na inne wybrane miejsce w bibliotece.
	*/
	void virtual przenies_nosnik();

	/**
	@brief Metoda wy�wietlaj�ca kolekcj� nosnik�w w bibliotece.
	*/
	void virtual pokaz_kolekcje();
};
# endif