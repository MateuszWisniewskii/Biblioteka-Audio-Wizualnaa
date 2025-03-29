/**
@file Biblioteka.cpp
@brief Plik zawieraj¹cy definicje klasy Biblioteka.
*/
#include "Biblioteka.h"

Biblioteka::Biblioteka(std::string a_nazwa_pliku): Szafka::Szafka(a_nazwa_pliku)
{
	//std::cout << "Konstruktor Bibliotki" << std::endl;
	if(polka.size()>0)
	{
		std::cout << "Witamy w naszej bibliotece :)" << std::endl;
		menu();
	}
	else
	{
		std::cout << "Sorki, ale wystapil jakis problem" << std::endl;
	}
}

Biblioteka::~Biblioteka()
{
	std::cout << "Destruktor Biblioteki" << std::endl;
}

void Biblioteka::menu()
{
	std::string wybor;
	std::cout << "***************************************" << std::endl;
	std::cout << "                 MENU                  " << std::endl;
	std::cout << "1. Pokaz kolekcje." << std::endl;
	std::cout << "2. Dodaj przedmiot do Biblioteki." << std::endl;
	std::cout << "3. Przenies przedmiot na inne miejsce." << std::endl;
	std::cout << "4. Usun przedmiot z Biblioteki." << std::endl;
	std::cout << "5. Wyjdz z biblioteki." << std::endl;
	std::cout << "***************************************" << std::endl;
	std::cout << "wprowadz nr. operacji lub nazwe operacji: "; std::cin >> wybor; std::cout << std::endl;
	std::cout << "*****************************************************************" << std::endl;

	if (wybor == "1" || wybor == "Pokaz" || wybor == "pokaz" || wybor == "Pokaz kolekcje" || wybor == "pokaz kolekcje")
	{
		pokaz_kolekcje();
	}
	else if (wybor == "2" || wybor == "Dodaj" || wybor == "dodaj" || wybor == "Dodaj przedmiot" || wybor == "dodaj przedmiot")
	{
		dodaj_nosnik();
	}
	else if (wybor == "3" || wybor == "Przenies" || wybor == "przenies" || wybor == "Przenies przedmiot" || wybor == "przenies przedmiot")
	{
		przenies_nosnik();
	}
	else if (wybor == "4" || wybor == "Usun" || wybor == "usun" || wybor == "Usun przedmiot" || wybor == "usun przedmiot")
	{
		usun_nosnik();
	}
	else if (wybor == "5" || wybor == "Wyjdz" || wybor == "wyjdz" || wybor == "Wyjdz z biblioteki" || wybor == "wyjdz z biblioteki")
	{
		wyjdz_z_biblioteki();
	}
	else
	{
		std::cout << std::endl;
		std::cout << "B³ad przy wybieraniu opcji." << std::endl;
		std::cout << "Sprobuj jeszcze raz." << std::endl;
		std::cout << std::endl;
		Biblioteka::menu();
	}


}

void Biblioteka::dodaj_nosnik()
{
	std::string wybor;
	int proba = 0;
	while (proba < 3)
	{
		std::cout << "Co chcialbys dodac do kolekcji??" << std::endl;
		std::cout << "1. Album muzyczny?" << std::endl;
		std::cout << "2. Film?" << std::endl;
		std::cout << "3. Ksiazke?" << std::endl;
		std::cout << "Podaj nr. operacji lub rodzaj nosnika: ";
		std::cin >> wybor; std::cout << std::endl;

		if (wybor == "1" || wybor == "Album" || wybor == "album" || wybor == "Album muzyczny" || wybor == "album muzyczny")
		{
			dodaj_muzyczke();
			return menu();
		}
		else if (wybor == "2" || wybor == "Film" || wybor == "film")
		{
			dodaj_film();
			return menu();
		}
		else if (wybor == "3" || wybor == "Ksiazka" || wybor == "ksiazka")
		{
			dodaj_ksiazke();
			return menu();
		}
		else
		{
			proba++;
			std::cout << "Niepoprawny wybor. Pozostalo prob: " << 3 - proba << std::endl;
		}
	}
	std::cout << "Przekroczono liczbê prob. Wyjscie z dodawania przedmiotu!" << std::endl;
	menu();
}

void Biblioteka::usun_nosnik()
{
	int wybor_poz;
	int proba = 3;
	std::cout << "ktora pozycje chcesz usunac?" << std::endl;
	std::cout << "Podaj numer pozycji: "; 
	for (int i = 0; i < proba; ++i)
	{
		std::cin >> wybor_poz; std::cout << std::endl;
		if (wybor_poz >= 1 && wybor_poz <= polka.size())
		{
			break;  // Wyjœcie z pêtli, jeœli wartoœæ jest poprawna
		}
		else
		{
			std::cout << " Nieprawidlowy numer pozycji. Pozostale proby: " << proba - i - 1 << std::endl;
			std::cout << "Podaj poprawny numer pozycji: ";
		}
	}
	if (wybor_poz < 1 || wybor_poz > polka.size())
	{
		std::cout << "Przekroczono liczbe prob. Wyjscie z dodawania przedmiotu!" << std::endl;
		menu();  // lub inna odpowiednia akcja, gdy przekroczono liczbê prób
	}

	for (int i = 0; i < polka.size(); i++) {
		if (i == wybor_poz - 1) {
			polka.erase(polka.begin() + i);
			std::cout << "Poprawnie usunieto przedmiot z pozycji" << std::endl;
			break;
		}
	}
	for (int i = wybor_poz - 1 ; i < polka.size(); i++)
	{
		int numer = i + 1;
		polka[i]->set_numer(numer);
	}
	menu();
}

void Biblioteka::przenies_nosnik()
{
	int wybor_poz;
	int nowe_miejsce;
	int proba = 3;
	std::cout << "ktora pozycje chcesz przeniesc?" << std::endl;
	std::cout << "Podaj numer pozycji, ktora chcesz przeniesc: ";
	for (int i = 0; i < proba; ++i) 
	{
		std::cin >> wybor_poz;
		if (wybor_poz >= 1 && wybor_poz <= polka.size())
		{
			break;  // Wyjœcie z pêtli, jeœli wartoœæ jest poprawna
		}
		else 
		{
			std::cout << " Nieprawidlowy numer pozycji. Pozostale proby: " << proba - i - 1 << std::endl;
			std::cout << "Podaj poprawny numer pozycji: ";
		}
	}
	if (wybor_poz < 1 || wybor_poz > polka.size()) 
	{
		std::cout << "Przekroczono liczbe prób. Wyjscie z dodawania przedmiotu!" << std::endl;
		menu();  // lub inna odpowiednia akcja, gdy przekroczono liczbê prób
	}

	proba = 3;
	std::cout << "Podaj numer nowej pozycji, w ktorym ma sie znalezc przedmiot: ";
	for (int i = 0; i < proba; ++i)
	{
		std::cin >> nowe_miejsce; 
		if(nowe_miejsce>=1 && nowe_miejsce <= polka.size())
		{
			break;  // Wyjœcie z pêtli, jeœli wartoœæ jest poprawna
		}
		else 
		{
			std::cout << " Nieprawidlowy numer pozycji. Pozostale proby: " << proba - i - 1 << std::endl;
			std::cout << "Podaj poprawny numer pozycji: ";
		}
	}
	if (nowe_miejsce < 1 || nowe_miejsce > polka.size())
	{
		std::cout << "Przekroczono liczbê prob. Wyjscie z dodawania przedmiotu!" << std::endl;
		menu();  // lub inna odpowiednia akcja, gdy przekroczono liczbê prób
	}

	polka[wybor_poz-1]->set_numer(nowe_miejsce);
	polka[nowe_miejsce-1]->set_numer(wybor_poz);

	std::swap(polka[wybor_poz - 1], polka[nowe_miejsce - 1]);

	std::cout << "Poprawnie przeniesiono przdmioty" << std::endl;

	menu();
}

void Biblioteka::pokaz_kolekcje()
{
	for(auto p : polka)
	{
		p->draw();
	}
	menu();
}

void Biblioteka::wyjdz_z_biblioteki()
{
	std::ofstream plik(nazwa_pliku);
	if (plik.is_open())
	{
		for (auto* obiekt : polka) 
		{
			obiekt->zapisz(plik);
		}
		plik.close();
	}
	else
	{
		std::cout << "Blad podczas otwierania pliku." << std::endl;
	}
}

void Biblioteka::dodaj_ksiazke()
{
	std::string nazwa, autor, data_premiery, gatunek;
	int nr = polka.size(), liczba_stron;
	nr++;

	std::cout << "Podaj nazwe ksiazki: "; std::cin >> nazwa;
	std::cout << "Podaj Imie i Nazwisko autora: "; std::cin >> autor;
	std::cout << "Podaj date premiery: "; std::cin >> data_premiery;
	std::cout << "Podaj liczbe stron: "; std::cin >> liczba_stron;
	std::cout << "Podaj gatunek lektury: "; std::cin >> gatunek;
	std::cout << std::endl;

	Nosnik* p = new Nosnikpapierowy(nr, nazwa, autor, "ksiazka", data_premiery, liczba_stron, gatunek);

	polka.push_back(p);
}

void Biblioteka::dodaj_muzyczke()
{
	std::string  nazwa, autor, data_premiery, gatunek;
	float dlugosc_nagrania;
	int nr = polka.size();
	nr++;

	std::cout << "Podaj nazwe albumu: "; std::cin >> nazwa;
	std::cout << "Podaj Imie i Nazwisko autora lub nazwe zespolu: "; std::cin >> autor;
	std::cout << "Podaj date premiery: "; std::cin >> data_premiery;
	std::cout << "Podaj dlugosc calej plyty: "; std::cin >> dlugosc_nagrania;
	std::cout << "Podaj gatunek muzyczny: "; std::cin >> gatunek;
	std::cout << std::endl;

	Nosnik* p = new Nosnikaudio(nr, nazwa, autor, "album", data_premiery, dlugosc_nagrania, gatunek);

	polka.push_back(p);
}

void Biblioteka::dodaj_film()
{
	std::string nazwa, autor, data_premiery, gatunek, obsada, wybor, aktor;
	float dlugosc_nagrania;
	int nr = polka.size();
	nr++;

	std::cout << "Podaj nazwe filmu: "; std::cin >> nazwa;
	std::cout << "Podaj Imie i Nazwisko rezysera: "; std::cin >> autor;
	std::cout << "Podaj date premiery: "; std::cin >> data_premiery;
	std::cout << "Podaj dlugosc filmu: "; std::cin >> dlugosc_nagrania;
	std::cout << "Podaj gatunek filmu: "; std::cin >> gatunek;
	std::cout << "Czy chcesz podaæ obsade tego filmu? Wpisz T/N: "; std::cin >> wybor;
	if(wybor == "T" || wybor == "t" || wybor == "tak" || wybor == "TAK" || wybor == "Tak")
		while (std::getline(std::cin, aktor))
		{
			std::cout << "Jezeli nie chcesz juz podawac obsady, wpisz koniec, jesli nie to, podaj jak sie nazywa aktor";
			if (aktor != "Koniec" || aktor != "koniec" || aktor != "KONIEC")
			{
				break;
			}
				obsada += aktor + "/ ";
		}
		std::cout << "Okej, to bêdzie a tyle :)" << std::endl;

	Nosnik* p = new Nosnikwideo(nr, nazwa, autor, "film", data_premiery, dlugosc_nagrania, gatunek, obsada);

	polka.push_back(p);
}