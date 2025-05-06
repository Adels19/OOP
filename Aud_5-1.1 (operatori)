#include <iostream>
#include <cstring>

using namespace std;

// Aud_5-1.1
// https://bbb-lb.finki.ukim.mk/playback/presentation/2.3/8b86aae906d25c9acd475b0b0fefd7034e7206de-1711624496101

class Fraction {
    int numerator;
    int denominator;
public:
    Fraction(int numerator = 0, int denominator = 1) : numerator(numerator), denominator(denominator) {}

    Fraction operator+(Fraction &other) {  // nema & zatoa sto kreirame kompletno nova dropka, a ne sakame da ja smenime
        return Fraction(this->numerator * other.denominator + other.numerator * this->denominator,
                        this->denominator * other.denominator);
    }

    Fraction operator-(Fraction &other) {       // isto samo namesto + e -
        return Fraction(this->numerator * other.denominator - other.numerator * this->denominator,
                        this->denominator * other.denominator);
    }

    Fraction operator*(Fraction &other) {   // isto samo namesto + e *
        return Fraction(this->numerator * other.denominator * other.numerator * this->denominator,
                        this->denominator * other.denominator);
    }

    friend ostream &operator<<(ostream &out, const Fraction &f) {
        out << f.numerator << "/" << f.denominator << endl;
        return out;
    }

    friend istream &operator>>(istream &in, Fraction &f) { // ne e const oti go polnime
        in >> f.numerator >> f.denominator;
        return in;
    }

    bool operator<(const Fraction &f) const {
        return (this->numerator * f.denominator < f.numerator * this->denominator);
    }

    bool operator>(const Fraction &f) const {
        return f < *this;
    }

    bool operator<=(const Fraction &f) const {
        return !(f < *this);
    }

    bool operator>=(const Fraction &f) const {
        return !(*this < f);
    }

    Fraction &operator+=(Fraction &other) {  // & zatoa sto ja izmenuvame postoeckata
        this->numerator = this->numerator * other.denominator + other.numerator * this->denominator;
        this->denominator = this->denominator * other.denominator;
        return *this;  // jas se smeniv, vrati me
    }


};

int main() {

    Fraction f, f2;
    cin >> f >> f2;
    cout << f << f2;

    cout << "zbir: " << (f + f2);
    cout << "razlika: " << f - f2;

    cout << (f > f2) << endl; // 0 ako ne e tocno, 1 ako e tocno

    cout << (f2 += f);

    return 0;
}
