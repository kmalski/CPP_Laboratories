#pragma once

#include "Wrapper.h"

/**
 * @class TypeWrapper
 * @brief szablon klasy przechowujacej obiekt danego typu. Dzieki dziedziczeniu po klasie Wrapper, mozna stworzyc kontener polimorficzny,
 * 		  ktory moze przechowywac obiekty dowolnego typu jednoczesnie.
 */
template <typename T>
class TypeWrapper : public Wrapper {
	public:
	    /**
		 * @fn TypeWrapper
		 * @brief konstruktor
		 * @param element - obiekt, ktory chcemy przechowac
		 */
		TypeWrapper(T element) : _element(element) {}

	    /**
		 * @fn getElement
		 * @brief getter, zwracajacy obiekt, ktory jest przechowywany
		 */
		T getElement() {
			return _element;
		}


	private:
		/**
		 * @param _element
		 * @brief element ktory jest przechowywany
		 */
		T _element;
};