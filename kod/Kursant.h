#pragma once
#include <string>
#include <vector>
#include "Uzytkownik.h"
#include "Postep.h"

class Kursant : public Uzytkownik {
private:
    std::string dataRejestracji;
    std::vector<Postep> postepy;

public:
    Kursant(int id, std::string imie, std::string nazwisko, std::string dataRejestracji);
    std::string pobierzRole() const override;
    Postep* znajdzPostep(int id_kursu);
    void dodajPostep(Postep p);
};
