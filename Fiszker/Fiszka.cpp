#include "Fiszka.h"
#include <conio.h>

Fiszka::Fiszka(string przodx, string tylx, short stanx)
{
    przod = przodx;
    tyl = tylx;
    kiedy_sprawdzana = time(NULL);
    stan = stanx;
}

Fiszka::Fiszka()
{
    kiedy_sprawdzana = time(NULL);
    stan = 0;
}

void Fiszka::wypisz_info()
{
    cout << przod << " - " << tyl << "\tdodany: " << kiedy_sprawdzana << "\tstan: " << stan << endl;
}

void Fiszka::zamien_front_tyl()
{
    string chwilowy = przod;
    przod = tyl;
    tyl = chwilowy;
}

void Fiszka::zmien_stan(int opcja)
{
    stan = opcja;
}

string Fiszka::getPrzod()
{
    return przod;
}

string Fiszka::getTyl()
{
    return tyl;
}

int Fiszka::getStan()
{
    return stan;
}
int Fiszka::getKiedy_sprawdzana()
{
    return kiedy_sprawdzana;
}

void Fiszka::setPrzod(string x)
{
    przod = x;
}
void Fiszka::setTyl(string x)
{
    tyl = x;
}
void Fiszka::setStan(int x)
{
    stan = x;
}
void Fiszka::setKiedy_sprawdzana(int x)
{
    kiedy_sprawdzana = x;
}
