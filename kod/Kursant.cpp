#include "Kursant.h"

Kursant::Kursant(int id, std::string imie, std::string nazwisko, std::string dataRejestracji)
    : Uzytkownik(id, imie, nazwisko), dataRejestracji(dataRejestracji) {}

std::string Kursant::pobierzRole() const {
    return "Kursant";
}

Postep* Kursant::znajdzPostep(int id_kursu) {
    for (Postep& p : postepy) {
        if (p.pobierzKurs()->pobierzId() == id_kursu) {
            return &p;
        }
    }
    return nullptr;
}

void Kursant::dodajPostep(Postep p) {
    postepy.push_back(p);
}
