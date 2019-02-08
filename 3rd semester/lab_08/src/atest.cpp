/*
 Celem zadania jest napisanie malej klasy modelujac kat.
 Jak wiemy kat moze zmieniac sie jedynie w przedziale od 0 do 2PI, 
 Wszystkie katy mniejsze niz 0 i wieksze niz 2PI sa tozsame z jakims katem z przedzialu od 0 od 2PI.
 Katy spoza przedialu 0-2PI sprowadza sie do przedzialu 0-2PI poprze dodanie/odjecie wielokrotnosci 2PI.

 Warosc kata w jednostkach SI podawana jest w radianach czyli jest liczba rzeczywista z zakresy 0 do 2PI.
 Jednak w praktyce bardzo czesto uzywa sie miary stopniowej i wtedy przydatny jest odpowiedni konstruktor i metoda dostepowa. 
 Wspolisnienie tych dwoch systemow miary kata jest na tyle problematyczne ze klasa Angle musi uniemozliwic konstruckcje bez zdefiniowanych jednostek.
 Biblioteka matematyczna definiuje stala M_PI, ktora nalezy uzyc zamiast 3.14.

 Program powinien sie skompilowac do pliku wykonywalnego 'atest'
 Plik zawierajacy funkcje main musi sie nazywac atest.cpp
 Podczas kompilacji musi byc uzyta flaga -Wall
 Za niespelnienie tych warunkow odejmuje punkt za kompilacje.
*/

#include <iostream>
using namespace std;

#include "Angle.h"
#include "Angle.h"

int main() {
  //Angle phi0(0.45); // to niepowinno sie skompilowac
  const Angle phi1 = Angle::fromRadians(11.45); // po podaniu konta powyzej 2PI i mniejszego niz 0 nastapic ma obrot do przedzialu (0, 2PI)
  const Angle phi2 = Angle::fromDegrees(-715);  // tak samo tutaj z jednoczesna konwersja na radiany
  
  double realphi1 = phi1.toRad();
  double realphi2 = phi2.toRad();
  cout << "Katy phi1 " << realphi1 << " phi2 " << realphi2 <<endl;

  realphi1 = phi1.toDeg();
  realphi2 = phi2.toDeg();
  cout << "Katy phi1 " << realphi1 << " phi2 " << realphi2 <<endl;

  
  Angle phi3(phi1);
  phi3.add(phi2);
  cout << phi3.toDeg() << endl;

  cout << "Roznica w stopniach " << Angle::distance(phi1, phi2).toDeg() << endl;
}
/* wynik dzialania
Katy phi1 5.16681 phi2 0.0872665
Katy phi1 296.037 phi2 5
222.516
Roznica w stopniach 68.9633
 */
