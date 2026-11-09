#include "Postep.h"

double Postep::obliczProcentPostepu() {
    if (kurs == nullptr) {
        return 0.0;
    }
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
    return "Certyfikat ukonczenia kursu dla: " + imie + " " + nazwisko;
}

bool Postep::ukonczLekcje(int id_modulu, int id_lekcji) {
    for (int i = 1; i < id_modulu; i++) {
        if (!czyModulUkonczony(i)) {
            return false;
        }
    }
    ukonczoneLekcje.insert(id_lekcji);
    return true;
}
