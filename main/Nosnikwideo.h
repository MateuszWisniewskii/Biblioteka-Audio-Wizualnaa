/**
@file Nosnikwideo.h
@brief Plik nag³ówkowy, zawieraj¹cy deklaracjê klasy Nosnikwideo.
*/
#ifndef NOSNIKWIDEO_H
#define NOSNIKWIDEO_H
#include "Nosnik.h"
#include <sstream>

/**
@class Nosnikwideo
@brief Klasa reprezentuj¹ca noœnik wszystkich filmów.
Klasa potomna mo Klasie Nosnik.
*/

class Nosnikwideo : public Nosnik
{
protected:

	/**< D³ugoœæ ca³ego filmu. */
	float dlugosc_nagrania;

	/**< Wektor aktorów graj¹cych w filmie. */
	std::vector<std::string> obsada;

public:

	/**
	@brief Konstruktor klasy Nosnikwideo.
	@param a_nr Numer miejsca w bibliotece.
	@param a_nazwa Nazwa filmu.
	@param a_autor Re¿yser filmu.
	@param a_zawartosc Krótka nazwa noœnika album/ksi¹¿ka/film.
	@param a_data_premiery Data premiery filmu.
	@param a_dlugosc_nagrania Dlugosc filmu w minutach.
	@param a_gatunek Gatunek filmu.
	@param a_obsada Obsada.
	*/
	Nosnikwideo(int a_nr, std::string a_nazwa, std::string a_autor, std::string a_zawartosc, std::string a_data_premiery, float a_dlugosc_nagrania, std::string a_gatunek,std::string a_obsada);
	
	/**
	@brief Destruktor klasy Nosnikwideo.
	*/
	~Nosnikwideo();

	/////////////////////////////////////////////////////////////////////////

	/**
	@brief Metoda get_dlugosc_nagrania, zwraca d³ugoœæ filmu.
	@return D³ugoœæ filmu.
	*/
	float get_dlugosc_nagrania();

	/**
	@brief Metoda get_obsada, zwraca obsade filmu jako lancuch znakow,
	rozdielony separatorem "/ ".
	@return Obsada == std::string.
	*/
	std::string get_obsada();

	/**
	@brief Metoda wpisz_obsade, dzieli lancuch znakow zawierajacy obsade nosnika na poszczegolnych aktorow i zapisuje ich do wektora obsada.
	@param vector_obsada Wektor, do ktorego zapisywana jest obsada nosnika wideo.
	@param a_obsada Lancuch znakow zawierajacy obsade nosnika wideo.
	*/
	void wpisz_obsade(std::vector<std::string>& vector_obsada, std::string a_obsada);

	/////////////////////////////////////////////////////////////////////////

	/**
	@brief Metoda draw, wyœwietla informacje o noœniku wideo.
	*/
	void virtual draw() override;

	/**
	@brief Metoda zapisz, zapisuje informacje o noœniku wideo do pliku.
	@param os Strumieñ wyjœciowy, do którego zapisywane s¹ dane.
	*/
	void virtual zapisz(std::ofstream& os) override;
};
#endif