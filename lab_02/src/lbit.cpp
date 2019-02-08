#include <iostream>
#include "lbit.h"

void resetBits(unsigned char *bits, int mask, int size){
    int length = size / 8;

    for(int i = 0; i < length; i++){
        bits[i] = (unsigned char)(mask);
    }
}

void printBits(const unsigned char *bits, int start, int end){
    if(end == -1){
        end = start;
        start = 0;
    }
    for(int i = start; i < end; i++){
        std::cout<<getBit(bits, i);
        if(i != start && (i+1) % 8 == 0){
            std::cout<<" ";
        }
    }
    std::cout<<std::endl;
}

void flipBit(unsigned char *bits, int position){
    if(getBit(bits, position)){
        setBit(bits, position, 0);
    }
    else{
        setBit(bits, position, 1);
    }
}

void setBit(unsigned char *bits, int position, int value){
    int positionInArray = position / 8;
    int bitPosition = position % 8;

    if(value){
        bits[positionInArray] = bits[positionInArray] | (1 << bitPosition);
    }
    else{
        bits[positionInArray] = bits[positionInArray] & ~(1 << bitPosition);
    }
}

int getBit(const unsigned char *bits, int position){
    int positionInArray = position / 8;
    int bitPosition = position % 8;

    return (bits[positionInArray] & (1 << bitPosition)) != 0;
}