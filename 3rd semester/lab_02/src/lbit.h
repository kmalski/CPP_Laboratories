#pragma once

#include <iostream>
/**
*@fn resetBits
*@brief funkcja ustawiajace bity na podanym zakresie wedlug podanej maski
*/
void resetBits(unsigned char *bits, int mask, int size);

/**
*@fn printBits
*@brief funkcja wypisujaca bity na podanym zakresie
*/
void printBits(const unsigned char *bits, int start, int end = -1);

/**
*@fn flipBit
*@brief funkcja zamieniajaca bit na przeciwny na podanej pozycji
*/
void flipBit(unsigned char *bits, int position);

/**
*@fn setBit
*@brief funkcja ustawiajaca bit na podanej pozycji na podana wartosc
*/
void setBit(unsigned char *bits, int position, int value);

/**
*@fn getBit
*@brief funkcja pobierajaca bit na podanej pozycji
*/
int getBit(const unsigned char *bits, int position);