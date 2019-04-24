/* W zadaniu mamy do czynienia z pewna hierarcha klas 
   opisujaca zestaw klas (6 sztuk) będących w róznych relacjach. 
   Hierarchia powinna być uzasadniona - bez uzasadnienia zad. nie na temat == 0pkt.
   
   Kompilowac z -Wall -g
 */

#include <iostream>
#include "Urzadzenia.h"

void ptrPrint(const void* p) {
  if ( p == 0 )
    std::cout << "null ptr" << std::endl;
  else
    std::cout << "valid ptr" << std::endl;
}

void print(const Urzadzenie* u) {
  if ( u )
    std::cout << u->rodzaj()  << std::endl;
}

int main() {
  
  Skaner* s2= new Skaner(  Rozdzielczosc(1000, 1600) );
  ptrPrint(dynamic_cast<Papierozerne*>(s2));
  
  
  Drukarka* d2= new Drukarka(  Rozdzielczosc(1000, 1600) );
  ptrPrint(dynamic_cast<Papierozerne*>(d2));
  print(d2);

  Papierozerne* p =  new Wielofunkcyjne( Rozdzielczosc(300,600), Rozdzielczosc(600, 1200) );
  const Drukarka *d = dynamic_cast<Drukarka*>(p);
  const Ksero *k = dynamic_cast<Ksero*>(p);  
  const Skaner *s = dynamic_cast<Skaner*>(p);
  std::cout << "--------"  << std::endl;
  ptrPrint(d);
  print(d);
  ptrPrint(k);
  print(k);
  ptrPrint(s);
  print(s);
  std::cout << s->Skaner::rodzaj() << std::endl;
  // std::cout << s->Urzadzenie::rodzaj()  << std::endl; // z tym kodem ma sie nie z-linkowac
  ptrPrint(dynamic_cast<const Papierozerne*>(k));
  
  std::cout << d->rozdzielczosc() << std::endl;
  std::cout << s->rozdzielczosc() << std::endl;


  delete s2;
  delete d2;
  delete p;
}
/* wynik
null ptr
valid ptr
Drukarka
--------
valid ptr
Wielofunkcyjne
valid ptr
Wielofunkcyjne
valid ptr
Wielofunkcyjne
Skaner
valid ptr
300x600
600x1200

 */
