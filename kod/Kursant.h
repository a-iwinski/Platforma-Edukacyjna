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
    std::string pobierzRole() override;
    Postep znajdzPostep(int id_kursu);
};
