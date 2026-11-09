#pragma once
#include <string>
#include <vector>
#include "Kursant.h"
#include "Wykladowca.h"
#include "Kurs.h"

class PlatformaEdukacyjna {
private:
    std::vector<Kursant> listaKursantow;
    std::vector<Wykladowca> listaWykladowcow;
    std::vector<Kurs> katalogKursow;

public:
    void utworzKurs(int id_wykladowcy, std::string tytul, std::string opis);
    void dodajModulDoKursu(int id_kursu, Modul m);
    void dodajLekcjeDoModulu(int id_kursu, int id_modulu, Lekcja l);
    std::vector<Kurs> wyszukajKursy(std::string fraza);
    bool zapiszNaKurs(int id_kursanta, int id_kursu);
    bool ukonczLekcje(int id_kursanta, int id_kursu, int id_modulu, int id_lekcji);
    std::string pobierzCertyfikat(int id_kursanta, int id_kursu);
};
