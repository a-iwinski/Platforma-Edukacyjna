#pragma once
#include <string>
#include "Uzytkownik.h"

class Wykladowca : public Uzytkownik {
private:
    std::string tytulNaukowy;
    std::string specjalizacja;

public:
    std::string pobierzRole() override;
};
