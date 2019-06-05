#pragma once

#include "registration.H"

//bazowa klasa szablonowa sluzaca do zdefiniowania API, ktore pozwala pozyskac ID oraz obiekt podanego typu
template<typename BaseT>
class Generator {
	public:
	virtual int getID() const = 0; 

	virtual BaseT * getNewObject() const = 0;

    virtual ~Generator() = default;
};

//klasa szablonowa definiujaca metody klasy Generator dla konkretnych typow
template <typename BaseT, typename T>
class TGenerator : public Generator<BaseT> {
	public:
	int getID() const {
		return type2int<T>::value;
	}

	T * getNewObject() const {
		return new T;
	}
};