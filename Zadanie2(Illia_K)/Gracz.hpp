class Gracz {
private:
    string imie;
    string haslo;
    int kasa = 0;
    int portfel = 0;
    int Kolo[16] = { -1, 0, 100, 200, 100, 200, 100, 200, 500, 500, 1000, 1000, 1500, 2000, 3000, 5000 };
public:
    void Set_Name(Gracz* gracze);
    void Read_File(vector<string>& hasla);
    void textPlayers(int kolejka, Gracz* gracze);
    int& Kasa(Gracz* gracze, int& kolejka);
    int& Portfel(Gracz* gracze , int& kolejka);
    int& KOLO(Gracz* gracze , int& i);
    string& Name(Gracz* gracze, int& kolejka);
    string& Haslo(Gracz* gracze);
    char WczytajZnak();
    char WczytajWybor(Gracz* gracze);
};
