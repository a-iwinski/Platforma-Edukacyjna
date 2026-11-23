# Zmiany w kodzie wzgledem diagramu klas (do uzasadnienia na Lab 4)

## Zmiany metod
- `Kursant::dodajPostep(Postep)` - nowa metoda. Pole `postepy` jest prywatne, wiec Kursant sam dodaje sobie Postep przy zapisie na kurs (enkapsulacja).
- `Kursant::znajdzPostep` zwraca `Postep*` (nullptr = brak zapisu), zeby `ukonczLekcje` zmienialo prawdziwy postep, a nie kopie.
- `pobierzRole()` jest `const`.

Na diagramie pominieto konstruktory i gettery 
