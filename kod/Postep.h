#pragma once
#include <set>
#include <string>
#include "Kurs.h"

class Postep {
private:
    Kurs* kurs;
    std::set<int> ukonczoneLekcje;
    bool certyfikatWydany;

public:
    Postep(Kurs* kurs);
    double obliczProcentPostepu();
    std::string wystawCertyfikat(std::string imie, std::string nazwisko);
    bool czyModulUkonczony(int id_modulu);
    bool ukonczLekcje(int id_modulu, int id_lekcji);

    Kurs* pobierzKurs() const;
};
