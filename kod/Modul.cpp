#include "Modul.h"

Modul::Modul(int id, std::string tytul) : id(id), tytul(tytul) {}

void Modul::dodajLekcje(Lekcja l) {
    lekcje.push_back(l);
}

std::vector<Lekcja>& Modul::pobierzLekcje() {
    return lekcje;
}

std::string Modul::pobierzTytul() const {
    return tytul;
}
