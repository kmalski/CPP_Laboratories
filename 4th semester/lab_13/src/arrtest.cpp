/* Opis zadania:
 * Proszę napisać kontener z optymalnym kopiowaniem będący opakowaniem na tablicę dynamiczną.
 * 
 * Smaczkiem zadania jest to ze ten kontener musi rozpoznac typy przechowywane 
 * i jesli sa to typy proste to zamiast zlozonego konstruktora kopiujacego 
 * powiniem uzyc prostego przepisania pamieci. 
 * Zob: man memcpy
 * struct Test, testuje dokladnie to wymaganie
 *
 * UWAGA: Rozmiar kontenera DynArray nie jest staly!
 * 
 * 
 * UWAGA: Mozna kozystac ze strony: https://en.cppreference.com/w/cpp/types
 * nalezy kompilowac z flaga --std=c++11
 */
 
#include "DynArr.hpp"
#include "DynArr.hpp"

#include <iostream>
#include <string>
#include <numeric>


struct Test {
  Test() = default;
  Test(const Test& ) = delete;
  void operator=(const Test&) = delete;
  char v;
};

int main(){
    // array indexing
    DynArray<int> arr;
    std::cout << "new DynArray<int> = " << arr << std::endl;
    for(int i = 0; i < 5; ++i){
      arr.expandAndSet(i*i);
    }
    std::cout << "filled DynArray<int> = " << arr << std::endl;
    
    arr[0] = 10.5;   
    std::cout << "changed DynArray<int>[0] = " << arr[0] << std::endl;  
    
    DynArray<int> arrb = arr;   
    std::cout << "copied DynArray<int> = " << arrb << std::endl;

    DynArray<Test> dt;
    //Test s = {'x'}; // operacje = nie zadzialalaja z powodu skasowanych konstruktorow
    //Test z = s;
    //Test t = {'y'};
    //t = s;
    dt.expandAndSet({'a'});
    std::cout << "Test " << dt[0].v << std::endl;
    DynArray<Test> rt = dt;
    std::cout << "copy Test " << rt[0].v << std::endl;
    
    DynArray<DynArray<int>> arr2D(3);
    arr2D[0].expandAndSet(6);
    arr2D[0].expandAndSet(2);

    std::cout << "DynArray<DynArray<int>>[0] = " << arr2D[0] << std::endl;
    std::cout << "DynArray<DynArray<int>> = " << arr2D << std::endl;
    
    DynArray<DynArray<int>> arr2Db = arr2D;
    std::cout << "copied DynArray<DynArray<int>> = " << arr2Db << std::endl;
    return 0;
}

/* Wynik 
new DynArray<int> = {}
filled DynArray<int> = {"0","1","4","9","16"}
changed DynArray<int>[0] = 10
copied DynArray<int> = {"10","1","4","9","16"}
Test a
copy Test a
DynArray<DynArray<int>>[0] = {"6","2"}
DynArray<DynArray<int>> = {"{"6","2"}","{}","{}"}
copied DynArray<DynArray<int>> = {"{"6","2"}","{}","{}"}
*/
