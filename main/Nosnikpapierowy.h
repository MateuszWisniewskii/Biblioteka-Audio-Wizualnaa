/**
@file Nosnikpapierowy.h
@brief Plik nag��wkowy, zawieraj�cy deklaracj� klasy Nosnikpapierowy.
*/
#ifndef NOSNIKPAPIEROWY_H
#define NOSNIKPAPIEROWY_H
#include "Nosnik.h"

/**
@class Nosnikpapierowy
@brief Klasa reprezentuj�ca no�nik wszystkich ksi��ek, czasopism itd.
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
	@param a_nr Numer no�nika w bibliotece.
	@param a_nazwa Nazwa ksi��ki.
	@param a_autor Nazwa zespo�u, b�d� Imi� i Nazwisko tw�rcy ksi��ki.
	@param a_zawartosc Kr�tka nazwa no�nika album/ksi��ka/film.
	@param a_data_premiery Data premiery ksi��ki.
	@param a_liczba_stron Liczba stron.
	@param a_gatunek Gatunek ksi�zki.
	*/
	Nosnikpapierowy(int a_nr, std::string a_nazwa, std::string a_autor, std::string a_zawartosc, std::string a_data_premiery, int a_liczba_stron, std::string a_gatunek) ;

	/**
	@brief Destruktor klasy Nosnikpapierowy.
	*/
	~Nosnikpapierowy();

	/////////////////////////////////////////////////////////////////////////

	/**
	@brief Metoda get_liczba_stron, zwraca liczbe stron w ksi��ce/czasopi�mie.
	@return Liczba stron w ksi��ce.
	*/
	int get_liczba_stron();

	/////////////////////////////////////////////////////////////////////////

	/**
	@brief Metoda draw, wy�wietla informacje o no�niku papierowym.
	*/
	void virtual draw() override;

	/**
	@brief Metoda zapisz, zapisuje informacje o no�niku audio do pliku.
	@param os Strumie� wyj�ciowy, do kt�rego zapisywane s� dane.
	*/
	void virtual zapisz(std::ofstream& os) override;
};
#endif

