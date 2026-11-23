#include "PlatformaEdukacyjna.h"

PlatformaEdukacyjna::PlatformaEdukacyjna(std::vector<Kursant> kursanci, std::vector<Wykladowca> wykladowcy)
    : listaKursantow(kursanci), listaWykladowcow(wykladowcy) {}

void PlatformaEdukacyjna::utworzKurs(int id_wykladowcy, std::string tytul, std::string opis) {
    if (id_wykladowcy < 0 || id_wykladowcy >= (int)listaWykladowcow.size()) {
        return;
    }
    int id_kursu = katalogKursow.size();
    katalogKursow.push_back(Kurs(id_kursu, tytul, opis, &listaWykladowcow[id_wykladowcy]));
}

void PlatformaEdukacyjna::dodajModulDoKursu(int id_kursu, Modul m) {
    if (id_kursu < 0 || id_kursu >= (int)katalogKursow.size()) {
        return;
    }
    katalogKursow[id_kursu].dodajModul(m);
}

void PlatformaEdukacyjna::dodajLekcjeDoModulu(int id_kursu, int id_modulu, Lekcja l) {
    if (id_kursu < 0 || id_kursu >= (int)katalogKursow.size()) {
        return;
    }
    std::vector<Modul>& moduly = katalogKursow[id_kursu].pobierzModuly();
    if (id_modulu < 1 || id_modulu > (int)moduly.size()) {
        return;
    }
    moduly[id_modulu - 1].dodajLekcje(l);
}

// Pusta fraza zwraca caly katalog (przegladanie), niepusta - kursy z fraza w tytule.
std::vector<Kurs> PlatformaEdukacyjna::wyszukajKursy(std::string fraza) {
    std::vector<Kurs> wynik;
    for (Kurs& k : katalogKursow) {
        if (k.pobierzTytul().find(fraza) != std::string::npos) {
            wynik.push_back(k);
        }
    }
    return wynik;
}

bool PlatformaEdukacyjna::zapiszNaKurs(int id_kursanta, int id_kursu) {
    if (id_kursanta < 0 || id_kursanta >= (int)listaKursantow.size() ||
        id_kursu < 0 || id_kursu >= (int)katalogKursow.size()) {
        return false;
    }
    Kursant& kursant = listaKursantow[id_kursanta];
    if (kursant.znajdzPostep(id_kursu) != nullptr) {
        return false;
    }
    kursant.dodajPostep(Postep(&katalogKursow[id_kursu]));
    return true;
}

bool PlatformaEdukacyjna::ukonczLekcje(int id_kursanta, int id_kursu, int id_modulu, int id_lekcji) {
    if (id_kursanta < 0 || id_kursanta >= (int)listaKursantow.size()) {
        return false;
    }
    Postep* postep = listaKursantow[id_kursanta].znajdzPostep(id_kursu);
    if (postep == nullptr) {
        return false;
    }
    return postep->ukonczLekcje(id_modulu, id_lekcji);
}

std::string PlatformaEdukacyjna::pobierzCertyfikat(int id_kursanta, int id_kursu) {
    if (id_kursanta < 0 || id_kursanta >= (int)listaKursantow.size()) {
        return "";
    }
    Kursant& kursant = listaKursantow[id_kursanta];
    Postep* postep = kursant.znajdzPostep(id_kursu);
    if (postep == nullptr) {
        return "";
    }
    return postep->wystawCertyfikat(kursant.pobierzImie(), kursant.pobierzNazwisko());
}

Kursant* PlatformaEdukacyjna::pobierzKursanta(int id_kursanta) {
    if (id_kursanta < 0 || id_kursanta >= (int)listaKursantow.size()) {
        return nullptr;
    }
    return &listaKursantow[id_kursanta];
}
