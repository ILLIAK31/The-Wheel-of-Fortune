#include <iostream>
#include <fstream>
#include <vector>
#include<string>

using namespace std;

#include "Gracz.hpp"

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
}
