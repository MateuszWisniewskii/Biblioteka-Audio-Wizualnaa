#pragma once
#include <vector>
#include <string>
#include "Szafka.h"
#include "Nosnik.h"

class Biblioteka {
private:
    std::vector<Szafka> polki;
    std::vector<Nosnik*> nosniki;

public:
    void dodajSzafke(Szafka polka) {
        polki.push_back(polka);
    }

    void dodajNosnik(Nosnik* nosnik) {
        nosniki.push_back(nosnik);
    }

    void usunNosnik(Nosnik* nosnik) {
        for (int i = 0; i < nosniki.size(); i++) {
            if (nosniki[i] == nosnik) {
                nosniki.erase(nosniki.begin() + i);
                break;
            }
        }
    }

    void przemiescNosnik(Nosnik* nosnik, Szafka& polka) {
        for (int i = 0; i < polki.size(); i++) {
            if (polki[i].czyZawiera(nosnik)) {
                polki[i].usunNosnik(nosnik);
                break;
            }
        }
        polka.dodajNosnik(nosnik);
    }

    void generujSpisZawartosci(std::string nazwaPliku, int opcjaSortowania) {
        /*
        opcjaSortowania:
        1 - sortowanie po numerze pó³ki
        2 - sortowanie po tytule/nazwie
        */
    }
};
