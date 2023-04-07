class Gracz {
private:
    string imie;
    int kasa = 0;
    int portfel = 0;
public:
    void Set_Name(Gracz* gracze);
    void Change_porfel(Gracz* gracze,int& kolejka);
    void Kasa_Zero(Gracz* gracze, int& kolejka);
    void zgadl_kwota(Gracz* gracze, int& kolejka,int& zgadl , int& kwota);
    void Print_name(Gracz* gracze, int& kolejka);
    void textPlayers(int kolejka, Gracz* gracze);
    char WczytajZnak();
    char WczytajWybor(Gracz* gracze);
    void Read_File(vector<string>& hasla);
};
