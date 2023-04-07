#include <iostream>

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
