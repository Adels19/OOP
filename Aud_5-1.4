#include <iostream>
#include <cstring>

using namespace std;

class Ucenik {
private:
    char *ime;
    float prosek;
    int godina;
public:

    //default c
    Ucenik() {
        this->ime = new char[6];
        strcpy(this->ime, "Adela");
        this->prosek = 0.0;
        this->godina = 1;
    }

    // w arguments c
    Ucenik(const char *ime, float prosek, int godina) { // bitno e const char!!
        this->prosek = prosek;
        this->godina = godina;
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
    }

    // copy constructor
    Ucenik(const Ucenik &u) {
        this->prosek = u.prosek;
        this->godina = u.godina;
        ime = new char[strlen(u.ime) + 1];
        strcpy(this->ime, u.ime);
    }

    // destructor
    ~Ucenik() {
        delete[] ime;
    }

    // operator =
    Ucenik &operator=(const Ucenik &u) {
        if (this != &u) {
            delete[] ime;
            ime = new char[strlen(u.ime) + 1];
            strcpy(this->ime, u.ime);
            this->prosek = u.prosek;
            this->godina = u.godina;
        }
        return *this;
    }

    friend ostream &operator<<(ostream &o, const Ucenik &u) {
        return o << "Ime: " << u.ime << ", godina: " << u.godina << ", prosek: " << u.prosek << endl;
    }


    // prefiksen
    Ucenik &operator++() {
        godina++;       // prvo ja zgolemuva godinata
        return *this;   // go vraka modificiraniot objekt (ovaj)
    }

    // postfiksen
    Ucenik operator++(int) {
        Ucenik tmp = *this;     // kreira kopija od tekoven objekt
        godina++;               // ja zgolemuva god. na originalnoto
        return tmp;             // ja vraka kopijata (stara verzija)
    }

    friend class Paralelka;

    friend bool operator>(const Ucenik &u1, const Ucenik &u2);

    float getProsek() const {
        return prosek;
    }

};

// za da moze sporedba od objekt
bool operator>(const Ucenik &u1, const Ucenik &u2) {
    return (u1.prosek > u2.prosek);    // se koristi vo najgolem prosek funkcijata
}

class Paralelka {
    Ucenik *ucenici;
    int vkupno;
public:

    // default c
    Paralelka() {
        this->vkupno = 0;
        this->ucenici = nullptr;
    }

    // w arguments c
    Paralelka(Ucenik *ucenici, int vkupno) {
        this->vkupno = vkupno;
        this->ucenici = new Ucenik[vkupno];
        for (int i = 0; i < vkupno; i++) {
            this->ucenici[i] = ucenici[i];
        }
    }

    // copy constr
    Paralelka(const Paralelka &p) {
        this->vkupno = p.vkupno;
        this->ucenici = new Ucenik[vkupno];
        for (int i = 0; i < vkupno; i++) {
            this->ucenici[i] = p.ucenici[i];
        }
    }

    ~Paralelka() {
        delete[] ucenici;
    }

    // Dodavanje nov ucenik vo nizata ucenici
    Paralelka &operator+=(const Ucenik &u) {
        Ucenik *tmp = new Ucenik[vkupno + 1];   // se kreira nova d.a.niza
        for (int i = 0; i < vkupno; i++) { // kopiranje na postoecki ucenici
            tmp[i] = ucenici[i];    // tuka e potreben operator = vo Ucenik klasa
        }
        tmp[vkupno] = u;    // noviot ucenik u se dodava na poslednata pozicija
        delete[] ucenici;// se osloboduva stara niza
        ucenici = tmp;  // ucenici pokazuva kon tmp
        vkupno++;
        return *this;   // vraka referenca kon tekoven objekt Paralelka
    }

    // pecatime ucenici
    friend ostream &operator<<(ostream &o, const Paralelka &p) {
        for (int i = 0; i < p.vkupno; i++) {
            o << p.ucenici[i];
        }
        return o;
    }

    Paralelka &operator++() {
        for (int i = 0; i < vkupno; i++) {
            ++ucenici[i];
        }
        return *this;
    }

    Paralelka operator++(int) {
        Paralelka tmp = *this;
        for (int i = 0; i < vkupno; i++) {
            ucenici[i]++;
        }
        return tmp;
    }

    void nagradi() {
        for (int i = 0; i < vkupno; i++) {
            if (ucenici[i].getProsek() == 10.0) {
                cout << ucenici[i];
            }
        }
    }

    void najvisokProsek() {

        Ucenik tmpU = ucenici[0];   // pretpostavuva deka prviot ima najvisok prosek
        for (int i = 0; i < vkupno; i++) {
            if (ucenici[i] > tmpU) {    // blagodarenie na bool operator >
                tmpU = ucenici[i];
            }
        }
        cout << "Najvisok prosek vo paralelkata:" << tmpU.getProsek() << endl;
    }


};


int main() {

    Ucenik u1("Martina Martinovska", 9.5, 3);
    Ucenik u2("Darko Darkoski", 7.3, 2);
    Ucenik u3("Angela Angelovska", 10, 3);

    Paralelka p;
    p += u1;
    p += u2;
    p += u3;

    cout << p;
    cout << "Nagradeni:" << endl;
    p.nagradi();
    cout << endl;
    p.najvisokProsek();
    cout << endl;

    u2++;
    cout << p;
    cout << endl;
    p++;
    cout << p;

    return 0;
}
