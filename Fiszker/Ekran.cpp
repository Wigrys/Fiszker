#include "Ekran.h"
#include <string>
#include <cstdlib>
#include <windows.h>

extern bool koniec;

void Ekran::ustaw_wskaznik(int x, int y)
{
    COORD gdzie;
    gdzie.X = x;
    gdzie.Y = y;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), gdzie);
    pokaz_wskaznik();
}

void Ekran::ukryj_wskaznik()
{
    ::HANDLE hConsoleOut =::GetStdHandle( STD_OUTPUT_HANDLE );
    ::CONSOLE_CURSOR_INFO hCCI;
    ::GetConsoleCursorInfo( hConsoleOut, & hCCI );
    hCCI.bVisible = FALSE;
    ::SetConsoleCursorInfo( hConsoleOut, & hCCI );
}

void Ekran::pokaz_wskaznik()
{
    ::HANDLE hConsoleOut =::GetStdHandle( STD_OUTPUT_HANDLE );
    ::CONSOLE_CURSOR_INFO hCCI;
    ::GetConsoleCursorInfo( hConsoleOut, & hCCI );
    if( hCCI.bVisible != TRUE )
    {
        hCCI.bVisible = TRUE;
        ::SetConsoleCursorInfo( hConsoleOut, & hCCI );
    }
}

void Ekran::wyczysc()
{
    system( "cls" );
    int ile_znakow = szerokosc_ekranu * wysokosc_ekranu;
    tresc.assign(ile_znakow, znak_tla);

    for(int i = 0 ; i < wysokosc_ekranu ; i++)
    {
        tresc[(i+1)*szerokosc_ekranu - 1] = '\n';
    }
}

void Ekran::wyswietl()
{
    system("cls");
    cout << tresc << flush;
}

void Ekran::wypisz(int kolumna, int rzad, const string tekst)
{
    tresc.replace((szerokosc_ekranu*rzad)+kolumna, tekst.length(), tekst);
}

void Ekran::wypisz(int kolumna, int rzad, char znak, int ile)
{
    tresc.replace((szerokosc_ekranu*rzad)+kolumna, ile, ile, znak);
}

void Ekran::wyswietl_menu()
{
    wyczysc();
    rysuj_obramowke(wysokosc_ekranu/8, 3);
    rysuj_obramowke(wysokosc_ekranu/8+dlugosc_ramki_menu, 3);
    rysuj_obramowke(wysokosc_ekranu/8+dlugosc_ramki_menu*2, 3);
    rysuj_obramowke(wysokosc_ekranu/8+dlugosc_ramki_menu*3, 3);
    tekst_w_ramce(1, "1.Ucz sie fiszek.");
    tekst_w_ramce(2, "2.Importuj talie.");
    tekst_w_ramce(3, "3.Eksportuj talie.");
    tekst_w_ramce(4, "Nacisnij ESC, aby wyjsc.");
    wyswietl();
}

void Ekran::wyswietl_wczytywanie_talii()
{
    wyczysc();
    rysuj_obramowke(3, 3);
    tekst_w_ramce(1, "Wpisz nazwe talii:");
    wyswietl();
}

void Ekran::wyswietl_odgadywanie(int dlugosc)
{
    wyczysc();
    rysuj_obramowke(wysokosc_ekranu/8, dlugosc);
    rysuj_obramowke(wysokosc_ekranu/8 + dlugosc+dlugosc_ramki_menu, dlugosc);
    string dolny_pasek = "     1.ZLE                  |          2.POWTORZYC          |                3.DOBRZE     ";
    wypisz(0, wysokosc_ekranu-2, '-');
    wypisz(0, wysokosc_ekranu-1, dolny_pasek);
    wypisz(0, wysokosc_ekranu, '-');
    wyswietl();
}

void Ekran::wyswietl_importowanie()
{

}

void Ekran::wyswietl_eksportowanie()
{

}

void Ekran::zakoncz_program()
{
    exit(0);
}

void Ekran::menu()
{
    ukryj_wskaznik();
    wyswietl_menu();
    int wybor = 0;
    wybor = _getch();
    switch (wybor)
    {
    case '1':
        odgadywanie();
        break;
    case '2':
        importowanie();
        break;
    case '3':
        eksportowanie();
        break;
    case 27:
        zakoncz_program();
        break;
    default:
        menu();
        break;
    }
}

string Ekran::pobieranie_nazwy_talii()
{
    string nazwa_talii;
    wyswietl_wczytywanie_talii();
    ustaw_wskaznik(szerokosc_ekranu/2-10, 9);
    cin >> nazwa_talii;
    ukryj_wskaznik();
    return nazwa_talii;
}

void Ekran::odgadywanie() //ca³a funkcja do przerobienia
{
    string nazwa_obecnej_talii = pobieranie_nazwy_talii();
    short ktory;
    Talia odgadywana(nazwa_obecnej_talii);
    odgadywana.wczytywanie_talii(nazwa_obecnej_talii);
    wyswietl_odgadywanie();
    for(int i=0 ; i<odgadywana.ile_fiszek_w_talii(0) ; i++)
    {
        wyczysc_obramowke();
        tekst_w_ramce_fiszka(0, odgadywana.getFiszka(0 ,i));
        if(_getch() != 27)
        {
            tekst_w_ramce_fiszka(1, odgadywana.getFiszka(0 ,i));
            do
            {
                ktory = _getch();
            }
            while(ktory!='1' && ktory!='2' && ktory!='3' && ktory!=27);
            switch(ktory)
            {
            case '1':
                (odgadywana.getFiszka(0, i)).zmien_stan(1);
                odgadywana.zapisywanie_talii(nazwa_obecnej_talii);
                break;
            case '2':
                (odgadywana.getFiszka(0, i)).zmien_stan(2);
                odgadywana.zapisywanie_talii(nazwa_obecnej_talii);
                break;
            case '3':
                (odgadywana.getFiszka(0, i)).zmien_stan(3);
                odgadywana.zapisywanie_talii(nazwa_obecnej_talii);
                break;
            case 27:
                menu();
                break;
            }
        }
        else
            menu();
    }
}

void Ekran::importowanie()
{

}

void Ekran::eksportowanie()
{

}

void Ekran::rysuj_obramowke(int rzad, int dlugosc)
{
    string boki = "||";
    boki.insert(1, (szerokosc_ekranu/2)-2, ' ');
    wypisz((szerokosc_ekranu/4), rzad, '-', szerokosc_ekranu/2);
    for(int i=0 ; i<dlugosc ; i++)
        wypisz((szerokosc_ekranu/4), i+rzad+1, boki);
    wypisz((szerokosc_ekranu/4), rzad + dlugosc + 1, '-', szerokosc_ekranu/2);
}

void Ekran::tekst_w_ramce(int ktory, string tekst)
{
    wypisz((szerokosc_ekranu/2)-tekst.length()/2-1, (wysokosc_ekranu/8+2)*ktory, tekst);
}

void Ekran::tekst_w_ramce_fiszka(bool ktory, Fiszka fiszka)
{
    string tekst = fiszka.getPrzod();
    string formulka = "Wcisnij dowolny klawisz, aby kontynuowac";
    wypisz((szerokosc_ekranu/2)-tekst.length()/2-1, (wysokosc_ekranu/4), tekst);
    wypisz((szerokosc_ekranu/2)-formulka.length()/2-1, (wysokosc_ekranu/2)-1, formulka);
    if(ktory == 1)
    {
        string tekst = fiszka.getTyl();
        wypisz((szerokosc_ekranu/2)-tekst.length()/2-1, (wysokosc_ekranu/2+4), tekst);
    }
    wyswietl();
}

void Ekran::wyczysc_obramowke()
{
    wypisz(23, (wysokosc_ekranu/8+3), ' ', szerokosc_ekranu/2-2);
    wypisz(23, (wysokosc_ekranu/8+13), ' ', szerokosc_ekranu/2-2);
    wyswietl();
}
