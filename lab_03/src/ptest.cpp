/*
 Tematem zadania jest algorytm weryfikacji numeru PESEL.
 Mianowice na numer PESEL sklada sie z 6 cyfr skonstruowanych z daty urodzenia 
 i czterech cyfr identyfikacyjnych. 
 Ciekawostka parzystosc przedostatniej cyfry koduje plec, %2==0 - kobieta %2==1 - mezczyzna.
 
 Ostatnia cyfra numeru PESEL to tzw. suma kontrolna. Jest ona otrzymywana jako wynik odpowiedniej opracji na poprzedzajacych 10ciu cyfrach.
 Niech dana bedzie osoba urodzona w 1991-05-11. Mozliwy pesel dla tej osoby wyglada tak:
 9105112389? (znakiem ? oznaczono cyfre kontrolna, ktorej wyliczenie jest pokazane ponizej)

 Tworzymy:
 wektor cyfr w numerze PESEL: 9 1 0 5 1 1 2 3 8 9 ?
 wektor wag (niemzienny):     1 3 7 9 1 3 7 9 1 3 
 suma iloczynow: 9*1 + 1*3 + 0*7 + 5*9 + 1*1 + 1*3 + 2*7 + 3*9 + 8*1 + 9*3 = 137

 Sume te nalezy nastepnie podzielic modulo przez 10 a reszte odjac od 10.
 W tym przypadku ta reszta to: 7
 Liczba kontrolna = 3.
 Caly nr. PESEL wiec = 91051123893
 (UWAGA, gdy liczba kontrolna wynosi 10 to cyfra kontrolna dodawana do nr PESEL jest 0.)


 Nalezy napisac dwie funkce do obliczania cyfry kontrolnej (find_pesel_crtl) i funkcje sprawdzajaca poprawnosc nr. 
 PESEL, czyli czy cyfra kontrolna jest poprawna, (pesel_correct).
 Kompilowac do pliku wkonywalnego o nazwie pesel_test z opcjami -Wall -g.

 */

#include <iostream>
#include "check_pesel.h"
#include "check_pesel.h"

int main() {
  const char* pesel = "9105112389";
  char crtl = find_pesel_crtl(pesel);

  std::cout << pesel << crtl << std::endl;

  pesel = "9105112319";
  crtl = find_pesel_crtl(pesel);
  std::cout << pesel << crtl << std::endl;

  /// weryfikacja 
  pesel = "01250471121"; 
  if ( pesel_correct(pesel) ) {
    std::cout << "pesel " << pesel << " jet poprawny " << std::endl; 
  }

  pesel = "01250471120"; 
  if (not pesel_correct(pesel) ) {
    std::cout << "pesel " << pesel << " nie jet poprawny " << std::endl; 
  }
  return 0;
}
/* wynik
91051123893
91051123190
pesel 01250471121 jet poprawny 
pesel 01250471120 nie jet poprawny 
 */
