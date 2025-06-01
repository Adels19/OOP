#include <iostream>
#include <cstring>

using namespace std;

class HotelReservation {
protected:
    int broj_denovi;
    int broj_lica;
    string ime;
    string prezime;
    int cena = 25;
public:

    HotelReservation(const string &ime, const string &prezime, int br_denovi, int br_lica) {
        this->ime = ime;
        this->prezime = prezime;
        this->broj_denovi = br_denovi;
        this->broj_lica = br_lica;
        this->cena = 25;
    }

    HotelReservation(const HotelReservation &hr) {
        this->broj_denovi = hr.broj_denovi;
        this->broj_lica = hr.broj_lica;
        this->ime = hr.ime;
        this->prezime = hr.prezime;
        this->cena = 25;
    }

    virtual int price() {
        return broj_denovi * broj_lica * 25;
    }

    virtual int price(int amount) {
        if (amount >= price()) {
            return amount - price();
        } else {
            cout << "Za vashata rezervacija treba da naplatite " << price() << endl;
            return -1;
        }
    }

};

class HalfBoardHotelReservation : public HotelReservation {
    int cena_pojadok = 5;
public:
    HalfBoardHotelReservation(string ime, string prezime, int broj_denovi, int broj_lica)
            : HotelReservation(ime, prezime, broj_denovi, broj_lica) {
        this->cena_pojadok = 5;
//        this->ime = ime;
//        this->prezime = prezime;
//        this->broj_lica = br_lica;
//        this->broj_denovi = br_denovi;
    }

    int price(int amount) override {
        int cena = HotelReservation::price() + broj_lica * 5;
        if (amount >= cena) {
            return amount - cena;
        }else{
            cout << "Za vashata rezervacija treba da naplatite " << cena << endl;
            return -1;
        }
    }
};

class Hotel {
    string ime_hotel;
    int saldo;
public:
    Hotel(const string &ime_hotel) {
        this->ime_hotel = ime_hotel;
        saldo = 0;
    }

    // & za da se povika od HotelReservation, a ne od baznata - HalfBoardHotelReservation
    int pay(HotelReservation &hr, int amount) {
        int kusur = hr.price(amount);
        if (kusur != -1) {
            saldo += amount - kusur;
        }
        return kusur;
    }


};

int main() {

    Hotel h("Bristol");
    HotelReservation *hr1 = new HotelReservation("Petko", "Petkovski", 5, 5);
    int cena = h.pay(*hr1, 1000);
    if (cena != -1)
        cout << "Kusur : " << cena << endl;
    HalfBoardHotelReservation *hr2 =
            new HalfBoardHotelReservation("Risto", "Ristovski", 5, 5);
    cena = h.pay(*hr2, 1000);
    if (cena != -1)
        cout << "Kusur : " << cena << endl;
    //покажувач кон основна класа покажува кон објект од изведена
    HotelReservation *hr3 = new HalfBoardHotelReservation("Ana", "Anovska", 4, 2);
    cena = h.pay(*hr3, 100);
    if (cena != -1)
        cout << "Kusur : " << cena << endl;
    HalfBoardHotelReservation hr4("Tome", "Tomovski", 5, 3);
    cena = h.pay(hr4, 1000);
    if (cena != -1)
        cout << "Kusur : " << cena << endl;
}
