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

int jestSamogloska(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
        return 1;
    else
        return 0;
}

void Invisible_Word(string& haslo , int maska[100], int& i, int& n)
{
    for (i = 0; i < n; i++)
    {
        if (haslo[i] == ' ')
            maska[i] = 0;
        else
            maska[i] = 1;
    }
}

void Show_Invisible_Word(int maska[100],int&i,int&n,string &haslo)
{
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
}

int main()
{
    SetConsoleOutputCP(1250);
    //SetConsoleOutputCP(CP_UTF8);
    Gracz* gracze = new Gracz[3];
    int kolejka = 0 , i , n , maska[100] , suma = 0 , zgadl = 0 , sa_spolgloski = 0 , kwota = 0;
    string proba;
    char literka , wybor;
    srand(time(NULL));
    string rezultat;
    vector<string> hasla;
    int j;
    gracze->Read_File(*&hasla);
    assert(hasla.size() > 0);
    j = rand() % hasla.size();
    gracze->Haslo(gracze) = hasla[j];
    n = gracze->Haslo(gracze).size();
    gracze->Set_Name(gracze);
    Invisible_Word(gracze->Haslo(gracze), maska, i, n);

    do
    {  
        Show_Invisible_Word(maska,i,n,gracze->Haslo(gracze));
        sa_spolgloski = 0;
        kwota = 0;
        for (i = 0; i < n; i++)
            if ((!jestSamogloska(gracze->Haslo(gracze)[i])) && (maska[i]))
            {
                sa_spolgloski = 1;
                break;
            }
        if (sa_spolgloski)
            cout << " -- Spolgloski sa --" << endl;
        gracze->textPlayers(kolejka , gracze);
        cout << "1. zgaduj haslo" << endl;
        cout << "2. krecenie kolem" << endl;
        wybor = gracze->WczytajWybor(gracze);
        if (wybor == '1')
        {
            cout << "Podaj haslo" << endl;
            getline(cin >> ws, proba);  
            for (auto& c : proba) 
                c = toupper(c);
            if (gracze->Haslo(gracze) == proba) {
                cout << endl << " !!!!!!!!!! =======   WYGRANA ========== !!!!!!!!!!!!!" << endl;
                gracze->Portfel(gracze, kolejka) += gracze->Kasa(gracze, kolejka);
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
        if (gracze->KOLO(gracze,i) == 0)
            rezultat = "Strata kolejki";
        if (gracze->KOLO(gracze,i) == -1)
            rezultat = "Bankrut";
        if (rezultat != "")
            cout << "\033[1;31m" << rezultat << "\033[0m" << endl;
        else
        {
            cout << "\033[1;34m" << gracze->KOLO(gracze,i) << "\033[0m" << endl;
            kwota = gracze->KOLO(gracze,i);
        }
        if ((gracze->KOLO(gracze, i) == 0) || (gracze->KOLO(gracze, i) == -1))
        {
            if (gracze->KOLO(gracze, i) == -1)
                gracze->Kasa(gracze, kolejka) = 0;
            kolejka = (kolejka + 1) % 3;
            suma = 1;
            cout << endl << "=================================================" << endl;
            continue;
        }
        cout << gracze->Name(gracze,kolejka) << ": Podaj litere" << endl;
        literka = gracze->WczytajZnak();
        //
        cout << literka << endl;
        //
        zgadl = 0;
        if (jestSamogloska(literka))
            cout << "samogloska" << endl;
        else
            cout << "spolgloska" << endl;
        for (i = 0; i < n; i++)
        {
            if ((gracze->Haslo(gracze)[i] == literka) && (maska[i] == 1)) {
                maska[i] = 0;
                zgadl++;
            }
        }
        if (zgadl)
        {
            cout << "OK" << endl;

            gracze->Kasa(gracze,kolejka) += kwota * zgadl;
            cout << endl << gracze->Name(gracze,kolejka) << "\033[1;32m " << gracze->Kasa(gracze,kolejka) << "\033[0m";
        }
        else {
            cout << "Zle!";
            kolejka = (kolejka + 1) % 3;
            cout << endl << "=================================================" << endl;
            suma = 1;
            continue;
        }
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