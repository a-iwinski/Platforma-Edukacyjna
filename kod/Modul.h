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
    void dodajLekcje(Lekcja l);
};
