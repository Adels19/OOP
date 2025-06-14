#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

// 3 bitni raboti:
// define the error/exception class
// throw (in the constructor)

#include <fstream>

class NegativeValueException {
private:
    float cena;
public:
    void message() {
        cout << "Nevalidna discount cena" << endl;
    }
};

// apstraktna
class Discount {
public:
    static float euro;
    static float dollar;

    virtual ~Discount() {}


    //Овие се апстрактни методи во базната класа Discount,
    //што значи дека секоја класа што наследува од Discount мора да ги имплементира.
    //obavezno virtual stavi = 0
    virtual float discount_price() = 0;

    virtual float price() = 0;

    virtual void print_rule() = 0;
};

float Discount::euro = 61.7;
float Discount::dollar = 44.5;

// ne treba da nasleduva od Discount no ke vidime zosto
// затоа што: Product е основна класа за сите производи,
// но не секој Product има попуст (пример: FoodProduct нема попуст).
class Product {
    // protected a ne private
protected:
    string imeProizvod;
    float cenaProizvod;
public:

    // inicijaliziraj i default const! i float const!
    Product(const string &imeProizvod = " ", const float cenaProizvod = 0) {
        this->imeProizvod = imeProizvod;
        this->cenaProizvod = cenaProizvod;
    }

    Product(const Product &copy) {
        this->imeProizvod = copy.imeProizvod;
        this->cenaProizvod = copy.cenaProizvod;
    }

    // za da rabotime direktno so ovaj price, getPrice
    float getPrice() {
        return cenaProizvod;
    }

    void changePrice(float cp) {
        if (cp < 0)
            throw NegativeValueException();
        this->cenaProizvod = cp;

    }

    void print() {
        cout << "Product{ name=" << imeProizvod << ", price=" << cenaProizvod << "}" << endl;
    }


};


class FoodProduct : public Product, public Discount {
private:
    float calories;
public:
    FoodProduct(const string &imeProizvod = " ", const float cenaProizvod = 0, const float calories = 0)
            : Product(imeProizvod, cenaProizvod) {
        this->calories = calories;
    }

    float discount_price() {
        return cenaProizvod;
    }

    float price() {
        return getPrice();  // od bazna klasa Product
    }

    void print_rule() {
        cout << "Nema popust za proizvodite od tip na hrana" << endl;
    }


};

class Drinks : public Product, public Discount {
private:
    string brend;
    bool alcoholic;
public:

    Drinks(const string imeProizvod = " ", float cenaProizvod = 0, const string brend = "", const bool alkololno = true)
            : Product(imeProizvod, cenaProizvod) {
        this->brend = brend;
        this->alcoholic = alkololno;
    }

    float discount_price() {
        // euro e static a ne del od klasa
        if (alcoholic && getPrice() / Discount::euro > 20) {
            return getPrice() * 0.95;
            // zosto getPrice() a ne cenaProizvod - poprecizno i poelegantno
        } else if (!alcoholic && brend == "Coca-Cola") {
            return getPrice() * 0.9;
        } else {
            return getPrice();
//             return cenaProizvod; jas vaka segdw rabotev..
        }
    }

    float price() {
        return getPrice();
    }

    void print_rule() {
        cout << "Site alkoholni pijaloci poskapi od 20 evra imaat popust od 5 %, "
                "dodeka pak nealkoholnite od brendot Coca - Cola imaat popust od 10 % " << endl;
    }


};

class Cosmetics : public Product, public Discount {
public:
    Cosmetics(const string &imeProizvod, const float cenaProizvod)
            : Product(imeProizvod, cenaProizvod) {}


    float discount_price() {
        // zs Discount::euro koristam a ne direktno euro?
        if (getPrice() / Discount::euro > 5) {
            return getPrice() * 0.82;
        } else if (getPrice() / dollar > 20) { // mozi vaka samo dollar da stoj?
            return getPrice() * 0.86;
        } else return getPrice();
    }

    float price() {
        return getPrice();
    } // kako ova vraka getPrice() e definirano vo Product neli.?

    // zs ne se overridenuvaatt ovie funkcii?
    void print_rule() {
        cout << "Site kozmeticki proizvodi poskapi od 5 evra imaat popust od 12%,"
                "a onie poskapi od 20 dolair imaat popust 14%" << endl;
    }

};

float total_discount(Discount **d, int n) {
    float discount = 0;
    for (int i = 0; i < n; i++) {
        discount += d[i]->discount_price();
        cout << "Prvicna cena: " << d[i]->price() << endl;
        cout << "Cena so popust: " << d[i]->discount_price() << endl;
        d[i]->print_rule();
    }
    return discount;
}


int main() {

    int n = 0;
    float newPrice;
    // sto vsusnost e **d ?
    // dinamicki alocirana niza na pokazuvaci kon Discount
    Discount **d = new Discount *[10];
    d[n++] = new FoodProduct("leb", 30);
    d[n++] = new Cosmetics("krema", 720);
    d[n++] = new Drinks("sok", 50, "Coca-Cola", false);
    d[n++] = new Drinks("viski", 1350, "Jack Daniel's", true);

    cout << "Vkupnata cena na site proizvodi e: " << total_discount(d, n) << endl;

    for (int i = 0; i < n; i++) {
        Cosmetics *c = dynamic_cast<Cosmetics *> (d[i]);    // sto pravi ovaj dynamic_cast?
        //dynamic_cast<Cosmetics*> се обидува безбедно да го конвертира d[i] во Cosmetics*
        if (c != 0) {   // kastot e uspesen
            c->print();
            cin >> newPrice;
            try {
                c->changePrice(newPrice);
                c->print();
            } catch (NegativeValueException i) {
                i.message();
            }
        }
    }


    // zosto e ovaj del?
    //Бидејќи ги креиравме објектите со new,
    //мораме рачно да ги ослободиме со delete за да нема мемориски протекување (memory leak).
    for (int i = 0; i < n; ++i) {
        delete d[i];
    }
    delete[] d;

    return 0;
}
