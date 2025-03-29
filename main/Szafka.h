/**
@file Szafka.h
@brief Plik nag��wkowy, zawieraj�cy deklaracj� klasy Szafka.
*/
#ifndef SZAFKA_H
#define SZAFKA_H
#include <cstddef>
#include "Nosnik.h"
#include "Nosnikaudio.h"
#include "Nosnikpapierowy.h"
#include "Nosnikwideo.h"

/**
@class Szafka
@brief Klasa reprezentuj�ca sam� szafke na przedmioty w bibliotece.
Klasa bazowa dla Klasy Biblioteka, zawiera
metody wirtualne umo�liwiaj�ce zarz�dzanie kolekcj� nosnik�w w bibliotece.
*/

class Szafka 
{
protected:

	/**< Wektor wska�nik�w na Klase bazow� dla no�nik�w, przechowuj�cy nosniki multimedialne w szafce. */
	std::vector<Nosnik*> polka; 

	/**< Nazwa pliku z danymi szafki. */
	std::string nazwa_pliku; 
	
public:

	/*
	@brief Konstruktor domy�lny klasy Szafka.
	Tworzy pust� szafk� na nosniki multimedialne.
	*/
	Szafka();

	/**
	@brief Konstruktor jednoargumentowy klasy Szafka.
	@param a_nazwa_pliku Nazwa pliku z danymi szafki. Zawarte s� w nim wszystkie no�niki.
	*/
	Szafka(std::string a_nazwa_pliku);

	/**
	@brief Destruktor klasy Szafka
	*/
	~Szafka();

	/////////////////////////////////////////////////////////////////////////

	/**
	@brief Metoda odczytuje dane z podanego pliku i tworzy obiekty reprezentuj�ce nosniki multimedialne.
	Inicjalizuje szafk�, dodaj�c odczytane nosniki do wektora polka.
	@param nazwa_pliku Nazwa pliku z danymi szafki.
	@param dane Referencja do wektora wska�nik�w, w kt�rym b�d� przechowywane odczytane dane z pliku tekstowego.
	*/
	void odczytaj_dane_z_pliku(const std::string& nazwa_pliku, std::vector<Nosnik*>& dane);

	/////////////////////////////////////////////////////////////////////////

	/** 
	@brief Metody czysto wirtualne, definicje w klasach potomnych, tutaj w Klasie Biblioteka.
	*/
	void virtual dodaj_nosnik() = 0;

	void virtual usun_nosnik() = 0;

	void virtual przenies_nosnik() = 0;

	void virtual pokaz_kolekcje() = 0;
};
#endif