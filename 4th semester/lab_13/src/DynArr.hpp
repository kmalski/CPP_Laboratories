#pragma once

#include <iostream>
#include <type_traits>
#include <cstring>

//szablon struktury udostepniajacej funkcje, ktora przenosi blok pamieci
template <typename T, bool flag>
struct CopyStruct {
	static void copy(T *to, const T *from, int size) {
		memcpy(to, from, sizeof(T) * size);
	}
};

//szablon struktury udostepniajacej funkcje, ktora kopiuje podany obszar pamieci kopiujac kolejne elementy
template <typename T>
struct CopyStruct<T, false> {
	static void copy(T *to, const T *from, int size) {
		for (int i = 0; i < size; i++) {
			to[i] = from[i];
		}
	}
};

//szablon klasy bedacej kontenerem, jesli dodawane elementy sa trywialnie kopiowalne kopiuje je przenoszac blok pamieci, w innym wypadku
//odbywa sie zwykle przepisanie kolejnych wartosci
template <typename T>
class DynArray {
public:
	//konstruktor tworzac pusty kontener o podanym rozmiarze
	DynArray(int size = 0) : _size(size), _array(new  T[size]) {}

	//konsturktor kopiujacy
	DynArray(const DynArray& other) : _size(other._size), _array(new T[_size]) {
		CopyStruct<T, std::is_trivially_copyable<T>::value>::copy(_array, other._array, _size);
	}

	//destruktor
	~DynArray() {
		delete[] _array;
	}

	//metoda zwracajaca rozmiar kontenera
	int size() const {
		return _size;
	}

	//metoda dodajaca podany element na koniec kontenera, jesli obiekt jest trywialnie kopiowalny to kopiowany jest poprzez
	//przeniesienie blok pamieci, w innym wypadku kopiuje wartosc
	void expandAndSet(const T &item) {
		resize(_size + 1);
		CopyStruct<T, std::is_trivially_copyable<T>::value>::copy(_array + _size - 1, &item, 1);
	}

	//operator przypisania
	void operator=(T& other) {
		if(this == other) {
			return;
		}
		_size = other._size;
		resize(_size);
		CopyStruct<T, std::is_trivially_copyable<T>::value>::copy(_array, other._array, _size);
	}

	//operator indeksow
	T & operator[](int index) {
		return _array[index];
	}

	//operator indeksow zwracajacy staly element z podanego indeksu
	const T & operator[](int index) const {
		return _array[index];
	}

private:
	int _size;
	T *_array;

	//funkcja zmieniajaca rozmiar kontenera
	void resize(int newSize) {
		T *tmp = new T[newSize];
		CopyStruct<T, std::is_trivially_copyable<T>::value>::copy(tmp, _array, _size);
		delete[] _array;
		_array = tmp;
		_size = newSize;
	}

};

//szablon operatora wypisania dla kontenera DynArray
template <typename T>
std::ostream & operator<<(std::ostream & out, const DynArray<T> & array) {
	out << "{";
	for (int i = 0; i < array.size(); i++) {
		out << "\"" << array[i] << "\"";
		if (i != array.size() - 1) {
			out << ",";
		}
	}
	out << "}";
	return out;
}
