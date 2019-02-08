#pragma once

/**
*@fn find_pesel_crtl
*@brief funkcja obliczajaca sume kontrolna nr PESEL
*/
char find_pesel_crtl(const char *pesel);

/**
*@fn pesel_correct
*@brief funkcja sprawdzajaca czy nr PESEL jest poprawny (czy suma kontrolna jest poprawna)
*/
bool pesel_correct(const char *pesel);