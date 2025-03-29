/**
@file Nosnikpapierowy.h
@brief Plik nag³ówkowy, zawieraj¹cy deklaracjê klasy Nosnikpapierowy.
*/
#ifndef NOSNIKPAPIEROWY_H
#define NOSNIKPAPIEROWY_H
#include "Nosnik.h"

/**
@class Nosnikpapierowy
@brief Klasa reprezentuj¹ca noœnik wszystkich ksi¹¿ek, czasopism itd.
Klasa potomna mo Klasie Nosnik.
*/

class Nosnikpapierowy : public Nosnik
{
protected:

	/**< Liczba wszystkich stron przedmiotu. */
	int liczba_stron;

public:

	/**
	@brief Konstruktor klasy Nosnikaudio.
	@param a_nr Numer noœnika w bibliotece.
	@param a_nazwa Nazwa ksi¹¿ki.
	@param a_autor Nazwa zespo³u, b¹dŸ Imiê i Nazwisko twórcy ksi¹¿ki.
	@param a_zawartosc Krótka nazwa noœnika album/ksi¹¿ka/film.
	@param a_data_premiery Data premiery ksi¹¿ki.
	@param a_liczba_stron Liczba stron.
	@param a_gatunek Gatunek ksi¹zki.
	*/
	Nosnikpapierowy(int a_nr, std::string a_nazwa, std::string a_autor, std::string a_zawartosc, std::string a_data_premiery, int a_liczba_stron, std::string a_gatunek) ;

	/**
	@brief Destruktor klasy Nosnikpapierowy.
	*/
	~Nosnikpapierowy();

	/////////////////////////////////////////////////////////////////////////

	/**
	@brief Metoda get_liczba_stron, zwraca liczbe stron w ksi¹¿ce/czasopiœmie.
	@return Liczba stron w ksi¹¿ce.
	*/
	int get_liczba_stron();

	/////////////////////////////////////////////////////////////////////////

	/**
	@brief Metoda draw, wyœwietla informacje o noœniku papierowym.
	*/
	void virtual draw() override;

	/**
	@brief Metoda zapisz, zapisuje informacje o noœniku audio do pliku.
	@param os Strumieñ wyjœciowy, do którego zapisywane s¹ dane.
	*/
	void virtual zapisz(std::ofstream& os) override;
};
#endif

