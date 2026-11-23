#pragma once
#include <string>
#include <vector>
#include "Modul.h"
#include "Wykladowca.h"

class Kurs {
private:
    int id;
    std::string tytul;
    std::string opis;
    std::vector<Modul> moduly;
    Wykladowca* wykladowca;

public:
    Kurs(int id, std::string tytul, std::string opis, Wykladowca* wykladowca);
    int policzLekcje();
    void dodajModul(Modul m);

    int pobierzId() const;
    std::string pobierzTytul() const;
    std::string pobierzOpis() const;
    std::vector<Modul>& pobierzModuly();
};
