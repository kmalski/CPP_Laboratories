/* Celam zadnaia jest napisanie klasy opisujacej ulamek zyczajny.
   Klasa ta pozwala na konwersje z liczby calkowitej i z liczby typu double 
   (w tym przypadku z kontrolowana precyzja).
   
   Dostepna jest takze konwersja na typ double. 
   Zeby zadanie nie bylo nudne ulamki mozna dodawac (metoda add).

   UWAGA: Ulamkow nie trzeba skracac.
   UWAGA: Prosze sie zastanowic nad poprawnoscia const.
   UWAGA: Rachunkowa trudnoscia moze sie okazac konwersja z typu double na ulamek. 
   Niemniej, algorytm jest trywialnie prosty. Nalezy mnozyc liczbe rzeczywista przez 10 
   az do momentu gdy czesc dziesietna ulamka bedzie == 0 lub gdy odpowiednia precyzja 
   zostanie osiagnieta (czyli mianownik bedzie rowny precyzji, ktora zesmy ustalili).
 */

#include <iostream>
#include "Frac.h"
#include "Frac.h"

int main() {

  Frac f1(1,2);
  double fdec = f1;
  std::cout << "dziesietnie " << fdec << std::endl;

  
  Frac f2( f1 );
  std::cout << "skopiowane " << f2 << std::endl;
  f2.print();
  std::cout << std::endl;

  const Frac podo( f2.add( f1 ) );
  podo.print(" doane proste ulamki \n");

  
  const Frac f3(4);
  f3.print();
  std::cout << std::endl;
  double f3dec = f3;
  f2.print();
  std::cout << f3dec << std::endl;
  
  double a = 7 + f2;
  std::cout << a << std::endl;

  Frac::setCnvPrecision(1000000);
  const Frac fd(9.12);
  fd.print("\n");
  Frac::setCnvPrecision(1000);
  const Frac fd2(0.333333333);
  fd2.print(" na double ");
  std::cout << fd2 << std::endl;

  const Frac sim(4.0);
  sim.print(" sim\n");

  fd2.add(fd2).print(" po dodaniu\n");


  
  
}
/*
dziesietnie 0.5
skopiowane 0.5
1/2
4/4 doane proste ulamki 
4/1
1/24
7.5
9119999/1000000
333/1000 na double 0.333
4/1 sim
666000/1000000 po dodaniu
*/