#include "Talia.h"
#include <fstream>
#include <string>

Talia::Talia(string nazwa)
{
    talia[0].reserve(ile_fiszek_w_pliku(nazwa));
    talia[1].reserve(ile_fiszek_w_pliku(nazwa));
    talia[2].reserve(ile_fiszek_w_pliku(nazwa));
}

Fiszka& Talia::getFiszka(int ktora, int i)
{
    return talia[ktora][i];
}

int Talia::ile_fiszek_w_talii(int ktora)
{
    return talia[ktora].size();
}

int Talia::ile_fiszek_w_pliku(string nazwa_talii)
{
    fstream plik;
    int ile = 0;
    plik.open(("pliki\\" + nazwa_talii + ".txt").c_str(), ios::in);
    if(plik.good())
    {
        while(!plik.eof())
        {
            getline(plik, nazwa_talii);
            ile++;
        }
    }
    else
        return -1;
    plik.close();
    return ile;
}

void Talia::wczytywanie_talii(string nazwa_talii) //ca³¹ funkcjê trzeba przerobiæ, narazie zapisuje tylko w talii nr 0;
{
    fstream plik;
    plik.open(("pliki\\" + nazwa_talii + ".txt").c_str(), ios::in);
    if(plik.good())
    {
        for(int i=0 ; i < ile_fiszek_w_pliku(nazwa_talii) ; i++)
        {
            Fiszka nowa;
            string tekst;
            getline(plik, tekst, ',');
            nowa.setPrzod(tekst);
            getline(plik, tekst, ',');
            nowa.setTyl(tekst);
            getline(plik, tekst, ',');
            nowa.setKiedy_sprawdzana(string_na_int(tekst));
            getline(plik, tekst, '\n');
            nowa.setStan(string_na_int(tekst));
            talia[0].push_back(nowa);
        }
    }
    plik.close();
}

void Talia::zapisywanie_talii(string nazwa_talii) //ca³¹ funkcjê trzeba przerobiæ, narazie zapisuje tylko z talii nr 0;
{
    fstream plik;
    plik.open(("pliki\\" + nazwa_talii + ".txt").c_str(), ios::out);
    if(plik.good())
    {
        for(int i=0 ; i < ile_fiszek_w_talii(0) ; i++)
        {
            plik << talia[0][i].getPrzod() << ",";
            plik << talia[0][i].getTyl() << ",";
            plik << talia[0][i].getKiedy_sprawdzana() << ",";
            plik << talia[0][i].getStan();
            if(i!=ile_fiszek_w_talii(0)-1)
                 plik << endl;
        }
    }
    plik.close();
    return;
}

int Talia::string_na_int(string tekst)
{
    int liczba = 0;
    for(int i=tekst.length()-1, j=1 ; i>=0 ; i--, j*=10)
        liczba += (tekst[i]-48) * j;
    return liczba;
}
