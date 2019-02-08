#include "check_pesel.h"

char find_pesel_crtl(const char *pesel) {
    const int weights[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int crtl = 0;
    for (int i = 0; i < 10; i++) {
        crtl += weights[i] * (pesel[i] - '0'); 
    }
    crtl %= 10;
    crtl = 10 - crtl;
    if(crtl == 10) {
        crtl = 0;
    }
    return crtl + '0';
}

bool pesel_correct(const char *pesel) {
    return find_pesel_crtl(pesel) == pesel[10];
}