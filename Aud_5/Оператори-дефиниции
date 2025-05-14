#include <iostream>

using namespace std;

class Broj {
    int value;
public:

    Broj(int value = 0) {
        this->value = value;
    }

    int get() const {
        return value;
    }

    // Преоптоварување на + како член-функција
    Broj operator+(const Broj &other) const {
        return Broj(this->value + other.value);
    }

    void pecati() const {
        cout << "Vrednost: " << value << endl;
    }

    // вообичаено со friend, особено оператори за печатење и внесување
    friend ostream &operator<<(ostream &os, const Broj &broj);

    friend istream &operator>>(istream &in, Broj &b);

};

// Преоптоварување на + како глобална-функција
//Broj operator+(const Broj &a, const Broj &b) {
//    return Broj(a.get() + b.get());
//}

// Преоптоварување на - како глобална-функција
Broj operator-(const Broj &a, const Broj &b) {
    return (a.get() - b.get());
}


//операторите << и >> за ostream и istream речиси секогаш се дефинираат
// како глобални функции,а во класата се декларираат како friend
// ако имаат потреба од пристап до приватни членови на класата.
ostream &operator<<(ostream &out, const Broj &broj) {
    out << broj.value;
    return out;
}
istream &operator>>(istream &in, Broj &broj) {
    in >> broj.value;
    return in;
}



int main() {

    Broj a(5), b(3);
    cin >> a >> b;
    Broj c = a + b;
    c.pecati();
    c = a - b;
    c.pecati();


    return 0;
}
