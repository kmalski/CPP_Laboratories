#pragma once

#include <iostream>

template <typename T>
class DynArray {
public:
	typedef T* Iterator;
	// class Iterator {
	// public:
	// 	Iterator(T *pointer) : _indexPointer(pointer) {}

	// 	void operator++() {
	// 		_indexPointer++;
	// 	}

	// 	bool operator!=(const Iterator &iter) {
	// 		return _indexPointer != iter._indexPointer;
	// 	}

	// 	T operator*() {
	// 		return *_indexPointer;
	// 	}

	// 	T * operator->() {
	// 		return _indexPointer;
	// 	}

	// private:
	// 	T *_indexPointer;
	// };

	DynArray(int size) : _size(size), _array(new  T[size]) {}

	DynArray(int size, const T *array) : _size(size), _array(new  T[size]) {
		for (int i = 0; i < size; i++) {
			_array[i] = array[i];
		}
	}

	~DynArray() {
		delete[] _array;
	}

	int size() const {
		return _size;
	}

	T & operator[](int index) {
		return _array[index];
	}

	const T & operator[](int index) const {
		return _array[index];
	}

	Iterator begin() {
		return Iterator(_array);
	}

	Iterator end() {
		return Iterator(_array + _size);
	}

private:
	int _size;
	T *_array;

};

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
