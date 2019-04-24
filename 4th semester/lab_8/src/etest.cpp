
/**
 * Celem zadania jest zabawa z obsluga wyjatkow. 
 * Pewne funkcje matematyczne maja okreslona dziedzine np. tu, to tylko liczby dodatnie.
 * Jesli argument tych funkcji jest spoza dziedziny to funkcje te wyrzucaja jakis wyjatek.
 * 
 * Naszym celem jest napisanie przydatnego narzedzia "secureRun", ktore uruchamia funkcje 
 * wraz z obsluga wyjatkow. Jesli wykonanie jest poprawne to otrzymujemy wynik.
 * Jesli zas wykonanie nie bylo poprawne to nasz "wynik" wskazuje na ten blad.
 *
 * Dla wygody klasa/struktura opakowujaca wynik jest konwertowalna 
 * na typ double.Konwersja dziala tylko jesli wynik byl poprawny. 
 * W przeciwnym razie powinnismy miec wyjatek.
 * Prosze kompilowac do etest z flagami -Wall -g
 **/


#include <cmath>
#include <iostream>
#include "Executor.h"


class Sin : public Executor::Function {
public:
  Sin(double n, double phase ) : m_n(n), m_phase(phase) {}

  double operator()( double x) const { return std::sin( m_n*x + m_phase ); }
  
private:
  double m_n;
  double m_phase;
};


struct Sqrt : public Executor::Function {
  double operator()( double x) const {
    if ( x < 0 )
      throw false; // to jest b. brzydkie ale jako cwiczenie akceptowalne
    return std::sqrt(x);
  }  
};

struct Log : public Executor::Function {
  double operator()( double x) const {
    if ( x < 0 )
      throw "Invalid argument"; // j.w.
    return std::log(x);
  }  
};

int main() {

  Executor::Result r = Executor::secureRun( Sin(1, 0), 0.3 );
  std::cout << r.valid << " " << r.value << " " << r.problem << std::endl;

  double x(r);
  std::cout << x << std::endl;
  
  r = Executor::secureRun( Sqrt(), 2.0 );
  std::cout << r.value << " " << r.problem << std::endl;

  r = Executor::secureRun( Sqrt(), -2.0 );
  std::cout << r.problem << std::endl;   

  r = Executor::secureRun( Log(), -2.0 );
  std::cout << r << std::endl;

  double y = r;
  std::cout << "val of y " << y << std::endl;
}
/* wynik
1 0.29552 
0.29552
1.41421 
Boolean of value false thrown
ERROR Invalid argument
libc++abi.dylib: terminating with uncaught exception of type char const*


 */
