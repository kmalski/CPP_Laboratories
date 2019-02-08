#include "Bit.h"

Bit::Bit(int position, unsigned char *bit) {
    _bit = bit;
    _position = position;
}

void Bit::operator=(bool state) {
    if(state){
        *_bit = *_bit | (1 << _position);
    } else {
        *_bit = *_bit & ~(1 << _position);
    }
}

Bit::operator bool() const {
    return (*_bit & (1 << _position)) != 0;
}
