/*
Celem zadania jest implementacja  klasy funkcjonujacej jak 
tablica jednowymiarowa typu double indeksowana w dowolnym zakresie 
(np. ujemnymi indeksami).

Podczas konstrukcji tablica ta ma pozwalac na wyszczegolnienie 
dolnego i gornego indeksu.
Mozliwe powinny byc inne konstruktory, w tym pobierajace inna tablice 
jak i fragment innej tablicy.

FlexiTab ma posidac metody zwracajacy minimalny i maksymalny+1 indeks 
a takze rozmiar. I proste roszezenie, metoda sprawdzajaca czy indeks jest 
w zakresie.

Kompliowac z flagami -Wall do pliku wykonywalnego tt.
 */

#include <iostream>

#include "FlexiTab.h"
#include "FlexiTab.h"


int main() {
  using namespace std;
  FlexiTab temps(-15, 4);
  temps.setAll(0);
  
  temps.at(-5) += 2.3;
  temps.at(-6) += 7.2;
  temps.at(3) += 3.89;
  
  
  const FlexiTab temps1(temps); // kopia tablicy
  cout << "kopia" <<endl;
  FlexiTab::print(temps1);
  cout << endl;
  cout << "fragment" <<endl;
  const FlexiTab temps2(temps1, -5, 4); // kopia zakresu tablicy
  FlexiTab::print(temps2);

  cout << endl;      
  cout << "Czy indeks -15 jest dobry " << temps2.inRange(-15) << endl;
  cout << "Czy indeks +15 jest dobry " << temps2.inRange(+15) << endl;
  cout << "Czy indeks -1  jest dobry " << temps2.inRange(-1) << endl;
 
}
/* wynik
kopia
-15:0 -14:0 -13:0 -12:0 -11:0 -10:0 -9:0 -8:0 -7:0 -6:7.2 -5:2.3 -4:0 -3:0 -2:0 -1:0 0:0 1:0 2:0 3:3.89 
fragment
-5:2.3 -4:0 -3:0 -2:0 -1:0 0:0 1:0 2:0 3:3.89 
Czy indeks -15 jest dobry 0
Czy indeks +15 jest dobry 0
Czy indeks -1  jest dobry 1
 */
