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
    int policzLekcje();
    void dodajModul(Modul m);
};
