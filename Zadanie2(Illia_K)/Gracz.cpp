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