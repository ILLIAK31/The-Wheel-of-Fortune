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
    void Show_Invisible_Word(int maska[100], int& i, int& n, string& haslo);
    void Invisible_Word(string& haslo, int maska[100], int& i, int& n);
    void Do_While(int& i, int& n, int maska[100], Gracz* gracze, int& sa_spolgloski, int& kwota, int& kolejka, char& wybor, string& proba, int& suma, string& rezultat, char& literka, int& zgadl);
    int& Kasa(Gracz* gracze, int& kolejka);
    int& Portfel(Gracz* gracze , int& kolejka);
    int& KOLO(Gracz* gracze , int& i);
    int jestSamogloska(char& c);
    string& Name(Gracz* gracze, int& kolejka);
    string& Haslo(Gracz* gracze);
    char WczytajZnak();
    char WczytajWybor(Gracz* gracze);
    
};
