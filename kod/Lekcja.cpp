#include "Lekcja.h"

Lekcja::Lekcja(int id, std::string temat, std::string tresc)
    : id(id), temat(temat), tresc(tresc) {}

int Lekcja::pobierzId() const { return id; }
std::string Lekcja::pobierzTemat() const { return temat; }
