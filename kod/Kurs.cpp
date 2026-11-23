#include "Kurs.h"

Kurs::Kurs(int id, std::string tytul, std::string opis, Wykladowca* wykladowca)
    : id(id), tytul(tytul), opis(opis), wykladowca(wykladowca) {}

int Kurs::policzLekcje() {
    int suma = 0;
    for (Modul& m : moduly) {
        suma += m.pobierzLekcje().size();
    }
    return suma;
}

void Kurs::dodajModul(Modul m) {
    moduly.push_back(m);
}

int Kurs::pobierzId() const { return id; }
std::string Kurs::pobierzTytul() const { return tytul; }
std::string Kurs::pobierzOpis() const { return opis; }
std::vector<Modul>& Kurs::pobierzModuly() { return moduly; }
