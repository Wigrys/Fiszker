#include <iostream>

using namespace std;
#include <time.h>

class Fiszka
{
    int kiedy_sprawdzana;
    short stan;
    string przod;
    string tyl;
public:
    Fiszka(string, string, short = 0);
    Fiszka();
    void zamien_front_tyl();
    void wypisz_info();
    void zmien_stan(int);
    string getPrzod();
    string getTyl();
    int getStan();
    int getKiedy_sprawdzana();
    void setPrzod(string);
    void setTyl(string);
    void setStan(int);
    void setKiedy_sprawdzana(int);
};


