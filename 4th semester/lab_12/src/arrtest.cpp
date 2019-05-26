/* Opis zadania:
 * Proszę napisać kontener będący opakowaniem na tablicę dynamiczną. 
 * Dla uproszczenia, rozmiar kontenera jest STALY i NIEZMIENNY w trakcie działania programu
 * proszę pamiętać o zarządzaniu pamięcią.
 * 
 * Jako uzupełnienie kontenera, należy napisać podklasę Iterator 
 * (lub rozwiazac postawiony problem jakos inaczej).
 * Funkcjonalnosc iteratora to: op. ++, !- i dereferencja
 * 
 * W przyszłości taki iterator będzie potrzebny w korzystaniu z algorytmów
 * biblioteki standardowej, zakomentowany przykład poniżej.
 * Umożliwi on także zastosowanie tzw. zakresowej pętli for ( C++11 ).
 * 
 */
 
#include "DynArr.hpp"
#include "DynArr.hpp"

#include <iostream>
#include <string>
#include <numeric>

int main(){
    // array indexing
    DynArray<int> arr(5);   
    for(int i = 0; i < arr.size(); ++i){
        arr[i] = i*i;
    }
    std::cout << "DynArray<int> = " << arr << std::endl;
    
    arr[0] = 10.5;   
    std::cout << "DynArray<int>[0] = " << arr[0] << std::endl;
    
    // array iterators
    const std::string staticArray[4] = {"Anna", "Elsa", "Olaf", "Zen"};
    DynArray<std::string> strArr(4, staticArray);
    
    std::cout << "DynArray<std::string> = "<< strArr << std::endl;
    // uzycie iteratora
    for(DynArray<std::string>::Iterator it = strArr.begin(); it != strArr.end(); ++it){ 
        std::cout << "\tBefore: " << *it << std::endl;
	it->append(" Ice"); 		                // do kogo nalezy funkcja append?
        std::cout << "\tAfter : " << *it << std::endl;
    }
    std::cout << "DynArray<std::string> = "<< strArr << std::endl;
    
    return 0;
}

/* Wynik działania programu
DynArray<int> = {"0","1","4","9","16"}
DynArray<int>[0] = 10
DynArray<std::string> = {"Anna","Elsa","Olaf","Zen"}
	Before: Anna
	After : Anna Ice
	Before: Elsa
	After : Elsa Ice
	Before: Olaf
	After : Olaf Ice
	Before: Zen
	After : Zen Ice
DynArray<std::string> = {"Anna Ice","Elsa Ice","Olaf Ice","Zen Ice"}
*/
