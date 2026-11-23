#pragma once
#include <string>

class Uzytkownik {
protected:
    std::string imie;
    std::string nazwisko;
    int id;

public:
    Uzytkownik(int id, std::string imie, std::string nazwisko);
    virtual ~Uzytkownik() = default;
    virtual std::string pobierzRole() const = 0;

    std::string pobierzImie() const;
    std::string pobierzNazwisko() const;
};
