#pragma once

//szablon klasy sluzacej do pozyskania ID skojarzonego wczesniej z podanym typem za pomoca makra DECLARE_TYPE_IDENTIFIER
template<typename T> class type2int;

//szablon klasy sluzacej do pozyskania typu skojarzonego wczesniej z podanym ID za pomoca makra DECLARE_TYPE_IDENTIFIER
template<int id> class int2type;

//makro sluzace do stworzenia klas szablonowych przypisujacych podany typ do podanego ID
#define DECLARE_TYPE_IDENTIFIER(T,id)\
template<>\
class type2int<T>\
{\
public:\
	static const int value=id;\
};\
template<>\
class int2type<id>\
{\
public:\
	typedef T type;\
};

