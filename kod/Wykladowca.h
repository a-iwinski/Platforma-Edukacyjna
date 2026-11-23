#pragma once
#include <string>
#include "Uzytkownik.h"

class Wykladowca : public Uzytkownik {
private:
    std::string tytulNaukowy;
    std::string specjalizacja;

public:
    Wykladowca(int id, std::string imie, std::string nazwisko,
               std::string tytulNaukowy, std::string specjalizacja);
    std::string pobierzRole() const override;
};
