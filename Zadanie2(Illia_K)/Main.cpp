#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include <stdlib.h>     
#include <time.h>      
#include <string>  
#include <vector>
#include <cstring>
#include <cassert>
#include <locale.h>

using namespace std;

#include "Gracz.hpp"

Gracz* gracze = new Gracz[3];
int kolejka = 0;
int Kolo[] = { -1, 0, 100, 200, 100, 200, 100, 200, 500, 500, 1000, 1000, 1500, 2000, 3000, 5000 };

int jestSamogloska(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
        return 1;
    else
        return 0;

}

int main()
{
    SetConsoleOutputCP(1250);
    int i , n , maska[100] , suma = 0 , zgadl = 0 , sa_spolgloski = 0 , kwota = 0;
    string haslo , proba;
    char literka , wybor;
    srand(time(NULL));
    string rezultat;
    vector<string> hasla;
    int j;

    gracze->Read_File(*&hasla);

    for (string item : hasla)
        cout << item << endl;
    cout << endl << endl;

    assert(hasla.size() > 0);
    j = rand() % hasla.size(); // losujemy j-te haslo z przedzialu 0 ... size - 1
    //cout << hasla[j];
    haslo = hasla[j];
    n = haslo.size();

    gracze[0].imie = "Bryanusz";
    gracze[1].imie = "Jessica ";
    gracze[2].imie = "Nepomucen";

    for (i = 0; i < n; i++)
    {
        if (haslo[i] == ' ')
            maska[i] = 0;
        else
            maska[i] = 1;
    }

    do
    {
        // cout << "\033[2J";

        cout << "\033[47m" << "\033[31m";
        for (i = 0; i < n; i++)
        {

            if (maska[i] == 1)
                cout << ".";
            else
                cout << haslo[i];
        }

        cout << "\033[0m";
        cout << endl;

        sa_spolgloski = 0;
        kwota = 0;

        for (i = 0; i < n; i++)
            if ((!jestSamogloska(haslo[i])) && (maska[i]))
            {
                sa_spolgloski = 1;
                break;
            }

        if (sa_spolgloski)
            cout << " -- Spolgloski sa --" << endl;


        //cout << gracze[kolejka].imie << " " << endl;
        gracze->textPlayers(kolejka , gracze);

        cout << "1. zgaduj haslo" << endl;
        cout << "2. krecenie kolem" << endl;

        // TODO tylko 1 i 2, nie mozna wprowadzac liter

        wybor = gracze->WczytajWybor(gracze);

        if (wybor == '1')
        {
            cout << "Podaj haslo" << endl;
            getline(cin >> ws, proba);  // wczytanie z klawiatury string z uwzgl. whitespa
            for (auto& c : proba)  // & zapamietuje modyfikacje w petli & - referencja
                c = toupper(c);
            if (haslo == proba) {
                cout << endl << " !!!!!!!!!! =======   WYGRANA ========== !!!!!!!!!!!!!" << endl;
                gracze[kolejka].portfel += gracze[kolejka].kasa;
                break;
            }
            else
            {
                kolejka = (kolejka + 1) % 3;
                suma = 1;
                cout << endl << " !!!!!!!!!! =======   ZLE ========== !!!!!!!!!!!!!" << endl;
                cout << endl << "=================================================" << endl;
                continue;


            }



        }


        rezultat = "";
        i = rand() % 15;
        if (Kolo[i] == 0)
            rezultat = "Strata kolejki";
        if (Kolo[i] == -1)
            rezultat = "Bankrut";
        if (rezultat != "")
            cout << "\033[1;31m" << rezultat << "\033[0m" << endl;
        else
        {
            cout << "\033[1;34m" << Kolo[i] << "\033[0m" << endl;
            kwota = Kolo[i];
        }

        // Strata kolejki i bankrut
        if ((Kolo[i] == 0) || (Kolo[i] == -1))
        {
            if (Kolo[i] == -1) // bankrut
                gracze[kolejka].kasa = 0;

            kolejka = (kolejka + 1) % 3;
            suma = 1;
            cout << endl << "=================================================" << endl;

            // TODO
            // sleep for
            // kupowanie samoglosek

            continue;

        }





        cout << gracze[kolejka].imie << ": Podaj litere" << endl;



        literka = gracze->WczytajZnak();


        zgadl = 0;

        if (jestSamogloska(literka))
            cout << "samogloska";
        else
            cout << "spolgloska";
        cout << endl;

        for (i = 0; i < n; i++)
        {
            if ((haslo[i] == literka) && (maska[i] == 1)) {
                maska[i] = 0;
                zgadl++;
            }
        }

        if (zgadl)
        {
            cout << "OK";
            gracze[kolejka].kasa += kwota * zgadl;

            cout << endl << gracze[kolejka].imie << "\033[1;32m " << gracze[kolejka].kasa << "\033[0m";


        }
        else {
            cout << "Zle!";
            // strata kolejki
            kolejka = (kolejka + 1) % 3;
            cout << endl << "=================================================" << endl;
            suma = 1;
            continue;
        }




        cout << endl;



        suma = 0;

        for (i = 0; i < n; i++)
        {
            suma += maska[i];
        }



    } while (suma);
    cout << "BRAWO!";
    exit(0);

    gracze->textPlayers(kolejka, gracze);
    Beep(523, 500);
}