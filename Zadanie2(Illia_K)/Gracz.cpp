#include <iostream>
#include <fstream>
#include <vector>
#include<string>

using namespace std;

#include "Gracz.hpp"

void Gracz::Set_Name(Gracz* gracze)
{
    gracze[0].imie = "Bryanusz";
    gracze[1].imie = "Jessica ";
    gracze[2].imie = "Nepomucen";
}

void Gracz::Read_File(vector<string>& hasla)
{
    ifstream strum;
    strum.open("Data.txt");
    setlocale(LC_CTYPE, "Polish");
    while (!strum.eof())
    {
        string s;
        getline(strum, s);
        hasla.push_back(s);

    }
    strum.close();
    for (string item : hasla)
        cout << item << endl;
    cout << endl << endl;
}

void Gracz::textPlayers(int kolejka , Gracz* gracze)
{
    int i;
    cout << "\n";
    for (i = 0; i < 3; i++) {
        if (i == kolejka)
            cout << "\033[1;34m";
        cout << gracze[i].imie << "\t" << gracze[i].kasa << "\n";
        cout << "\033[0m";

    }
    cout << "\n";
}

int& Gracz::Kasa(Gracz* gracze, int& kolejka)
{
    return gracze[kolejka].kasa;
}

int& Gracz::Portfel(Gracz* gracze,int& kolejka)
{
    return gracze[kolejka].portfel;
}

int& Gracz::KOLO(Gracz* gracze,int& i)
{
    return gracze->Kolo[i];
}

string& Gracz::Name(Gracz* gracze, int& kolejka)
{
    return gracze[kolejka].imie;
}

string& Gracz::Haslo(Gracz* gracze)
{
    return gracze->haslo;
}

char Gracz::WczytajZnak()
{
    string letter;
    cin >> letter;
    while (letter.length() != 1)
    {
        cout << endl << "Type a single letter and press <enter>: ";
        cin >> letter;
    }
    for (auto& c : letter)  
        c = toupper(c);
    return letter[0];
}

char Gracz::WczytajWybor(Gracz* gracze)
{
    char wybor;
    wybor = gracze->WczytajZnak();
    while (wybor != '1' && wybor != '2')
    {
        cout << endl << "Wybierz [1-2]: ";
        cin >> wybor;
    }
    return wybor;
}

void Gracz::Do_While(int& i, int& n,int maska[100], Gracz* gracze,int& sa_spolgloski, int& kwota ,int& kolejka,char& wybor,string& proba,int& suma,string& rezultat,char& literka, int& zgadl)
{
    do
    {
        Show_Invisible_Word(maska, i, n, gracze->Haslo(gracze));
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
        gracze->textPlayers(kolejka, gracze);
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
        if (gracze->KOLO(gracze, i) == 0)
            rezultat = "Strata kolejki";
        if (gracze->KOLO(gracze, i) == -1)
            rezultat = "Bankrut";
        if (rezultat != "")
            cout << "\033[1;31m" << rezultat << "\033[0m" << endl;
        else
        {
            cout << "\033[1;34m" << gracze->KOLO(gracze, i) << "\033[0m" << endl;
            kwota = gracze->KOLO(gracze, i);
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
        cout << gracze->Name(gracze, kolejka) << ": Podaj litere" << endl;
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

            gracze->Kasa(gracze, kolejka) += kwota * zgadl;
            cout << endl << gracze->Name(gracze, kolejka) << "\033[1;32m " << gracze->Kasa(gracze, kolejka) << "\033[0m";
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
}

int Gracz::jestSamogloska(char& c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y')
        return 1;
    else
        return 0;
}

void Gracz::Invisible_Word(string& haslo, int maska[100], int& i, int& n)
{
    for (i = 0; i < n; i++)
    {
        if (haslo[i] == ' ')
            maska[i] = 0;
        else
            maska[i] = 1;
    }
}

void Gracz::Show_Invisible_Word(int maska[100], int& i, int& n, string& haslo)
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