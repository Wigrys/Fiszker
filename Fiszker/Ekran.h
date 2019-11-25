#include "Talia.h"
#include <iostream>
#include <conio.h>

using namespace std;

class Ekran
{
    static const int szerokosc_ekranu = 90;
    static const int wysokosc_ekranu = 25;
    static const int dlugosc_ramki_menu = 5;
    string tresc;
    char znak_tla;
public:
    Ekran(char znak = ' ')
    {
        znak_tla = znak;
        wyczysc();
    }
    void ustaw_wskaznik(int, int);
    void ukryj_wskaznik();
    void pokaz_wskaznik();
    void wyczysc();
    void wyswietl();
    void wyswietl_menu();
    void wyswietl_wczytywanie_talii();
    void wyswietl_odgadywanie(int=dlugosc_ramki_menu);
    void wyswietl_importowanie();
    void wyswietl_eksportowanie();
    void zakoncz_program();
    void menu();
    string pobieranie_nazwy_talii();
    void odgadywanie();
    void importowanie();
    void eksportowanie();
    void wypisz(int, int, const string);
    void wypisz(int, int, char, int = szerokosc_ekranu);
    void rysuj_obramowke(int, int);
    void wyczysc_obramowke();
    void tekst_w_ramce(int, string);
    void tekst_w_ramce_fiszka(bool, Fiszka);
};
