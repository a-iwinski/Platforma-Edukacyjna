#include "Uzytkownik.h"

Uzytkownik::Uzytkownik(int id, std::string imie, std::string nazwisko)
    : imie(imie), nazwisko(nazwisko), id(id) {}

std::string Uzytkownik::pobierzImie() const { return imie; }
std::string Uzytkownik::pobierzNazwisko() const { return nazwisko; }
