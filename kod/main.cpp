#include <iostream>
#include <string>
#include <vector>
#include "Uzytkownik.h"
#include "Kursant.h"
#include "Wykladowca.h"
#include "Lekcja.h"
#include "Modul.h"
#include "Kurs.h"
#include "Postep.h"
#include "PlatformaEdukacyjna.h"

int main() {
    std::vector<Kursant> kursanci = {Kursant(0, "Jan", "Kowalski", "2026-10-01"),
                                     Kursant(1, "Ewa", "Malinowska", "2026-10-05")};
    std::vector<Wykladowca> wykladowcy = {Wykladowca(0, "Anna", "Nowak", "dr", "programowanie"),
                                          Wykladowca(1, "Piotr", "Zielinski", "mgr", "bazy danych")};
    PlatformaEdukacyjna platforma(kursanci, wykladowcy);

    // Przykladowe kursy na start.
    platforma.utworzKurs(0, "Programowanie w C++", "Od podstaw do OOP");
    platforma.dodajModulDoKursu(0, Modul(1, "Podstawy"));
    platforma.dodajModulDoKursu(0, Modul(2, "Programowanie obiektowe"));
    platforma.dodajLekcjeDoModulu(0, 1, Lekcja(1, "Zmienne i typy", "..."));
    platforma.dodajLekcjeDoModulu(0, 1, Lekcja(2, "Petle i warunki", "..."));
    platforma.dodajLekcjeDoModulu(0, 2, Lekcja(3, "Klasy i obiekty", "..."));
    platforma.dodajLekcjeDoModulu(0, 2, Lekcja(4, "Dziedziczenie", "..."));
    platforma.utworzKurs(1, "Wprowadzenie do SQL", "Zapytania i bazy danych");
    platforma.dodajModulDoKursu(1, Modul(1, "SELECT"));
    platforma.dodajLekcjeDoModulu(1, 1, Lekcja(1, "Pierwsze zapytanie", "..."));

    int rola = -1;
    while (rola != 0) {
        std::cout << "\n--- PLATFORMA EDUKACYJNA ---\n";
        std::cout << "1 - Kursant\n2 - Wykladowca\n0 - Wyjscie\nWybierz: ";
        std::cin >> rola;
        if (!std::cin) return 0;

        if (rola == 1) {
            // ---------- KURSANT ----------
            for (int i = 0; i < (int)kursanci.size(); i++) {
                std::cout << i << " - " << kursanci[i].pobierzImie() << " " << kursanci[i].pobierzNazwisko() << "\n";
            }
            std::cout << "Podaj id: ";
            int id;
            std::cin >> id;
            if (id < 0 || id >= (int)kursanci.size()) {
                std::cout << "Nie ma takiego kursanta\n";
                continue;
            }
            Uzytkownik* u = &kursanci[id];
            std::cout << "Zalogowano: " << u->pobierzImie() << " " << u->pobierzNazwisko()
                      << " (" << u->pobierzRole() << ")\n";
            Kursant* kursant = platforma.pobierzKursanta(id);

            int wybor = -1;
            while (wybor != 0) {
                std::cout << "\n1 - Przegladaj katalog\n2 - Wyszukaj kurs\n3 - Zapisz sie na kurs\n"
                             "4 - Ukoncz lekcje\n5 - Moj postep\n6 - Pobierz certyfikat\n0 - Wyloguj\nWybierz: ";
                std::cin >> wybor;
                if (!std::cin) return 0;

                if (wybor == 1) {
                    for (Kurs& k : platforma.wyszukajKursy("")) {
                        std::cout << k.pobierzId() << " - " << k.pobierzTytul() << " (" << k.pobierzOpis() << ")\n";
                    }
                } else if (wybor == 2) {
                    std::string fraza;
                    std::cout << "Fraza w tytule: ";
                    std::getline(std::cin >> std::ws, fraza);
                    for (Kurs& k : platforma.wyszukajKursy(fraza)) {
                        std::cout << k.pobierzId() << " - " << k.pobierzTytul() << "\n";
                    }
                } else if (wybor == 3) {
                    int id_kursu;
                    std::cout << "Id kursu: ";
                    std::cin >> id_kursu;
                    if (platforma.zapiszNaKurs(id, id_kursu)) {
                        std::cout << "Zapisano na kurs\n";
                    } else {
                        std::cout << "Nie mozna zapisac (juz zapisany lub nie ma takiego kursu)\n";
                    }
                } else if (wybor == 4) {
                    int id_kursu;
                    std::cout << "Id kursu: ";
                    std::cin >> id_kursu;
                    Postep* postep = kursant->znajdzPostep(id_kursu);
                    if (postep == nullptr) {
                        std::cout << "Nie jestes zapisany na ten kurs\n";
                        continue;
                    }
                    std::vector<Modul>& moduly = postep->pobierzKurs()->pobierzModuly();
                    for (int i = 0; i < (int)moduly.size(); i++) {
                        std::cout << "Modul " << i + 1 << ": " << moduly[i].pobierzTytul() << "\n";
                        for (Lekcja& l : moduly[i].pobierzLekcje()) {
                            std::cout << "   lekcja " << l.pobierzId() << ": " << l.pobierzTemat() << "\n";
                        }
                    }
                    int nr_modulu, id_lekcji;
                    std::cout << "Numer modulu: ";
                    std::cin >> nr_modulu;
                    std::cout << "Id lekcji: ";
                    std::cin >> id_lekcji;
                    if (platforma.ukonczLekcje(id, id_kursu, nr_modulu, id_lekcji)) {
                        std::cout << "Lekcja ukonczona. Postep: " << postep->obliczProcentPostepu() << "%\n";
                    } else {
                        std::cout << "Nie mozna ukonczyc lekcji (ukoncz najpierw poprzednie moduly lub sprawdz numery)\n";
                    }
                } else if (wybor == 5) {
                    for (Kurs& k : platforma.wyszukajKursy("")) {
                        Postep* postep = kursant->znajdzPostep(k.pobierzId());
                        if (postep != nullptr) {
                            std::cout << k.pobierzTytul() << ": " << postep->obliczProcentPostepu() << "%\n";
                        }
                    }
                } else if (wybor == 6) {
                    int id_kursu;
                    std::cout << "Id kursu: ";
                    std::cin >> id_kursu;
                    std::string cert = platforma.pobierzCertyfikat(id, id_kursu);
                    if (cert.empty()) {
                        std::cout << "Certyfikat niedostepny (potrzebne 100% postepu)\n";
                    } else {
                        std::cout << cert << "\n";
                    }
                }
            }
        } else if (rola == 2) {
            // ---------- WYKLADOWCA ----------
            for (int i = 0; i < (int)wykladowcy.size(); i++) {
                std::cout << i << " - " << wykladowcy[i].pobierzImie() << " " << wykladowcy[i].pobierzNazwisko() << "\n";
            }
            std::cout << "Podaj id: ";
            int id;
            std::cin >> id;
            if (id < 0 || id >= (int)wykladowcy.size()) {
                std::cout << "Nie ma takiego wykladowcy\n";
                continue;
            }
            Uzytkownik* u = &wykladowcy[id];
            std::cout << "Zalogowano: " << u->pobierzImie() << " " << u->pobierzNazwisko()
                      << " (" << u->pobierzRole() << ")\n";

            int wybor = -1;
            while (wybor != 0) {
                std::cout << "\n1 - Utworz kurs\n2 - Dodaj modul do kursu\n3 - Dodaj lekcje do modulu\n0 - Wyloguj\nWybierz: ";
                std::cin >> wybor;
                if (!std::cin) return 0;

                if (wybor == 1) {
                    std::string tytul, opis;
                    std::cout << "Tytul: ";
                    std::getline(std::cin >> std::ws, tytul);
                    std::cout << "Opis: ";
                    std::getline(std::cin >> std::ws, opis);
                    platforma.utworzKurs(id, tytul, opis);
                    std::cout << "Kurs utworzony\n";
                } else if (wybor == 2 || wybor == 3) {
                    std::vector<Kurs> kursy = platforma.wyszukajKursy("");
                    for (Kurs& k : kursy) {
                        std::cout << k.pobierzId() << " - " << k.pobierzTytul() << "\n";
                    }
                    int id_kursu;
                    std::cout << "Id kursu: ";
                    std::cin >> id_kursu;
                    if (id_kursu < 0 || id_kursu >= (int)kursy.size()) {
                        std::cout << "Nie ma takiego kursu\n";
                        continue;
                    }
                    int liczbaModulow = kursy[id_kursu].pobierzModuly().size();
                    if (wybor == 2) {
                        std::string tytul;
                        std::cout << "Tytul modulu: ";
                        std::getline(std::cin >> std::ws, tytul);
                        platforma.dodajModulDoKursu(id_kursu, Modul(liczbaModulow + 1, tytul));
                        std::cout << "Modul dodany\n";
                    } else {
                        for (int i = 0; i < liczbaModulow; i++) {
                            std::cout << "Modul " << i + 1 << ": " << kursy[id_kursu].pobierzModuly()[i].pobierzTytul() << "\n";
                        }
                        int nr_modulu;
                        std::cout << "Numer modulu: ";
                        std::cin >> nr_modulu;
                        if (nr_modulu < 1 || nr_modulu > liczbaModulow) {
                            std::cout << "Nie ma takiego modulu\n";
                            continue;
                        }
                        std::string temat, tresc;
                        std::cout << "Temat lekcji: ";
                        std::getline(std::cin >> std::ws, temat);
                        std::cout << "Tresc lekcji: ";
                        std::getline(std::cin >> std::ws, tresc);
                        platforma.dodajLekcjeDoModulu(id_kursu, nr_modulu, Lekcja(kursy[id_kursu].policzLekcje() + 1, temat, tresc));
                        std::cout << "Lekcja dodana\n";
                    }
                }
            }
        }
    }
    return 0;
}
