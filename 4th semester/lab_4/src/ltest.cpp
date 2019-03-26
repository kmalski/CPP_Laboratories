/* Zasadniczym celem zadania jest odnalezienie hierarchi klas.
   To znaczy nalezy znalezc "czesc wspolna" pewnych obiektow, ktore wystepuja w temacie.
   W szczegolnosci w rozwiazaniu moga wystapic tylko dwie implementacje funkcji eval. 

   UWAGA: Prosze zwrocic uwage na argumentowosc operacji logicznych.

   UWAGA: Prosze pamietac ze zachowanie polimorficzne wystepuje tylko z & lub *
   
 */

#include <iostream>
#include "Logical.h"

void p2(const TwoArg& op) {
  std::cout << "p2  " <<  op.result(true, false) << std::endl;
}

int main() {
  std::cout << "OR   " <<  Logical::eval( OR(), false, false ) << std::endl;
  std::cout << "OR   " <<  Logical::eval( OR(), false, true ) << std::endl;
  std::cout << "AND  " <<  Logical::eval( AND(), false, false ) << std::endl;
  std::cout << "AND  " <<  Logical::eval( AND(),
					  false,
					  Logical::eval(NOT(), false) ) << std::endl;
  std::cout << "AND  " <<  Logical::eval( AND(),
					  Logical::eval(OR(), true, false ),
					  true ) << std::endl;  

  p2( OR() );
  p2( AND() );
}
/* wynik
OR   0
OR   1
AND  0
AND  0
AND  1
p2  1
p2  0
 */
