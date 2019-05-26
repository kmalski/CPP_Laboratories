#pragma once

#include <vector>
#include "TypeWrapper.h"
#include "missing.h"

/**
 * @class ClonesF
 * @brief klasa fabryka, pozwalajaca na konstrukcje/klonowanie obiektow dowolnego typu
 */
class ClonesF {
	public:
	    /**
		 * @fn add
		 * @brief szablon metody dodajacej obiekt danego typu do fabryki, aby moc pozniej go zklonwac
		 * @param element - obiekt ktory chcemy dodac do fabryki
		 */
		template <typename T>
		void add(T element) {
			_objects.push_back(new TypeWrapper<T>(element));
		}

	    /**
		 * @fn clone
		 * @brief szablon metody klonujacej obiekt danego typu, ktory wczesniej zostal dodany do fabryki
		 */
		template <typename T>
		T clone() {
			for (auto elem : _objects) {
				TypeWrapper<T> *tmp = dynamic_cast<TypeWrapper<T> *>(elem);
				if (tmp) {
					return tmp->getElement();
				}
			}
			throw missing<T>();
		}

	    /**
		 * @fn ~ClonesF
		 * @brief destruktor usuwajacy wszystkie obiekty z fabryki
		 */
		~ClonesF() {
			for (auto elem : _objects) {
				delete elem;
			}
		}

	private:
	    /**
		 * @param _objects
		 * @brief wektor przechowujacy wszystkie obiekty dodane do fabryki
		 */
		std::vector<Wrapper *> _objects;
};