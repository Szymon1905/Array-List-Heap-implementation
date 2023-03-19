
class Stary_Kopiec {
public:
    int *tablica;
    unsigned int rozmiar;

    Stary_Kopiec();

    ~Stary_Kopiec();

    void dodaj(int);

    void usun(int);

    bool sprawdzCzyIstnieje(int);

    void wydrukujKopiec();

    void poprawStrukture();

    bool czy_sie_powtarza(int);
};



