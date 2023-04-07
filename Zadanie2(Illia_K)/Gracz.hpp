class Gracz {
private:
    string imie;
    int kasa = 0;
    int portfel = 0;
    int Kolo[16] = { -1, 0, 100, 200, 100, 200, 100, 200, 500, 500, 1000, 1000, 1500, 2000, 3000, 5000 };
public:
    void Set_Name(Gracz* gracze);
    int KOLO(Gracz* gracze , int& i);
    void Kwota_KOLO(Gracz* gracze, int& i,int& kwota);
    void Change_porfel(Gracz* gracze,int& kolejka);
    void Kasa_Zero(Gracz* gracze, int& kolejka);
    void zgadl_kwota(Gracz* gracze, int& kolejka,int& zgadl , int& kwota);
    void Print_name(Gracz* gracze, int& kolejka);
    void textPlayers(int kolejka, Gracz* gracze);
    char WczytajZnak();
    char WczytajWybor(Gracz* gracze);
    void Read_File(vector<string>& hasla);
};
