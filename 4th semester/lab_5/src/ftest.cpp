/*
 * Celem zadania jest napisanie hierarchi klas opisujacej skladniki systemu plikow.
 * Skladnikami tymi sa katalog (klasa Dir) i plik (klasa File) i moz cos jeszcze.

 * UWAGA: aby zapewnic ladne wypisywanie, klasy te powinny psiadac metode print z argumentem informujacym ile spacji potrzeba wypisac przed nazwa (indentacja).
 * UWAGA: W rozwiazaniu nalezy uzyc dynamicznego rozpoznania typow (wazne, upraszcza implementacje nieco!)
 * UWAGA: W implementacji metody add nalezy sie posluzyc wczeniej zdefiniowanym operatorem += a nie na odwrot
 * Kompilowac do pliku ftest z opckami -Wall -g 
 */

#include "Dir.h"
#include "File.h"

/* UWAGA: Takie dziedziczenie ma sie nie udac, prosze nie ignorowac tej uwagi, -1pkt za niezapewnienie tego wymagania
  struct Link : public File {
  }; 
 */


int main() {

  Dir* top = new Dir(".");
  Dir* home = new Dir("home");
  *top += home; // dodajemy do kat TOP podkatalog
  *home += new Dir("ewa");
  *home += new Dir("adam");
  
  std::cout << (const Dir&)*top << std::endl;

  top->findDir("ewa")->add( new Dir("Desk") );

  Dir* ewa = home->findDir("ewa");  
  *ewa += new File("auto1.jpg");
  *ewa += new File("auto2.jpg");
  *ewa += new File("auto3.jpg");
  top->findDir("ewa")->add( new Dir("work") );
  *home += new File("proj.descr");
  *home += new File("proj.files.repo");


  std::cout << *top;
  std::cout << "--------------" << std::endl;
  std::cout << *(ewa->get("work"));
  std::cout << *(top->get("proj.descr"));

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
    adam
    proj.descr
    proj.files.repo
--------------
work
proj.descr
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
About to delete adam
Deleting Dir: adam
About to delete proj.descr
About to delete proj.files.repo

 */
