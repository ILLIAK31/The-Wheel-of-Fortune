#include <iostream>
#include <fstream>
#include <vector>
#include<string>

using namespace std;

#include "Gracz.hpp"

int Gracz::KOLO(Gracz* gracze,int& i)
{
    if (gracze->Kolo[i] == 0)
        return 0;
    if (gracze->Kolo[i] == -1)
        return -1;
}

void Gracz::Kwota_KOLO(Gracz* gracze, int& i, int& kwota)
{
    cout << "\033[1;34m" << Kolo[i] << "\033[0m" << endl;
    kwota = Kolo[i];
}

void Gracz::Set_Name(Gracz* gracze)
{
    gracze[0].imie = "Bryanusz";
    gracze[1].imie = "Jessica ";
    gracze[2].imie = "Nepomucen";
}

void Gracz::Change_porfel(Gracz* gracze,int& kolejka)
{
    gracze[kolejka].portfel += gracze[kolejka].kasa;
}

void Gracz::Kasa_Zero(Gracz* gracze,int& kolejka)
{
    gracze[kolejka].kasa = 0;
}

void Gracz::Print_name(Gracz* gracze, int& kolejka)
{
    cout << gracze[kolejka].imie << ": Podaj litere" << endl;
}

void Gracz::zgadl_kwota(Gracz* gracze, int& kolejka, int& zgadl , int& kwota)
{
    gracze[kolejka].kasa += kwota * zgadl;
    cout << endl << gracze[kolejka].imie << "\033[1;32m " << gracze[kolejka].kasa << "\033[0m";
}

void Gracz::textPlayers(int kolejka , Gracz* gracze)
{
    int i;
    cout << "\n";
    for (i = 0; i < 3; i++) {
        if (i == kolejka) {
            cout << "\033[1;34m";
        }
        cout << gracze[i].imie << "\t" << gracze[i].kasa << "\n";
        cout << "\033[0m";

    }
    cout << "\n";
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
