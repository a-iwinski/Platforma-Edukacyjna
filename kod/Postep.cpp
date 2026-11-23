#include "Postep.h"

Postep::Postep(Kurs* kurs) : kurs(kurs), certyfikatWydany(false) {}

double Postep::obliczProcentPostepu() {
    int wszystkie = kurs->policzLekcje();
    if (wszystkie == 0) {
        return 0.0;
    }
    return 100.0 * ukonczoneLekcje.size() / wszystkie;
}

std::string Postep::wystawCertyfikat(std::string imie, std::string nazwisko) {
    if (obliczProcentPostepu() < 100.0) {
        return "";
    }
    certyfikatWydany = true;
    return "Certyfikat ukonczenia kursu \"" + kurs->pobierzTytul() + "\" dla: " + imie + " " + nazwisko;
}

// Moduly numerowane od 1 (modul nr 1 = pierwszy dodany do kursu).
bool Postep::czyModulUkonczony(int id_modulu) {
    std::vector<Modul>& moduly = kurs->pobierzModuly();
    if (id_modulu < 1 || id_modulu > (int)moduly.size()) {
        return false;
    }
    for (Lekcja& l : moduly[id_modulu - 1].pobierzLekcje()) {
        if (ukonczoneLekcje.count(l.pobierzId()) == 0) {
            return false;
        }
    }
    return true;
}

bool Postep::ukonczLekcje(int id_modulu, int id_lekcji) {
    std::vector<Modul>& moduly = kurs->pobierzModuly();
    if (id_modulu < 1 || id_modulu > (int)moduly.size()) {
        return false;
    }
    for (int i = 1; i < id_modulu; i++) {
        if (!czyModulUkonczony(i)) {
            return false;
        }
    }
    for (Lekcja& l : moduly[id_modulu - 1].pobierzLekcje()) {
        if (l.pobierzId() == id_lekcji) {
            ukonczoneLekcje.insert(id_lekcji);
            return true;
        }
    }
    return false;  // lekcja nie nalezy do tego modulu
}

Kurs* Postep::pobierzKurs() const { return kurs; }
