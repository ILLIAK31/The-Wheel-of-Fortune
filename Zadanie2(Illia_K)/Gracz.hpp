class Gracz {
public:
    string imie;
    int kasa = 0;
    int portfel = 0;
    void textPlayers(int kolejka, Gracz* gracze);
    char WczytajZnak();
    char WczytajWybor(Gracz* gracze);
    void Read_File(vector<string>& hasla);
};
