#pragma once

#include "Generators.H"
#include <vector>

//makro sluzace do wygenerowania generatora dla podanych typow
#define TYPE(BaseType,Type) ( new TGenerator<BaseType, Type>() )

//klasa fabryka sluzaca do generowania nowych obiektow o wczesniej dodanych typach.
template <typename T>
class Factory {
public:
	//meteoda sluzaca do dodawania typow obiektow, ktore pozniej bedziemy chcieli stworzyc. Metode nalezy wywolac podajac jako argument
	// makro TYPE. Podane dwa typy w makrze TYPE musza byc ze soba powiazane dziedziczeniem (Type musi dziedziczyc po BaseType)
	void preload(Generator<T> *object) {
		_objects.push_back(object);
	}

	//zwraca nowy obiekt typu skojarzonego wczesniej z podanym ID. Jesli wczesniej nie dodano takiego typu do Farbyki to metoda zwraca nullptr
	T * produce(const int id) {
		for (const auto & elem : _objects) {
			if (id == elem->getID()) {
				return elem->getNewObject();
			} 
		}
		return nullptr;
	}

	//destruktor
	~Factory() {
		for (auto & elem : _objects) {
			delete elem;
		}
	}

private:
	//kontener sluzacy do przechowywania generatorow wczesniej dodanych typow
	std::vector<Generator<T> *> _objects;
};