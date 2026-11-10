#include <iostream>
#include "Kursant.h"
#include "Wykladowca.h"
#include "Modul.h"
#include "Kurs.h"
#include "Postep.h"
#include "PlatformaEdukacyjna.h"


int Kurs::policzLekcje() { return 0; }
bool Postep::czyModulUkonczony(int) { return false; }

int main() {
    Wykladowca w;
    Kursant k;
    std::cout << "Rola 1: " << w.pobierzRole() << std::endl;
    std::cout << "Rola 2: " << k.pobierzRole() << std::endl;

    Lekcja l;
    Modul m;
    m.dodajLekcje(l);

    Kurs kurs;
    kurs.dodajModul(m);

    PlatformaEdukacyjna p;
    p.dodajModulDoKursu(0, m);  
    

    Postep postep{};
    std::cout << "Procent postepu: " << postep.obliczProcentPostepu() << "%" << std::endl;
    
    std::cout << "Lekcja 6 w module 2: " << (postep.ukonczLekcje(2, 6) ? "zaliczona" : "odrzucona") << std::endl;
    std::string cert = postep.wystawCertyfikat("Jan", "Kowalski");
    std::cout << "Certyfikat: " << (cert.empty() ? "odmowa" : cert) << std::endl;

    
    return 0;
}