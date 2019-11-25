#include "Fiszka.h"
#include <iostream>
#include <vector>

class Talia
{
    vector <Fiszka> talia[3];
public:
    Talia(string);

    Fiszka& getFiszka(int, int);
    int ile_fiszek_w_pliku(string);
    int ile_fiszek_w_talii(int);
    void wczytywanie_talii(string);
    void zapisywanie_talii(string);
    int string_na_int(string);
};
