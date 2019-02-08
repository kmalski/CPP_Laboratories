/* W zadaniu prosze napisac liste polaczona jednokierunkowo, sluzaca do przechowywania tablic 2x2 liczb calkowitych.

   UWAGA. Niektore z funkcji nie zmieniaja listy (np. print) i z tego powodu powinny odbierac staly wskaznik do struktury List.

   Kompilwac koniecznie z flagami -Wall -g
   Plik wykonywalny prosze nazwac "ltest".   
 */


#include <iostream>
#include "List.h"
#include "List.h"

int main() {
  List testList;
  prepare(&testList);
  const List* lptr = &testList;

  int x[2][2] = {{2,5}, {1,5}};
  add(&testList, x);
  

  int y[2][2] = {{3,2}, {4,3}};
  add(&testList, y);
  
  x[0][0] = 3;
  x[1][1] = 3;
  add(&testList, x);

  std::cout << "empty() " << empty(lptr) << std::endl;
  print(lptr);


  
  List testList2;
  prepare(&testList2, lptr); // tu poza inicjalizacja kopiujemy zawartosc pierwszej listy do drugiej
  x[0][0] = 1;
  x[1][0] = 1;
  x[0][1] = 4;
  x[1][1] = 2;
  add(&testList2, x);
  
  clear(&testList);
  std::cout << "empty() " << empty(lptr) << std::endl;
  print(lptr);    
  print(&testList2);  
  clear(&testList2);
}
/* wynik
empty() 0
2 5   3 2   3 5   
1 5   4 3   1 3   
empty() 1


2 5   3 2   3 5   1 4   
1 5   4 3   1 3   1 2   

 */
