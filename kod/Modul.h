#pragma once
#include <string>
#include <vector>
#include "Lekcja.h"

class Modul {
private:
    int id;
    std::string tytul;
    std::vector<Lekcja> lekcje;

public:
    Modul(int id, std::string tytul);
    void dodajLekcje(Lekcja l);
    std::string pobierzTytul() const;
    std::vector<Lekcja>& pobierzLekcje();
};
