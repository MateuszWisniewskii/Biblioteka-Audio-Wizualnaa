/**
@file Nosnikaudio.h
@brief Plik nag³ówkowy, zawieraj¹cy deklaracjê klasy Nosnikaudio.
*/
#ifndef NOSNIKAUDIO_H
#define NOSNIKAUDIO_H
#include "Nosnik.h"

/**
@class Nosnikaudio
@brief Klasa reprezentuj¹ca noœnik wszystkich utworów lub albumów muzycznych.
Klasa potomna mo Klasie Nosnik.
*/

class Nosnikaudio : public Nosnik
{
protected:

	/**< D³ugoœæ ca³ego albumu lub utworu jeœli jest tylko jeden. */
	float dlugosc_nagrania;

public:

	/**
	@brief Konstruktor klasy Nosnikaudio.
	@param a_nr Numer noœnika w bibliotece.
	@param a_nazwa Nazwa albumu/utworu.
	@param a_autor Nazwa zespo³u, b¹dŸ Imiê i Nazwisko twórcy albumu/utworu.
	@param a_zawartosc Krótka nazwa noœnika album/ksi¹¿ka/film.
	@param a_data_premiery Data premiery albumu/utworu.
	@param a_dlugosc_nagrania D³ugoœæ nagrania audio.
	@param a_gatunek Gatunek muzyczny nagrania audio.
	*/

	Nosnikaudio(int a_nr, std::string a_nazwa, std::string a_autor, std::string a_zawartosc, std::string a_data_premiery, float a_dlugosc_nagrania, std::string a_gatunek) ;

	/**
	@brief Destruktor klasy Nosnikaudio.
	*/
	~Nosnikaudio();

	/////////////////////////////////////////////////////////////////////////

	/**
	@brief Metoda get_dlugosc_nagrania, zwraca d³ugoœæ nagrania audio.
	@return D³ugoœæ nagrania audio.
	*/
	float get_dlugosc_nagrania();

	/////////////////////////////////////////////////////////////////////////
	
	/**
	@brief Metoda draw, wyœwietla informacje o noœniku audio.
	*/
	void virtual draw() override;

	/**
	@brief Metoda zapisz, zapisuje informacje o noœniku audio do pliku.
	@param os Strumieñ wyjœciowy, do którego zapisywane s¹ dane.
	*/
	void virtual zapisz(std::ofstream& os) override;
};
#endif