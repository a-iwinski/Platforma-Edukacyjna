#include "Wykladowca.h"

Wykladowca::Wykladowca(int id, std::string imie, std::string nazwisko,
                       std::string tytulNaukowy, std::string specjalizacja)
    : Uzytkownik(id, imie, nazwisko),
      tytulNaukowy(tytulNaukowy), specjalizacja(specjalizacja) {}

std::string Wykladowca::pobierzRole() const {
    return "Wykladowca";
}
