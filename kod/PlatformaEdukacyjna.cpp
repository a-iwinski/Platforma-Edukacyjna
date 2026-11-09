#include "PlatformaEdukacyjna.h"

void PlatformaEdukacyjna::dodajModulDoKursu(int id_kursu, Modul m) {
    if (id_kursu < 0 || id_kursu >= (int)katalogKursow.size()) {
        return;
    }
    katalogKursow[id_kursu].dodajModul(m);
}
