/**
@file Biblioteka.h
@brief Plik nag³ówkowy, zawieraj¹cy deklaracjê klasy Biblioteka.
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
@brief Klasa reprezentuj¹ca bibliotekê.
Klasa Biblioteka dziedziczy po klasie Szafka i zawiera
metody umo¿liwiaj¹ce zarz¹dzanie kolekcj¹ nosników w bibliotece.
*/

class Biblioteka :public Szafka
{
public:
	/**  
	@brief Konstruktor jednoargumentowy Klsay Biblioteka.
	@param a_nazwa_pliku Nazwa pliku tekstowego, z którego program, bêdzie zczytywa³ dane przy w³¹czeniu, 
	oraz do którego bêdzie zapisaywa³ zmiany w kolekcji noœników przy wychodzeniu.
	Deleguje prace do Konstruktora Klasy bazowej tutaj, do Klasy Szafka.
	*/
	Biblioteka(std::string a_nazwa_pliku);

	/** Destruktor Klasy Biblioteka */
	~Biblioteka();

	/////////////////////////////////////////////////////////////////////////

	/**
	@brief Metoda wyœwietlaj¹ca tekstowe menu biblioteki.
	*/
	void menu();

	/**
	@brief Metoda zapisuj¹ca kolekcjê nosników do pliku.
	*/
	void wyjdz_z_biblioteki();

	/**
	@brief Metoda dodaj¹ca now¹ ksi¹¿kê do biblioteki.
	*/
	void dodaj_ksiazke();

	/**
	@brief Metoda dodaj¹ca nowy album muzyczny do biblioteki.
	*/
	void dodaj_muzyczke();

	/**
	@brief Metoda dodaj¹ca nowy film do biblioteki.
	*/
	void dodaj_film();

	/////////////////////////////////////////////////////////////////////////

	/**
	@brief Metoda dodaj¹ca nowy nosnik do biblioteki. Po wyborze, konkretnego noœnika, 
	odsy³a do konkretnej funkcji dodaj¹cej obiekt do biblioteki.
	*/
	void virtual dodaj_nosnik();

	/**
	@brief Metoda usuwaj¹ca wybrany nosnik z biblioteki.
	*/
	void virtual usun_nosnik();

	/**
	@brief Metoda przenosz¹ca konkretny nosnik na inne wybrane miejsce w bibliotece.
	*/
	void virtual przenies_nosnik();

	/**
	@brief Metoda wyœwietlaj¹ca kolekcjê nosników w bibliotece.
	*/
	void virtual pokaz_kolekcje();
};
# endif