/**
@file Nosnikaudio.h
@brief Plik nag��wkowy, zawieraj�cy deklaracj� klasy Nosnikaudio.
*/
#ifndef NOSNIKAUDIO_H
#define NOSNIKAUDIO_H
#include "Nosnik.h"

/**
@class Nosnikaudio
@brief Klasa reprezentuj�ca no�nik wszystkich utwor�w lub album�w muzycznych.
Klasa potomna mo Klasie Nosnik.
*/

class Nosnikaudio : public Nosnik
{
protected:

	/**< D�ugo�� ca�ego albumu lub utworu je�li jest tylko jeden. */
	float dlugosc_nagrania;

public:

	/**
	@brief Konstruktor klasy Nosnikaudio.
	@param a_nr Numer no�nika w bibliotece.
	@param a_nazwa Nazwa albumu/utworu.
	@param a_autor Nazwa zespo�u, b�d� Imi� i Nazwisko tw�rcy albumu/utworu.
	@param a_zawartosc Kr�tka nazwa no�nika album/ksi��ka/film.
	@param a_data_premiery Data premiery albumu/utworu.
	@param a_dlugosc_nagrania D�ugo�� nagrania audio.
	@param a_gatunek Gatunek muzyczny nagrania audio.
	*/

	Nosnikaudio(int a_nr, std::string a_nazwa, std::string a_autor, std::string a_zawartosc, std::string a_data_premiery, float a_dlugosc_nagrania, std::string a_gatunek) ;

	/**
	@brief Destruktor klasy Nosnikaudio.
	*/
	~Nosnikaudio();

	/////////////////////////////////////////////////////////////////////////

	/**
	@brief Metoda get_dlugosc_nagrania, zwraca d�ugo�� nagrania audio.
	@return D�ugo�� nagrania audio.
	*/
	float get_dlugosc_nagrania();

	/////////////////////////////////////////////////////////////////////////
	
	/**
	@brief Metoda draw, wy�wietla informacje o no�niku audio.
	*/
	void virtual draw() override;

	/**
	@brief Metoda zapisz, zapisuje informacje o no�niku audio do pliku.
	@param os Strumie� wyj�ciowy, do kt�rego zapisywane s� dane.
	*/
	void virtual zapisz(std::ofstream& os) override;
};
#endif