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
    gracze->Invisible_Word(gracze->Haslo(gracze), maska, i, n);
    gracze->Do_While(i,n,maska,gracze,sa_spolgloski,kwota,kolejka,wybor,proba,suma,rezultat,literka,zgadl);
    cout << "BRAWO!";
    exit(0);
    gracze->textPlayers(kolejka, gracze);
    Beep(523, 500);
}