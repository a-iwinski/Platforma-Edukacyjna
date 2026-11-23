#pragma once
#include <string>

class Lekcja {
private:
    int id;
    std::string temat;
    std::string tresc;

public:
    Lekcja(int id, std::string temat, std::string tresc);
    int pobierzId() const;
    std::string pobierzTemat() const;
};
