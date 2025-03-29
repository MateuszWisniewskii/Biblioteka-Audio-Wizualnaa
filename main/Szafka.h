/**
@file Szafka.h
@brief Plik nag³ówkowy, zawieraj¹cy deklaracjê klasy Szafka.
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
@brief Klasa reprezentuj¹ca sam¹ szafke na przedmioty w bibliotece.
Klasa bazowa dla Klasy Biblioteka, zawiera
metody wirtualne umo¿liwiaj¹ce zarz¹dzanie kolekcj¹ nosników w bibliotece.
*/

class Szafka 
{
protected:

	/**< Wektor wskaŸników na Klase bazow¹ dla noœników, przechowuj¹cy nosniki multimedialne w szafce. */
	std::vector<Nosnik*> polka; 

	/**< Nazwa pliku z danymi szafki. */
	std::string nazwa_pliku; 
	
public:

	/*
	@brief Konstruktor domyœlny klasy Szafka.
	Tworzy pust¹ szafkê na nosniki multimedialne.
	*/
	Szafka();

	/**
	@brief Konstruktor jednoargumentowy klasy Szafka.
	@param a_nazwa_pliku Nazwa pliku z danymi szafki. Zawarte s¹ w nim wszystkie noœniki.
	*/
	Szafka(std::string a_nazwa_pliku);

	/**
	@brief Destruktor klasy Szafka
	*/
	~Szafka();

	/////////////////////////////////////////////////////////////////////////

	/**
	@brief Metoda odczytuje dane z podanego pliku i tworzy obiekty reprezentuj¹ce nosniki multimedialne.
	Inicjalizuje szafkê, dodaj¹c odczytane nosniki do wektora polka.
	@param nazwa_pliku Nazwa pliku z danymi szafki.
	@param dane Referencja do wektora wskaŸników, w którym bêd¹ przechowywane odczytane dane z pliku tekstowego.
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