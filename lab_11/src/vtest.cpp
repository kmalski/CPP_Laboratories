/*
  Celm zadania jest napisanie kopiowalnego i przypisywalnego wektora. 
  FVec ma to do siebie ze posiada operatory pozwalajace na dodawanie i odejmowanie leementow. 

  UWAGA: Nie trzeba obslugiwac zlego uzycia tego wektora
  UWAGA: Prosze pamietac o poprawnosci const
  UWAGA: Operatory (poza =) nie modyfikuja obiektow.

 */
#include <iostream>
#include "FVec.h"

int main() {
  
  FVec a(5); // wektor 5 elementowy indeksowany od 0 do 4x
  a.set(2,5).set(3,-1);  
  a.print("To jest a ");

  FVec b(7);  
  FVec c = b; // a to kopia czy przypisanie?
  c.set(2, 5).set(0, 11);
  c.print("to jest c ");
  b.set(0, 9);
  b.print("to jest b ");

  b = c + 10;
  b.print("to jest c+ 10: ");

  const FVec& crefb = b;  
  FVec dod = crefb+crefb;
  dod.print("2 x b ");
  b = b;
  b.print("zyjemy jeszcze ? ");
  
}
/* wynik
   To jest a 0 0 5 -1 0 
to jest c 11 0 5 0 0 0 0 
to jest b 9 0 0 0 0 0 0 
to jest c+ 10: 21 10 15 10 10 10 10 
2 x b 42 20 30 20 20 20 20 
zyjemy jeszcze ? 21 10 15 10 10 10 10 
 */
