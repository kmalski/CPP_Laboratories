/*
 Celem zadania jest napisanie funkcji, ktore pozwalaja na manipulowaniem 
 maska bitowa zapisana w tablicy znakow. 
 
 Maski bitowe moga byc roznej dlugosci i funkcje, ktore operuja na calej masce:
 printBits, resetBits optrzymuja albo dlugosc, albo zakresy bitow, ktore sa zaalokowane.

 Kompliwac z flagami -Wall -g do pliku wykonywalnego o nazwie btest
 UWAGA: Prosze zapoznac sie z caloscia programu i w implementacji uzyc funkcji, 
        ktore i tak bedzie sie implementowac.

 */
#include <iostream> 
#include "lbit.h"
#include "lbit.h"

int main() {
  unsigned char bits1[64/sizeof(unsigned char)]; // mozemy przechowac 64 bity
  unsigned char bits2[256/sizeof(unsigned char)]; // mozem przechowac 256 bitow

  resetBits( bits1, 0, 64 );
  resetBits( bits2, 0xAA, 256 ); // ustawia bity wg maski

  std::cout << "print\n";
  printBits( bits1, 64 ); // bit 0 jest po lewej stronie (inaczej niz zwykle)
  printBits( bits2, 100, 200 ); // bity z pozycji od 100 do 200 (liczymy od 0)

  std::cout << "\nflip\n";
  flipBit( bits1, 40 );
  printBits( bits1, 64 );
  flipBit( bits1, 0 );
  flipBit( bits1, 1 );
  flipBit( bits1, 8 );
  flipBit( bits1, 40 );
  printBits( bits1, 64 );
  
  std::cout << "\nset\n";
  setBit( bits1, 40, 0 );
  setBit( bits1, 39, 1 );
  printBits( bits1, 64 );

  std::cout << " bit na pozycji 12 " <<  getBit( bits1, 12)
	    << " i na pozycji 39 " << getBit( bits1, 39 ) << std::endl;


  const unsigned char x=0x5;
  printBits( &x, sizeof(x)*8 );
  for ( int b = 0; b < sizeof(x)*8; ++b ) {
    std::cout << getBit( &x, b ) << " ";
  }
  std::cout << "\nkoniec\n";
}
/* wynik
print
00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000 
0101 01010101 01010101 01010101 01010101 01010101 01010101 01010101 01010101 01010101 01010101 01010101 01010101 

flip
00000000 00000000 00000000 00000000 00000000 10000000 00000000 00000000 
11000000 10000000 00000000 00000000 00000000 00000000 00000000 00000000 

set
11000000 10000000 00000000 00000000 00000001 00000000 00000000 00000000 
 bit na pozycji 12 0 i na pozycji 39 1
10100000 
1 0 1 0 0 0 0 0 
koniec

 */
