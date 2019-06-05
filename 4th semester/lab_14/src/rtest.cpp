/**
 * mapa typ <--> int
 * 
 * Czasami przydatna jest mozliwosc jednoznaczej translacji:
 * z jakiegos typu na identyfikator (na przyklad aby zapisac identyfikator obiektu 
 * w pliku wynikowym)
 * i na odwrot z identyfikatora na jakis zadany typ (na przyklad aby moc stworzyc obiekty typow majac jedynie identyfikator). 
 * 
 * Prosze napisac naglowek registration.H wykorzystujacy technike 
 * specializacji celem stworzenia dwoch pomocniczych typw szablonowych 
 * type2int i int2type tak aby ponizszy kod kompilowal sie i dzialal. 
 * Specializacje prosze zastapic makrem DECLARE_TYPE_IDENTIFIER.
 *
 * Funkcjonalnosc nalezy nastepnie wykozystac w szabline fabryki pozwalajacej 
 * na generacje obiektow znajac ich identyfikator.
 *
 * Plik wynikowy prosze nazwac "test". Kompilowac z opcjami -Wall -g
 **/


#include <iostream>
#include <string>

#include "registration.H"
#include "factory.H"

struct Base {
  virtual std::string name() const =0;
  virtual ~Base() {}
};

class A : public Base{
public:
  std::string name() const { return "class A"; }  
};
DECLARE_TYPE_IDENTIFIER(A, 1112)

struct B : public Base{
  std::string name() const { return "struct B"; }
};
DECLARE_TYPE_IDENTIFIER(B, 1123)

struct C : public Base{
  std::string name() const { return "struct C"; }
};
DECLARE_TYPE_IDENTIFIER(C, 1127)


int main() {
  std::cout << " id " << type2int<A>::value << std::endl; 

  Base* x3(new  int2type<1112>::type);
  std::cout << x3->name() << std::endl;

  Base* x4(new int2type<1123>::type);
  std::cout << x4->name() << std::endl;

  delete x3;
  delete x4;

  Factory<Base> f;
  f.preload(TYPE(Base, A));
  f.preload(TYPE(Base, B));
  Base* x1 = f.produce(1112);
  std::cout << x1->name() << std::endl;
  
  Base* x2 = f.produce(1123);
  std::cout << x1->name() << std::endl;
  
  std::cout << f.produce(1127) << std::endl; // null ptr gdy nie ma prototypu
   
  
  //   int2type<3333>::type z; //ta linie powinna dac blad kompilacji
  
  delete x1;
  delete x2;
}
/* wynik 
 id 1112
class A
struct B
class A
class A
0x0
 */
