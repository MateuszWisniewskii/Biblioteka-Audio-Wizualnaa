/**
@file Nosnik.h
@brief Plik nag��wkowy, zawieraj�cy deklaracj� klasy Nosnik.
*/
#ifndef NOSNIK_H
#define NOSNIK_H
#include <string>
#include <vector>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <iomanip>

/**
@class Nosnik
@brief Klasa reprezentuj�ca podstawe no�nika multimedialnego.
Klasa bazowa dla Klas: Nosnikaudio/Nosnikpapierowy/Nosnikwideo.
*/

class Nosnik
{
protected:

	/**< Numer miejsca w bibliotece. */
	int nr;

	/**< Nazwa konkretnego albumu/ksi��ki/filmu. */
	std::string nazwa;

	/**< Nazwa zespo�u, b�d� Imie i Nazwisko tw�rcy albumu/ksi��ki/filmu. */
	std::string autor;

	/**< Kr�tka nazwa no�nika album/ksi��ka/film. */
	std::string zawartosc;

	/**< Data premiery albumu/ksi��ki/filmu. */
	std::string data_premiery;

	/**< Gatunek albumu/ksi��ki/filmu. Np: rock, horror, komedia. */
	std::string gatunek;

public:

	/**
	@brief Konstruktor wieloargumentowy klasy Nosnik.
	@param a_nr Numer miejsca w bibliotece.
	@param a_nazwa Nazwa nosnika.
	@param a_autor Autor nosnika.
	@param a_zawartosc Zawartosc nosnika.
	@param a_data_premiery Data premiery nosnika.
	@param a_gatunek Gatunek nosnika.
	*/
	Nosnik(int a_nr, std::string a_nazwa, std::string a_autor, std::string a_zawartosc, std::string a_data_premiery, std::string a_gatunek);

	/**
	@brief Destruktor klasy Nosnik.
	*/
	~Nosnik();

	/////////////////////////////////////////////////////////////////////////

	/**
	@brief Metoda get_numer, zwraca numer miejsca w bibliotece nosnika.
	@return Numer miejsca w bibliotece nosnika.
	*/
	int   get_numer();

	/**
	@brief Metoda get_autor, zwraca autora nosnika.
	@return Autor nosnika.
	*/
	std::string  get_autor();

	/**
	@brief Metoda get_zawartosc, zwraca zawartosc nosnika.
	@return Zawartosc nosnika.
	*/
	std::string  get_zawartosc();

	/**
	@brief Metoda get_data_premiery, zwraca date premiery nosnika.
	@return Data premiery nosnika.
	*/
	std::string  get_data_premiery();

	/**
	@brief Metoda get_gatunek, zwraca gatunek nosnika.
	@return Gatunek nosnika.
	*/
	std::string  get_gatunek();

	/**
	@brief Metoda get_nazwa, zwraca nazwe nosnika.
	@return Nazwa nosnika.
	*/
	std::string  get_nazwa();
	
	/**
	@brief Metoda set_numer, ustawia numer miejsca w bibliotece nosnika.
	@param a_numer Numer miejsca w bibliotece nosnika.
	*/	
	void  set_numer(int& a_numer);

	/////////////////////////////////////////////////////////////////////////

	/**
	@brief Metoda draw, wypisuje informacje o nosniku.
	*/
	void virtual draw();

	/**
	@brief Metoda zapisz, zapisuje informacje o nosniku do strumienia plikowego.
	@param os Strumien wyjsciowy, do ktorego zapisywane sa dane na temat nosnika.
	Po czym zapisywane s� w pliku tekstowym.
	*/
	void virtual zapisz(std::ofstream& os);
};
#endif