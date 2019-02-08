/*
 * Celem zadania jest napisanie hierarchi klas opisujacej skladniki systemu plikow.
 * Skladnikami tymi sa katalog (klasa Dir) i plik (klasa File).
 * 
 * UWAGA: Aby zapewnic ladne wypisywanie, klasy te powinny psiadac metode print z argumentem informujacym ile spacji potrzeba wypisac przed nazwa (indentacja).
 * UWAGA: Implementacja klasy Dir moze byc trywialna, np. zakladac ze bedzie ona posaiadac maksymalnie 10 skladnikow.
 * Kompilowac do pliku ftest z opckami -Wall -g 
 */

#include "Dir.h"
#include "File.h"

int main() {

  Dir* top = new Dir(".");
  Dir* home = new Dir("home");
  *top += home; // dodajemy do kat TOP podkatalog
  Dir* ewa = new Dir("ewa");
  *home += ewa;
  Dir* adam = new Dir("adam");
  *home += adam;  
  
  std::cout << (const Dir&)*top << std::endl;

  *ewa += new Dir("Desk");
  *ewa += new File("auto1.jpg");
  *ewa += new File("auto2.jpg");
  *ewa += new File("auto3.jpg");
  Dir* wd = new Dir("work");
  *wd += new File("proj.descr");
  *wd += new File("proj.files.repo");
  *ewa += wd;

  std::cout << *top;
  std::cout << "--------------" << std::endl;
  std::cout << *(ewa->get("work"));
  delete top;
}
/* wynik 
.
  home
    ewa
    adam

.
  home
    ewa
      Desk
      auto1.jpg
      auto2.jpg
      auto3.jpg
      work
        proj.descr
        proj.files.repo
    adam
--------------
work
  proj.descr
  proj.files.repo
Deleting Dir: .
About to delete home
Deleting Dir: home
About to delete ewa
Deleting Dir: ewa
About to delete Desk
Deleting Dir: Desk
About to delete auto1.jpg
About to delete auto2.jpg
About to delete auto3.jpg
About to delete work
Deleting Dir: work
About to delete proj.descr
About to delete proj.files.repo
About to delete adam
Deleting Dir: adam

 */
